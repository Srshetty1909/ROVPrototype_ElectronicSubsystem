#include <Wire.h>
#include<Servo.h>

Servo grip, drop;
int launch = 7;
int dropval = 180, gripval = 180;
int input[3] = {0, 0, 0};

void setup() {
 
  Wire.begin(3);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(launch, OUTPUT);
  grip.attach(5);
  drop.attach(6);
  grip.write(0);
  drop.write(0);
  digitalWrite(launch, LOW);

}

void loop() {

  if (input[0] == 1) 
  {
    grip.write(gripval);
  }
  else if (input[0] == 0)
  {
    grip.write(0);
  }

  if (input[1] == 1)
  {
    drop.write(dropval);
  }
  else if (input[1] == 0)
  {
    drop.write(0);
  }
  if(input[2] == 1)
  {
    digitalWrite(launch, HIGH);
  }
  else if(input[2] == 0)
  {
    digitalWrite(launch, LOW);
  }
}

void receiveEvent(int howmany){
 for(int i =0; i < howmany; i++)
 {
  input[i] = Wire.read();
 }
 
}
