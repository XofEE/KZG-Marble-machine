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

void setup() {
    pinMode(18, INPUT_PULLDOWN);

  // Dynamixel 2.0 Protocol -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(1);
  
  
  //Wheelmode
  Dxl.writeWord(ELE, CCW_Angle_Limit, 0); 
  Dxl.writeWord(MIN, CCW_Angle_Limit, 0); 
  Dxl.writeWord(CAT, CCW_Angle_Limit, 0); 
  
  Dxl.jointMode(EWP); //jointMode() is to use position mode

}

void loop() {
  if( digitalRead(CAP)==LOW){// if button is released, means GND(LOW) is connected to BOARD_BUTTON_PIN
    digitalWrite(BOARD_LED_PIN, LOW);
    
    Dxl.writeWord(ELE, GOAL_SPEED, random(100,200) | 0x400);
    Dxl.writeWord(MIN, GOAL_SPEED, random(100,200));
    Dxl.writeWord(CAT, GOAL_SPEED, random(100,200));
  }
  else {
    digitalWrite(BOARD_LED_PIN, HIGH);
  }
  
  if(Dxl.readByte(EWP, MOVING)==0){
    Dxl.setPosition(EWP,(random(0,2)-1)*500+2096,random(50,400));
  }
  

}


