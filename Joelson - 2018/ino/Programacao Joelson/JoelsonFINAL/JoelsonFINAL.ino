// Mapeamento de hardware, entradas e sensores//

int iniciar=0; //Variável necessária para início da competição 
#define LED 13 // Led para alerta Infravermelho
#define trigger 9 //Trigger Ultrassonico
#define echo 8 //Echo Ultrassonico
#define in1 4 //Ponte H
#define in2 5 //Ponte H
#define in3 6 //Ponte H
#define in4 7 //Ponte H
#define pir 0 //Infravermelho

// Protótipos das funções------
  void roboFrente();        //-
  void roboTras();          //-
  void roboDireita();       //-
  void roboEsquerda();      //-
//-----------------------------

void setup(){ 
  
  pinMode(LED,OUTPUT); 
 
//-- Ultrassonico -------------
  pinMode(trigger, OUTPUT); //-
  pinMode(echo, INPUT);     //-
  Serial.begin(9600);       //-
//-----------------------------

//-- Motores -------------------
  pinMode(in1,     OUTPUT);  //-
  pinMode(in2,     OUTPUT);  //-
  pinMode(in3,     OUTPUT);  //-
  pinMode(in4,     OUTPUT);  //-
//------------------------------

//-- Infravermelho--------------
  //pinMode(pir,INPUT);      //- a ser testado
  Serial.begin(9600);        //-
//------------------------------



}//Fim void setup

void loop(){  
  
  int valor; // recebe o valor do infravermelho
  long duration, cm; // recebe o valor do ultrassonico
  
  while(iniciar<=0){
    delay(2000); //5000 5s para iniciar
    roboDireita();//Robo precisa andar sentido horário
    delay(500);
    roboFrente();//Ir para frente
    iniciar++;
  }
  



  
  valor=analogRead(pir);//Receber valor Infravermelho  
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  cm = microsecondsToCentimeters(duration);
    
  if(valor > 1000){//intervalo a ser testado, pois não sabemos o valor da cor BRANCA/PRETA
    valor=analogRead(pir);//Receber valor Infravermelho  
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigger, LOW);
    duration = pulseIn(echo, HIGH);
    cm = microsecondsToCentimeters(duration);
    Serial.println("cm: ENTREI IF DO INFRAVERMELHO 1");
    Serial.println(cm);
    Serial.println("infrared ENTREI IF DO INFRAVERMELHO 1");
    Serial.println(valor);
    digitalWrite(LED, HIGH);
    roboTras(); 
    delay(2000); // Não sabemos quanto tempo o robo leva para fazer um giro em seu eixo
    roboEsquerda();
    delay(5000); // Não sabemos quanto tempo o robo leva para fazer um giro em seu eixo
    roboFrente();
    digitalWrite(LED, LOW);
  }
    else  
    roboFrente();
      
    
   do{ //intervalo a ser testado, pois não sabemos a distancia
      Serial.println("cm: ENCONTREI MEU INIMIGO");
      Serial.println(cm);
      Serial.println("infrared ENCONTREI MEU INIMIGO");
      Serial.println(valor);
      roboFrente();
      
      if(valor > 1000){//intervalo a ser testado, pois não sabemos o valor da cor BRANCA/PRETA
          valor=analogRead(pir);//Receber valor Infravermelho  
          digitalWrite(trigger, LOW);
          delayMicroseconds(2);
          digitalWrite(trigger, HIGH);
          delayMicroseconds(5);
          digitalWrite(trigger, LOW);
          duration = pulseIn(echo, HIGH);
          cm = microsecondsToCentimeters(duration);
          Serial.println("cm: ENTREI IF DO INFRAVERMELHO 2");
          Serial.println(cm);
          Serial.println("infrared ENTREI IF DO INFRAVERMELHO 2");
          Serial.println(valor);
          roboTras();
          delay(2000); // Não sabemos quanto tempo o robo leva para fazer um giro em seu eixo
          roboEsquerda();
          delay(5000); // Não sabemos quanto tempo o robo leva para fazer um giro em seu eixo
          roboFrente();
        }
    valor=analogRead(pir);//Receber valor Infravermelho  
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigger, LOW);
    duration = pulseIn(echo, HIGH);
    cm = microsecondsToCentimeters(duration);
    break;
    
    }while(cm < 55);
    
    }//fim void loop

long microsecondsToInches(long microseconds){
    return microseconds / 74 / 2;
}


long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}

void roboTras(){
  digitalWrite(in1, HIGH); //1
  digitalWrite(in2, LOW); //0
  digitalWrite(in3, LOW); //0
  digitalWrite(in4, HIGH); //1
}
void roboFrente(){
  digitalWrite(in1, LOW); //0
  digitalWrite(in2, HIGH); //1
  digitalWrite(in3, HIGH); //1
  digitalWrite(in4, LOW); //0
}

void roboDireita(){
  digitalWrite(in1, LOW); //1
  digitalWrite(in2, HIGH); //0
  digitalWrite(in3, LOW); //1
  digitalWrite(in4, HIGH); //0
}

void roboEsquerda(){
  digitalWrite(in1, HIGH); //0
  digitalWrite(in2, LOW); //1
  digitalWrite(in3, HIGH); //0
  digitalWrite(in4, LOW); //1
}

