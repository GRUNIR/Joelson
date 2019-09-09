int trig = 13;
int echo = 12;
int trig2 = 26;
int echo2 = 25;

float tempo;
float distancia;
float tempo2;
float distancia2;

void setup(){
  
    Serial.begin(115200);
    
    pinMode(trig, OUTPUT);
    pinMode(echo,INPUT);
    digitalWrite(trig, LOW);
    delayMicroseconds(10);

    pinMode(trig2, OUTPUT);
    pinMode(echo2,INPUT);
    digitalWrite(trig2, LOW);
    delayMicroseconds(10);  
}

void loop(){
  
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    tempo = pulseIn(echo, HIGH);
    
    distancia = tempo/29/2;
    
//------------------------------//
    digitalWrite(trig2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig2, LOW);
    tempo2 = pulseIn(echo2, HIGH);
    
    distancia2 = tempo2/29/2;

    Serial.print(distancia);
    Serial.print("   ULTRASSONICO   ");
    Serial.println(distancia2);

}



