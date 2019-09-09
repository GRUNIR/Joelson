int infver=0;
int valor=0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    valor=analogRead(infver);
    delay(500);
    Serial.println(valor);
}
