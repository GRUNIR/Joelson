int vetMotor[4] = {25,26,35,32},i,j,y=0; // Portas 8 7 (Motor Esquerda) / 9 10 (Motor Direita)
int pwm[2] = {33,34}; // VOCE PRECISA LIGAR AS PWM'S PARA INICIAR !!

void roboTras(int vetMotor[4]); // PROTOTIPO DE FUNCAO PARA MOVER O ROBO PARA TRAS
void roboFrente(int vetMotor[4]); // PROTOTIPO DE FUNCAO PARA MOVER O ROBO PARA FRENTE
void roboDireita(int vetMotor[4]); // PROTOTIPO DE FUNCAO PARA MOVER O ROBO PARA DIREITA
void roboEsquerda(int vetMotor[4]); // PROTOTIPO DE FUNCAO PARA MOVER O ROBO PARA ESQUERDA

void setup() {

  Serial.begin(115200);
  
  for(i=0;i<4;i++) // FOR PARA ACIONAMENTO DAS PORTAS DO MOTOR
    pinMode(vetMotor[i], OUTPUT); // LIGA AS PORTAS REFERENTE AOS MOTORES PARA SAIDA DE DADOS


}

void loop() {
  
  roboFrente(vetMotor);
  delay(5000);
  Serial.println("ESTOU COM SONINHO, AGORA VOU PARA TRAS");
  roboTras(vetMotor);
  delay(5000);
  
}
void roboFrente(int vetMotor[4]){ // FUNCAO PARA ACIONAR OS MOTORES PARA SEGUIR EM FRENTE

  digitalWrite(vetMotor[0], LOW); // 0
  digitalWrite(vetMotor[1], HIGH); // 1
  digitalWrite(vetMotor[2], LOW);// 0
  digitalWrite(vetMotor[3], HIGH); // 1

}// FIM 'FUNCAO PARA ACIONAR OS MOTORES PARA SEGUIR EM FRENTE'

void roboTras(int vetMotor[4]){// FUNCAO PARA ACIONAR OS MOTORES PARA IR PARA TRAS

  digitalWrite(vetMotor[0], HIGH); // 1
  digitalWrite(vetMotor[1], LOW); // 0
  digitalWrite(vetMotor[2], HIGH); // 1
  digitalWrite(vetMotor[3], LOW);// 0

}// FIM FUNCAO PARA ACIONAR OS MOTORES PARA IR PARA TRAS

void roboDireita(int vetMotor[4]){// FUNCAO PARA ACIONAR OS MOTORES PARA IR PARA DIREITA

  digitalWrite(vetMotor[0], LOW);// 0
  digitalWrite(vetMotor[1], HIGH);// 1
  digitalWrite(vetMotor[2], HIGH);//0
  digitalWrite(vetMotor[3], LOW);// 0

}// FIM FUNCAO PARA ACIONAR OS MOTORES PARA IR PARA DIREITA

void roboEsquerda(int vetMotor[4]){// FUNCAO PARA ACIONAR OS MOTORES PARA IR PARA ESQUERDA

  digitalWrite(vetMotor[0], HIGH); // 0
  digitalWrite(vetMotor[1], LOW);// 0
    digitalWrite(vetMotor[2], LOW);// 0
    digitalWrite(vetMotor[3], HIGH);// 1

  }// FIM FUNCAO PARA ACIONAR OS MOTORES PARA IR PARA ESQUERDA

