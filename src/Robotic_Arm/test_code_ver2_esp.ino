// #include <AccelStepper.h>
// AccelStepper stepper1(1,4,16);//wire,pulse,dir
int angle = 0;
int posn = 0;
int STEPS = 200;

int dir1=13; //motor 1
int dir2=25; //motor 2
int dir3=19; //motor 3
int pwm1=12; //motor 1
int pwm2=26; //motor 2
int pwm3=18; //motor 3
//wrist 
int p1=27;
int d1=14;
int p2=15;
int d2=2;
//gripper
int p3=32;
int d3=33;
int freq = 10000;
int res = 8;
int pwm=140;
int Icmd;
String cmd;

void setup(){
  Serial.begin(9600);
  // //stepper
  // stepper1.setMaxSpeed(2000);
  // stepper1.setAcceleration(1000); 
  //linear actuators 
  pinMode(dir1,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(pwm3,OUTPUT);
  //wrist motors
  pinMode(p1,OUTPUT);
  pinMode(d1,OUTPUT);
  pinMode(p2,OUTPUT);
  pinMode(d2,OUTPUT);
  //gripper
  pinMode(p3,OUTPUT);
  pinMode(d3,OUTPUT);
  //pwm channels
  ledcAttach(pwm1,freq,res);
  ledcAttach(pwm2,freq,res);
  ledcAttach(pwm3,freq,res);
  ledcAttach(p1,freq,res);
  ledcAttach(p2,freq,res);
  ledcAttach(p3,freq,res);
}

void loop() {
  if(Serial.available()>0){
    cmd = Serial.readStringUntil('\n');

    ledcWrite(pwm1,0);
    ledcWrite(pwm2,0);
    ledcWrite(pwm3,0);
    ledcWrite(p1,0);
    ledcWrite(p2,0);
    ledcWrite(p3,0);
    delay(50);

    if(cmd == "r") Icmd = 1;
    else if(cmd == "f") Icmd = 2;
    else if(cmd == "t") Icmd = 3;
    else if(cmd == "g") Icmd = 4;
    else if(cmd == "y") Icmd = 5;
    else if(cmd == "h") Icmd = 6;
    else if(cmd == "u") Icmd = 7;
    else if(cmd == "j") Icmd = 8;
    else if(cmd == "w") Icmd = 9;
    else if(cmd == "a") Icmd = 10;
    else if(cmd == "s") Icmd = 11;
    else if(cmd == "d") Icmd = 12;
    else if(cmd == "i") Icmd = 13;
    else if(cmd == "k") Icmd = 14;
    else Icmd=0;
    }

    switch(Icmd){
      case(1):
        Serial.println("r");
        digitalWrite(d3,HIGH);
        ledcWrite(p3,pwm);
        break;
        
      case(2):
        Serial.println("f");
        digitalWrite(d3,LOW);
        ledcWrite(p3,pwm);
        break;

      case(3):
        Serial.println("t");
        digitalWrite(dir1,HIGH);
        ledcWrite(pwm1,200);
        break;

      case(4):
        Serial.println("g");
        digitalWrite(dir1,LOW);
        ledcWrite(pwm1,200);
        break;

      case(5):
        Serial.println("y");
        digitalWrite(dir2,HIGH);
        ledcWrite(pwm2,pwm);
        break;

      case(6):
        Serial.println("h");
        digitalWrite(dir2,LOW);
        ledcWrite(pwm2,pwm);
        break;

      case(7):
        Serial.println("u");
        digitalWrite(dir3,HIGH);
        ledcWrite(pwm3,pwm);
        break;

      case(8):
        Serial.println("j");
        digitalWrite(dir3,LOW);
        ledcWrite(pwm3,pwm);
        break;

      case(9):
        Serial.println('w');
        digitalWrite(d1,HIGH);
        digitalWrite(d2,HIGH);
        ledcWrite(p1, 80);
        ledcWrite(p2, 80);
        break;

      case(11): 
        Serial.println('s');
        digitalWrite(d1,LOW);
        digitalWrite(d2,LOW);
        ledcWrite(p1, 80);
        ledcWrite(p2, 80);
        break;

      case(10):
        Serial.println('a');
        digitalWrite(d1,LOW);
        digitalWrite(d2,HIGH);
        ledcWrite(p1, 80);
        ledcWrite(p2, 80);
        break;

      case(12):
        Serial.println('d');
        digitalWrite(d1, HIGH);
        digitalWrite(d2,LOW);
        ledcWrite(p1, 80);
        ledcWrite(p2, 80);
        break;

      // case(13):
      //   Serial.println("i");
      //   stepper1.moveTo(-10);//set posn
      //   stepper1.run();//move to posn
      //   break;

      // case(14):
      //   Serial.println("k");
      //   stepper1.moveTo(10);//set posn
      //   stepper1.run();//move to posn
      //   break;        

      case(0):
        Serial.println("x");
        ledcWrite(pwm1, 0);
        ledcWrite(pwm2, 0);  
        ledcWrite(pwm3, 0);
        ledcWrite(p1, 0); 
        ledcWrite(p2, 0);  
        ledcWrite(p3,0);
        break;
  }
}
