// #include <AccelStepper.h>p3
// AccelStepper stepper1(1,4,16);//wire,pulse,dir
// int angle = 0;
// int posn = 0;
// int STEPS = 200;

int dir_la1=13; //la 1
int dir_la2=25; //la 2
int dir_la3=19; //la 3
int pwm_la1=12; //la 1
int pwm_la2=26; //la 2
int pwm_la3=18; //la 3
//wrist 
int pwm_w1=27;
int dir_w1=14;
int pwm_w2=15;
int dir_w2=2;
//gripper
int pwm_g=32;
int dir_g=33;
int freq = 10000;
int res = 8;
int pwm=160;
int pwm_ef=40;
char cmd;

void setup(){
  Serial.begin(9600);
  // //stepper
  // stepper1.setMaxSpeed(2000);
  // stepper1.setAcceleration(1000); 
  //linear actuators 
  pinMode(dir_la1,OUTPUT);
  pinMode(pwm_la1,OUTPUT);
  pinMode(dir_la2,OUTPUT);
  pinMode(pwm_la2,OUTPUT);
  pinMode(dir_la3,OUTPUT);
  pinMode(pwm_la3,OUTPUT);
  //wrist motors
  pinMode(pwm_w1,OUTPUT);
  pinMode(dir_w1,OUTPUT);
  pinMode(pwm_w2,OUTPUT);
  pinMode(dir_w2,OUTPUT);
  //gripper
  pinMode(pwm_g,OUTPUT);
  pinMode(dir_g,OUTPUT);
  //pwm channels
  ledcAttach(pwm_la1,freq,res);
  ledcAttach(pwm_la2,freq,res);
  ledcAttach(pwm_la3,freq,res);
  ledcAttach(pwm_w1,freq,res);
  ledcAttach(pwm_w2,freq,res);
  ledcAttach(pwm_g,freq,res);
}

void loop() {
  if(Serial.available()>0){
    String scmd = Serial.readStringUntil('/n');
    cmd = scmd.charAt(0);
    ledcWrite(pwm_la1,0);
    ledcWrite(pwm_la2,0);
    ledcWrite(pwm_la3,0);
    ledcWrite(pwm_w1,0);
    ledcWrite(pwm_w2,0);
    ledcWrite(pwm_g,0);
    delay(50);
  }
  switch(cmd){
    case('r'):
      Serial.println("r");
      digitalWrite(dir_g,HIGH);
      ledcWrite(pwm_g,pwm);
      break;
      
    case('f'):
      Serial.println("f");
      digitalWrite(dir_g,LOW);
      ledcWrite(pwm_g,pwm);
      break;

    case('t'):
      Serial.println("t");
      digitalWrite(dir_la1,HIGH);
      ledcWrite(pwm_la1,200);
      break;

    case('g'):
      Serial.println("g");
      digitalWrite(dir_la1,LOW);
      ledcWrite(pwm_la1,200);
      break;

    case('y'):
      Serial.println("y");
      digitalWrite(dir_la2,HIGH);
      ledcWrite(pwm_la2,pwm);
      break;

    case('h'):
      Serial.println("h");
      digitalWrite(dir_la2,LOW);
      ledcWrite(pwm_la2,pwm);
      break;

    case('u'):
      Serial.println("u");
      digitalWrite(dir_la3,HIGH);
      ledcWrite(pwm_la3,pwm);
      break;

    case('j'):
      Serial.println("j");
      digitalWrite(dir_la3,LOW);
      ledcWrite(pwm_la3,pwm);
      break;

    case('w'):
      Serial.println("w");
      digitalWrite(dir_w1,HIGH);
      digitalWrite(dir_w2,HIGH);
      ledcWrite(pwm_w1, pwm_ef);
      ledcWrite(pwm_w2, pwm_ef);
      break;

    case('s'): 
      Serial.println("s");
      digitalWrite(dir_w1,LOW);
      digitalWrite(dir_w2,LOW);
      ledcWrite(pwm_w1, pwm_ef);
      ledcWrite(pwm_w2, pwm_ef);
      break;

    case('a'):
      Serial.println('a');
      digitalWrite(dir_w1,LOW);
      digitalWrite(dir_w2,HIGH);
      ledcWrite(pwm_w1, pwm_ef);
      ledcWrite(pwm_w2, pwm_ef);
      break;

    case('d'):
      Serial.println('d');
      digitalWrite(dir_w1, HIGH);
      digitalWrite(dir_w2,LOW);
      ledcWrite(pwm_w1, pwm_ef);
      ledcWrite(pwm_w2, pwm_ef);
      break;

    // case('i'):
    //   Serial.println("i");
    //   stepper1.moveTo(-10);//set posn
    //   stepper1.run();//move to posn
    //   break;

    // case('k'):
    //   Serial.println("k");
    //   stepper1.moveTo(10);//set posn
    //   stepper1.run();//move to posn
    //   break;        

    case('x'):
      Serial.println("x");
      ledcWrite(pwm_la1, 0);
      ledcWrite(pwm_la2, 0);  
      ledcWrite(pwm_la3, 0);
      ledcWrite(pwm_w1, 0); 
      ledcWrite(pwm_w2, 0);  
      ledcWrite(pwm_g,0);
      break;
    }
  
}