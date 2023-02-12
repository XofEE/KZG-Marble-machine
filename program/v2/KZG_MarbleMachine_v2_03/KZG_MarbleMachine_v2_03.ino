#include <Adafruit_NeoPixel.h> //library for LED

/* Display Output mode */
#define HEXA 0
#define BINA 0
#define TIME 0
#define VALU 1

/* Parameters */
#define TCHANGE 5000 //max time between change of speed for Dynamixel  
#define BRI 50 //LED Brightness
#define TCUT 500 //min time between 2 values to skip rebounce or double marbles
#define TLED 300//time for led animation


/* ID Servo defines Robotis Dynamixel MX-28AR */
#define ELE 1 //Elevator
#define MIN 2 //Miner
#define CAT 3 //Crypto Kitty
#define EWP 4 //Ethereum White Paper

/* Pin defines */
#define SEN 18 //Inductive Proximity Sensorb LJ12A3-4-Z/BX

#define SOU 3 //digital pin for neopixe
#define LUM 1 //digital pin for neopixel
#define ULT 19 //digital pin for neopixel
#define ANT1 8 //digital pin for neopixe
#define ANT2 9 //digital pin for neopixel

#define LEDH 21 //digital pin for neopixe
#define LEDB 20 //digital pin for neopixel

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

Adafruit_NeoPixel pxB = Adafruit_NeoPixel(32, LEDB, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pxH = Adafruit_NeoPixel(32, LEDH, NEO_GRB + NEO_KHZ800);


unsigned long t_marble =0; //timer between marble
unsigned long val =0; //random value output
unsigned long t_change =0; //random value output
unsigned long t_led =0; //random value output
int pos[5];
int load[5];
int temp[5];

byte lineH=0;
byte lineB[200];

float xH=0;

/*Setup*/
void setup() {
  //Pin configuration
  pinMode(SEN, INPUT_PULLDOWN);//sensor pin
  pinMode(ULT, INPUT_PULLDOWN);//ultrason pin
  
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
  
  read_dynamixel();//update value from dynamixels sensors and analogpin
  
  for(int i =0;i<150;i++){//init array with zeros 
    lineB[i]=0;
  }

  //Start led
  pxH.begin();
  pxH.setBrightness(BRI);
  
  pxB.begin();
  pxB.setBrightness(BRI);
  
  update_led();
  
}

/*Loop*/
void loop() {
  
  if((digitalRead(SEN)==LOW) && (abs(micros()-t_marble) > TCUT*1000)){// if there is a new marble more than TCUT ms after the last
  
    digitalWrite(BOARD_LED_PIN, LOW);//LED on board ON
    update_value();//update value with sensors from all dynamixel and analog pin
    ultrasound(); //update value with ultrasound sensor
    
    
    if (HEXA) SerialUSB.print(val%16,HEX);
    else if (BINA) SerialUSB.print(val%2);
    else if (TIME) SerialUSB.println(micros()-t_marble);
    else if (VALU) SerialUSB.println(val);
    
    t_marble=micros(); //save time for restart counter
    t_change= t_change-TCHANGE*1000;//force update servo
    
    sinB();//add pulse lEDB 
    
    while (digitalRead(SEN)==LOW) delay(50);//wait for stuck marble or no Power
  }
  else {
    digitalWrite(BOARD_LED_PIN, HIGH);//LED on board OFF
  }
  
  //change speed of servo if marble detected or too long
  if (abs(micros()-t_change) > TCHANGE*1000){
    t_change=micros(); //save time for restart counter
    
    update_value();//update value with sensors from all dynamixel
    
    //change speed of dynamixel
    Dxl.writeWord(ELE, GOAL_SPEED, 200+val%101 | 0x400); //101 arbitrary value
    Dxl.writeWord(MIN, GOAL_SPEED, 100+val%43); //43 arbitrary value
    Dxl.writeWord(CAT, GOAL_SPEED, 100+val%193);//193 arbitrary value
    
    Dxl.setPosition(EWP,1365+val%1021,50+val%101);//101 arbitrary value
    }
    
    if (micros()%TLED*1000==0){//sinus on LEDH
    xH=xH+0.0031415;
    if (xH>3.1415) xH=0.0;
    
    lineH=20+sin(xH)*50;
    }
    
    
    if(micros()%900==0){//update LED
      move_line();
      update_led();
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
    val = val + analogRead(i);//add value from floating analog pin, antenna, light sensor and mic
  }
  
  return 0;
}

int ultrasound(void){
    // establish variables for duration of the ping, and the distance result
  // in centimeters:
  float duration, mm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(ULT, OUTPUT);
  digitalWrite(ULT, LOW);
  delayMicroseconds(2);
  digitalWrite(ULT, HIGH);
  delayMicroseconds(5);
  digitalWrite(ULT, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(ULT, INPUT);
  duration = rdpulseIn(ULT, HIGH,50);

  // convert the time into a distance in mm
  mm = duration/58.2;
  
  val = val+mm;//
  
  return 0;
}

unsigned long rdpulseIn(int pin, int value, int timeout) { // the following comments assume that we're passing HIGH as value. timeout is in milliseconds

    unsigned long now = micros();
    while(digitalRead(pin) == value) { // wait if pin is already HIGH when the function is called, but timeout if it never goes LOW
        if (micros() - now > (timeout*1000)) {
            return 0;
        }
    }

    now = micros(); // could delete this line if you want only one timeout period from the start until the actual pulse width timing starts
    while (digitalRead(pin) != value) { // pin is LOW, wait for it to go HIGH befor we start timing, but timeout if it never goes HIGH within the timeout period
        if (micros() - now > (timeout*1000)) { 
            return 0;
        }
    }

    now = micros();
    while (digitalRead(pin) == value) { // start timing the HIGH pulse width, but time out if over timeout milliseconds
        if (micros() - now > (timeout*1000)) {
            return 0;
        }
    }
    return micros() - now;
}

int move_line(void){//move array right for B
  for(int i =0;i<149;i++){
    lineB[149-i]=lineB[148-i];
  }
 return 0; 
}

int sinB(void){//add sinus to the start of LEDB array
  float x =0.0;
  for(int i =0;i<20;i++){
    lineB[i]=sin(x)*255;
    x=x+0.157;
  }
 return 0; 
}

int update_led(void){//update LED
  for(int i =0;i<13;i++){
    pxH.setPixelColor(i,lineH,lineH,lineH); 
  }
  pxH.show();
  for(int i =0;i<11;i++){
    pxB.setPixelColor(i,lineB[i*10+59],lineB[i*10+59],lineB[i*10+59]);
  }
  pxB.show();
 return 0; 
}
