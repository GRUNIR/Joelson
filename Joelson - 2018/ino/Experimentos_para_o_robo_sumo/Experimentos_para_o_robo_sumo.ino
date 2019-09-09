const int led=8;
int infver=0;
int valor=0;

void setup() {
    pinMode(led,OUTPUT);
}

void loop() {
    valor=analogRead(infver);
    if(valor<700){
      digitalWrite(led, HIGH);
    }else{
      digitalWrite(led, LOW);
    }
}
