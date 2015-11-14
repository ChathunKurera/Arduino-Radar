#include <Servo.h>

int trig = 10;
int echo = 11;
int srv = 12;

Servo servoName;

void setup() {
  pinMode( trig , OUTPUT);
  pinMode( echo, INPUT);
  servoName.attach(srv); //attaching servo controller to pin 12
  
  Serial.begin(9600);
}

void loop() {


  for(int j = 175; j > 5 ; j--){
    
    servoName.write(180-j);
    delay(8);
    Serial.print(j); 
    Serial.print(","); //for readability in processing code
    radarDistance();   
   
  }
  for(int i = 5; i <= 175; i++){
 
    servoName.write(180-i);
    delay(8);
    Serial.print(i); 
    Serial.print(","); //for readability in processing code
    radarDistance();

  }
}

long radarDistance(){
    long duration, distance;
    digitalWrite(echo, LOW);
    digitalWrite(trig, LOW);
    delay(8);
    digitalWrite(trig, HIGH);
    delay(8);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH, 400000);
    //Serial.println(duration);
    distance = (duration*0.034/2);
    Serial.print(distance);
    Serial.print("."); //for readability in processing code
}


