#include <Adafruit_NeoPixel.h> //library for LED

/* Display Output mode */
#define HEXA 0
#define BINA 0
#define TIME 0
#define VALU 1

/* Parameters */
#define TCHANGE 5000 //max time between change of speed for Dynamixel  

/* ID Servo defines Robotis Dynamixel MX-28AR */
#define ELE 1 //Elevator
#define MIN 2 //Miner
#define CAT 3 //Crypto Kitty
#define EWP 4 //Ethereum White Paper

/* Pin defines */
#define SEN 18 //Inductive Proximity Sensorb LJ12A3-4-Z/BX
#define LED 22 //digital pin for neopixel

/* Dynamixel Control table defines */
#define CW_Angle_Limit 6
#define CCW_Angle_Limit 8
#define GOAL_SPEED 32
#define PRESENT_POSITION 36
#define PRESENT_LOAD 40
#define PRESENT_TEMPERATURE 43
#define MOVING 46

 /* Serial device defines for dxl bus */
Dynamixel Dxl(3);

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(32, LED, NEO_GRB + NEO_KHZ800);


unsigned long t_marble =0; //timer between marble
unsigned long val =0; //random value output
unsigned long t_change =0; //random value output
int pos[5];
int load[5];
int temp[5];

/*Setup*/
void setup() {
  //Pin configuration
  pinMode(18, INPUT_PULLDOWN);//sensor pin
  
  for(int i =0;i<10;i++){//config analog pin to add as a source of noise 
    pinMode(i, INPUT_ANALOG);
  }

  // Dynamixel 2.0 Protocol -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(1);
  
  
  //Wheelmode
  Dxl.writeWord(ELE, CW_Angle_Limit, 0);
  Dxl.writeWord(ELE, CCW_Angle_Limit, 0); 
  
  Dxl.writeWord(MIN, CW_Angle_Limit, 0);  
  Dxl.writeWord(MIN, CCW_Angle_Limit, 0);
  
  Dxl.writeWord(CAT, CW_Angle_Limit, 0); 
  Dxl.writeWord(CAT, CCW_Angle_Limit, 0); 
  
  //JointMode
  Dxl.writeWord(ELE, CW_Angle_Limit, 0);
  Dxl.writeWord(ELE, CCW_Angle_Limit, 0); 
 
  
  //Start wheel mode servo
  Dxl.writeWord(ELE, GOAL_SPEED, 300 | 0x400); //reverse
  Dxl.writeWord(MIN, GOAL_SPEED, 100);
  Dxl.writeWord(CAT, GOAL_SPEED, 100);
  
  //Start servo
  Dxl.setPosition(EWP,2048,100);
  
  //Start time
  t_marble=micros(); //save time for restart counter
  t_change=micros(); //save time for restart counter
  
  read_dynamixel();//update value from dynamixels sensors
  
  
  pixels.begin();
  pixels.setBrightness(250);
  pixels.setPixelColor(1,255,255,255);
  pixels.show();
}

/*Loop*/
void loop() {
  
  if(digitalRead(SEN)==LOW){// if there is a marble
  
    digitalWrite(BOARD_LED_PIN, LOW);//LED on board ON
    update_value();//update value with sensors from all dynamixel
    
    
    if (HEXA) SerialUSB.print(val%16,HEX);
    else if (BINA) SerialUSB.print(val%2);
    else if (TIME) SerialUSB.println(micros()-t_marble);
    else if (VALU) SerialUSB.println(val);
    
    t_marble=micros(); //save time for restart counter
    t_change= t_change-TCHANGE*1000;//force update servo
    
    delay (500);//skip rebounce or double marbles
    while (digitalRead(SEN)==LOW) delay(50);//wait for stuck marble or no Power
  }
  else {
    digitalWrite(BOARD_LED_PIN, HIGH);//LED on board OFF
  }
  
  //change speed of servo if marble detected or too long
  if (abs (micros()-t_change) > TCHANGE*1000){
    t_change=micros(); //save time for restart counter
    
    update_value();//update value with sensors from all dynamixel
    
    //change speed of dynamixel
    Dxl.writeWord(ELE, GOAL_SPEED, 200+val%101 | 0x400); //101 arbitrary value
    Dxl.writeWord(MIN, GOAL_SPEED, 100+val%43); //43 arbitrary value
    Dxl.writeWord(CAT, GOAL_SPEED, 100+val%193);//193 arbitrary value
    
    Dxl.setPosition(EWP,1365+val%1021,50+val%101);//101 arbitrary value
  }

}

/*Fonctions*/

int read_dynamixel(void){//read sensors from all dynamixel
  for (int i=0;i<4;i++){
    pos[i+1] =Dxl.readWord(i+1, PRESENT_POSITION);
    load[i+1]=Dxl.readWord(i+1, PRESENT_LOAD);
    temp[i+1]=Dxl.readByte(i+1, PRESENT_TEMPERATURE);
  } 
  
  return 0;
}

int update_value(void){//update value with sensors from all dynamixel
  val = micros()-t_marble; //calculation of the time interval between two marbles
    
    read_dynamixel();//read value from dynamixels sensors    
    for (int i=0;i<4;i++){//adding values from Dynamixel Servos sensors
    val = val + pos[i+1];
    val = val + load[i+1];
    val = val + temp[i+1];
  } 
  
  for(int i =0;i<10;i++){
    val = val + analogRead(i);//add value from floating analog pin
  }
 
  
  return 0;
}

