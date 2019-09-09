int trig=13;
int echo=12;
float tempo;
float distancia;

void setup(){
    Serial.begin(9600);
    pinMode(trig, OUTPUT);
    pinMode(echo,INPUT);
    digitalWrite(trig, LOW);
    delayMicroseconds(10);  
}

void loop(){
      digitalWrite(trig,HIGH);
      delayMicroseconds(10);
      digitalWrite(trig,LOW);
      tempo=pulseIn(echo,HIGH);
      distancia=tempo/29.4/2;
      Serial.println(distancia);
}



