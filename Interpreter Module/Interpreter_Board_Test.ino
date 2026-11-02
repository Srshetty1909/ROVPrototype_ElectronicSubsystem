#include <Wire.h>
int acm[3] = {0, 0, 0};
int pcm[4] = {100, 100, 1, 1};
int inputs[7] = {100, 100, 1, 1, 0, 0, 0};
int i = 0, input = 0, count = 0;
int re = 3, de = 2;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(4800);
  pinMode(de, OUTPUT);
  pinMode(re, OUTPUT);
  digitalWrite(re, LOW);
  digitalWrite(de, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()){
    input = Serial.read();
    inputs[count] = input;
    count = count+1;
    if(count == 7){
      count = 0;
    }    
  }
  for(i = 0; i < 4; i++)
  {
    pcm[i] = inputs[i];
  }
  for(i = 0; i < 3; i++)
  {
    acm[i] = inputs[i+4];
  }    
  Wire.beginTransmission(2);
  for(i = 0; i < 4; i++)
  {
    Wire.write(pcm[i]);
    Serial.print(pcm[i]);
    Serial.print(" ");
  }
  Wire.endTransmission();
  Wire.beginTransmission(3);
  for(i = 0; i < 3; i++)
  {
    Wire.write(acm[i]);
    Serial.print(acm[i]);
    Serial.print(" ");
  }
  Wire.endTransmission();
  Serial.println();     
}
