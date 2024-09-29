int dir1 = 26;
int pwm1 = 27;
int dir2 = 14;
int pwm2 = 12;
const int freq = 10000;
const int resolution = 8;
int i=70;
int pwm = 70;
char cmd;

void setup() {
  Serial.begin(9600);
  pinMode(dir1,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pwm2,OUTPUT);
  ledcAttach(pwm1, freq, resolution);
  ledcAttach(pwm2, freq, resolution);
}

void loop() {
  if(Serial.available()>0){
    cmd = Serial.read();
    switch(cmd){
      case('w'):
        Serial.println('w');
        // if(i != 0 ){
        //   for(i;i>0;i--){
        //     ledcWrite(pwm1, i);
        //     ledcWrite(pwm2, i);
        //     delay(10);
        //   }
        // }
        digitalWrite(dir1,HIGH);
        digitalWrite(dir2,HIGH);
        // for(i=0 ; i<=pwm;i++){
          ledcWrite(pwm1, i);
          ledcWrite(pwm2, i);
          // analogWrite(pwm1,i);
          // analogWrite(pwm2,i);
        //}
      break;

      case('s'): 
        Serial.println('s');
        // if(i != 0 ){
        //   for(i;i>0;i--){
        //     ledcWrite(pwm1, i);
        //     ledcWrite(pwm2, i);
        //     // analogWrite(pwm1,i);
        //     // analogWrite(pwm2,i);
        //     delay(10);
        //   }
        // }
        digitalWrite(dir1,LOW);
        digitalWrite(dir2,LOW);
        // for(i;i<=pwm;i++){
          ledcWrite(pwm1, i);
          ledcWrite(pwm2, i);
          // analogWrite(pwm1,i);
          // analogWrite(pwm2,i);
        // }
      break;

      case('a'):
        Serial.println('a');
        // if(i != 0 ){
        //   for(i;i>0;i--){
        //     ledcWrite(pwm1, i);
        //     ledcWrite(pwm2, i);
        //     // analogWrite(pwm1,i);
        //     // analogWrite(pwm2,i);
        //     delay(10);
        //   }
        // }
        digitalWrite(dir1,LOW);
        digitalWrite(dir2,HIGH);
        //for(i ; i<=pwm;i++){
          ledcWrite(pwm1, i);
          ledcWrite(pwm2, i);
          // analogWrite(pwm1,i);
          // analogWrite(pwm2,i);
   
        //}
      break;

      case('d'):
        Serial.println('d');
        // if(i != 0 ){
        //   for(i;i>0;i--){
        //     ledcWrite(pwm1, i);
        //     ledcWrite(pwm2, i);
        //     // analogWrite(pwm1,i);
        //     // analogWrite(pwm2,i);
        //     delay(10);
        //   }
        // }
        digitalWrite(dir1, HIGH);
        digitalWrite(dir2,LOW);
        //for(i ; i<=pwm;i++){
          ledcWrite(pwm1, i);
          ledcWrite(pwm2, i);
          // analogWrite(pwm1,i);
          // analogWrite(pwm2,i);
        //}
      break;

      case 'x':
        //if(i != 0 ){
          //for(i;i>0;i--){
            ledcWrite(pwm1, 0);
            ledcWrite(pwm2, 0);
            // analogWrite(pwm1,i);
            // analogWrite(pwm2,i);
            //delay(10);
          //}
        //}
      break;
    }
  }
}