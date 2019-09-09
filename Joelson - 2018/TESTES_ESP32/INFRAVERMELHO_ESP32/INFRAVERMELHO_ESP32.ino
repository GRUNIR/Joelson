#define INFRAVERMELHO 15

void setup() {
  
  Serial.begin(9600);
  
  pinMode(INFRAVERMELHO, INPUT);

}

void loop() {
  
  int C = analogRead(INFRAVERMELHO);
  Serial.println(C);

}

