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

  for(int i = 15; i <= 165; i++){
 
    servoName.write(i);
    delay(8);
    Serial.print(i); 
    Serial.print(","); //for readability in processing code
    radarDistance();

  }
  for(int j = 165; j > 15 ; j--){
    
    servoName.write(j);
    delay(8);
    Serial.print(j); 
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


