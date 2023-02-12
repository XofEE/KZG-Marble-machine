#define ELE 1
#define MIN 2
#define CAT 3
#define EWP 4

#define CAP 18

/* Control table defines */
#define GOAL_SPEED 32
#define MOVING 46
#define CCW_Angle_Limit 8

Dynamixel Dxl(3);

unsigned long t =0;

unsigned long val =0;


void setup() {
    pinMode(18, INPUT_PULLDOWN);

  // Dynamixel 2.0 Protocol -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(1);
  
  
  //Wheelmode
  Dxl.writeWord(ELE, CCW_Angle_Limit, 0); 
  Dxl.writeWord(MIN, CCW_Angle_Limit, 0); 
  Dxl.writeWord(CAT, CCW_Angle_Limit, 0); 
  
  //JointMode
  Dxl.jointMode(EWP); 
  
  t=micros();
  
  Dxl.writeWord(ELE, GOAL_SPEED, random(100,200) | 0x400);
  Dxl.writeWord(MIN, GOAL_SPEED, random(100,200));
  Dxl.writeWord(CAT, GOAL_SPEED, random(100,200));
  

}

void loop() {
  if( digitalRead(CAP)==LOW){// if contact
    digitalWrite(BOARD_LED_PIN, LOW);
    
    val = micros()-t;
    t=micros();
    
    SerialUSB.print(val%16,HEX);
    
    delay (100);
    while (digitalRead(CAP)==LOW) delay(50);
  }
  else {
    digitalWrite(BOARD_LED_PIN, HIGH);
  }
  
  if (random(100)==0){
    if(Dxl.readByte(EWP, MOVING)==0){
      Dxl.setPosition(EWP,random(-1,2)*500+2048,random(50,300)+(val%50));
    }
    
    Dxl.writeWord(ELE, GOAL_SPEED, (random(100,200)+(val%50)) | 0x400);
    Dxl.writeWord(MIN, GOAL_SPEED, random(100,200)+(val%50));
    Dxl.writeWord(CAT, GOAL_SPEED, random(100,200)+(val%50));
  }
  
  delay(5);

}


