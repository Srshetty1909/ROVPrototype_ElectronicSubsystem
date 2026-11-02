 #include <Wire.h>
#include <Servo.h>

Servo lt, rt, ut1, ut2;
int m1 = 7, m2 = 8, m3 = 10, m4 = 11; 
int input[4] = {100, 100, 1, 1};
int ltv, rtv, utv1, utv2;
int i = 0;
void setup() {
  // put your setup code here, to run once:
  Wire.begin(2);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  lt.attach(3);
  rt.attach(5);
  ut1.attach(6);
  ut2.attach(9);
  lt.writeMicroseconds(1500);
  rt.writeMicroseconds(1500);
  ut1.writeMicroseconds(1500);
  ut2.writeMicroseconds(1500);
  delay(7000);
}
void loop() {
  // put your main code here, to run repeatedly:
  ltv = map(input[0], 0, 200, 1100, 1900);
  rtv = map(input[1], 0, 200, 1900, 1100);
  switch(input[2])
  {
    case 0: utv1 = 1800;
            utv2 = 1200;
            break;
    case 1: utv1 = 1500;
            utv2 = 1500;
            break;
    case 2: utv1 = 1200;
            utv2 = 1800;
            break;
  }
  switch(input[3])
  {
    case 0: digitalWrite(m1, LOW);
            digitalWrite(m2, LOW);
            digitalWrite(m3, HIGH);
            digitalWrite(m4, LOW);
            break;
    case 1: digitalWrite(m1, LOW);
            digitalWrite(m2, LOW);
            digitalWrite(m3, LOW);
            digitalWrite(m4, LOW);
            break;
    case 2: digitalWrite(m1, HIGH);
            digitalWrite(m2, LOW);
            digitalWrite(m3, LOW);
            digitalWrite(m4, LOW);
            break;         
  }
  lt.writeMicroseconds(ltv);
  rt.writeMicroseconds(rtv);
  ut1.writeMicroseconds(utv1);
  ut2.writeMicroseconds(utv2);
  Serial.print(ltv);
  Serial.print(" ");
  Serial.print(rtv);
  Serial.print(" ");
  Serial.print(utv1);
  Serial.print(" ");
  Serial.print(utv2);
  Serial.print(" ");
  Serial.print(digitalRead(m1));
  Serial.print(" ");
  Serial.println(digitalRead(m3));
  
  
}
void receiveEvent(int howmany){
 for(i =0; i < howmany; i++)
 {
  input[i] = Wire.read();
 }
}
