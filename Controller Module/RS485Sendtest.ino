int data[7] = {100, 100, 1, 1, 0, 0, 0};
int re = 3, de = 2;
int input = 0;
int i = 0, count = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(de, OUTPUT);
  pinMode(re, OUTPUT);
  digitalWrite(de, HIGH);
  digitalWrite(re, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()){
    input = Serial.read();
    data[count] = input;
    count = count+1;
    if(count == 7){
      count = 0;
      for(i = 0; i < 7; i++)
      {
        Serial.print(data[i]);
        Serial.print(" ");
      }
      Serial.println();
    }    
  }
  delay(100);
}
