/*
  ORIENTADOR: UTHANT VICENTIN LEITE
  PROGRAMADOR: WAN SONG ROCHA
  AUXILIAR: MÁRCUS VINÍCIUS LOBO COSTA
  VERSÃO: 1.3       
  COMPILADOR: ARDUINO 1.8.5 
  SISTEMA EMBARCADO: ESP-32 (Controladora NodeMCU-325)
  OBJETIVO: PROGRAMAÇÃO ELABORADA PARA PROJETO DE EXTENSÃO DE ROBÓTICA DA UNIVERSIDADE FEDERAL DE RONDÔNIA E PARTICIPAÇÃO EM CAMPEONATOS.
  PROGRAMAÇÃO: O ALGORITMO UTILIZA UMA ESTRUTURA DE DADOS, DENOMINADO-SE FILA DE PRIORIDADES. AO DECORRER QUE É REALIZADO INSERCÕES NESSA FILA, OS VALORES SÃO POSICIONADOS DE
  FORMA CRESCENTE. PORTANTO QUANDO EXECUTADO, A ESTRUTURA IRÁ PEGAR A ÚLTIMA POSIÇÃO DA FILA. EM RELAÇÃO AS PRIORIDADES, FOI COLOCADO MAIOR ENFÂSE NOS INFRAVERMELHOS, POIS A
  LEITURA DAS LINHAS É EFETUADO POR ELES E A MAIOR IMPORTÂNCIA É NÃO SAIR DA ÁEREA DESIGNIDA (DOJÔ), QUE FICA DELIMITADA POR LINHAS.

  OBS: O ALGORITMO AINDA NÃO FOI TESTADO NO ROBÔ. AINDA FALTA O QUESITO DE ENERGIZA O MOTOR, PARA USAR O SEU TORQUE MÁXIMO.
*/

#include <stdio.h>
#include <stdlib.h>
#include "FilaPrioridade.h"
#include <SoftwareSerial.h>
//#include "BluetoothSerial.h"
const int ledPin = 13;

int incomingByte;   
SoftwareSerial bluetooth(2,3);
//BluetoothSerial SerialBT; 

void setup(){
  

  Serial.begin(9600);
  bluetooth.begin(9600);
  
  //ACIONANDO OS MOTORES
  for(i = 0 ; i < 4 ; i++)
     pinMode(vetMotor[i], OUTPUT);
  
  //ACIONANDO TODOS OS SENSOR ULTRA E PWM
  for(i=0;i<2;i++){
    
    pinMode(TRIGGER[i], OUTPUT);
    pinMode(ECHO[i], INPUT);
    digitalWrite(TRIGGER[i], LOW);
    delayMicroseconds(10);
    pinMode(PWM[i], OUTPUT);
    analogWrite(PWM[i], 255);
    pinMode(INFRAVERMELHO[i], INPUT);
  
  }
   pinMode(ledPin, OUTPUT);
  /*
  ledcSetup(0,5000,8);
  ledcAttachPin(PWM[0],0);
  ledcWrite(0,255);
   
  ledcSetup(1,5000,8);
  ledcAttachPin(PWM[1],1);
  ledcWrite(1,255);
  */

  //DIRECAO(vetMotor, ESQUERDA);

  //Dir = 1; // ROBO ESTA INDO , A PRIORI, PARA FRENTE
  
}// FIM SETUP

void loop(){

    DIRECAO(vetMotor,TESTES);
//  fp = cria_FilaPrio();
//  
//  PRIORIDADE_CM0 = 0;
//  PRIORIDADE_CM1 = 0;
//  PRIORIDADE_QRE = 0;
//  
//  //LENDO OS SENSORES
//  for(i = 0 ; i < 2 ; i++){
//    QRE[i] = analogRead(INFRAVERMELHO[i]);
//    TEMPO_CM[i] = ULTRASSONICO(i);
//  }
//
//  
//  // SE ENCONTRAR ALGUEM COM O SENSOR DA FRENTE
//  if(TEMPO_CM[0] <= RETORNO_ULTRASSONICO)
//    PRIORIDADE_CM0 = 2;
//
//  // SE ENCONTRAR ALGUEM COM O SENSOR DE TRAS
//  if(TEMPO_CM[1] <= RETORNO_ULTRASSONICO)
//    PRIORIDADE_CM1 = 1;
//    
//  // SE ENCONTRAR A FAIXA COM SENSOR DA FRENTE
//  if((QRE[0] >= FAIXA)||(QRE[1] >= FAIXA))
//    PRIORIDADE_QRE = 3;
//
  Serial.print("INFRA - ");
  Serial.print(QRE[0]);
  Serial.print(" - ");
  Serial.print(QRE[1]);
  Serial.println("");
////  Inserindo na fila de prioridade
//  insere_FilaPrio(fp,PRIORIDADE_CM0);
//  insere_FilaPrio(fp,PRIORIDADE_CM1);
//  insere_FilaPrio(fp,PRIORIDADE_QRE);
// 
//  //Executa a maior prioridade ( prioridade a ser executada )
//  if(executa_FilaPrio(fp)){
//    free(fp);
//  }

}// FIM VOID LOOP

FilaPrio* cria_FilaPrio(){
  
    FilaPrio *fp;
    fp = (FilaPrio*) malloc(sizeof(struct fila_prioridade));
    if(fp != NULL)
        fp->qtd = 0;
    
    return fp;
    
    
}

int insere_FilaPrio(FilaPrio* fp, int prioridade){
    
    int i = fp->qtd-1;
    
    while(i >= 0 && fp->dados[i].prio >= prioridade){
        fp->dados[i+1] = fp->dados[i];
        i--;
    }
    
    fp->dados[i+1].prio = prioridade;
    fp->qtd++;
    
    return 1; 
}

int executa_FilaPrio(FilaPrio* fp){
  
  for(i=0;i<3;i++){
    
    Serial.print(fp->dados[i].prio);
    Serial.print(" ");
  
  }
    Serial.println();
    
    int aux = fp->qtd-1;
    switch(fp->dados[aux].prio){
    
    // ENCONTROU COM SENSOR DE TRAS
    case 1: Dir = 0;
            DIRECAO(vetMotor,TRAS);
            Serial.println("Entrei aqui 1");
            return 1;

    // ENCONTROU COM SENSOR DA FRENTE
    case 2: Dir = 1;
            DIRECAO(vetMotor,FRENTE);
            Serial.println("Entrei aqui 2");
            return 1;

    // ENCONTROU A FAIXA
    case 3:if(Dir == 1){
            Serial.println("Entrei aqui 3 - DIR 1");
            tempoAnterior = millis();
            DIRECAO(vetMotor, DIREITA);
            if(!GIRO())
              return 1;
           }
           
           else{
            Serial.println("Entrei aqui 3 - DIR 0");
            tempoAnterior = millis();
            DIRECAO(vetMotor, DIREITA);
            if(!GIRO())
              return 1;
           }
            return 0;            
            
            default:
            return 1;
            
  }//fim switch
  
  return 0;
}

//FUNCAO PARA MOVIMENTACAO DO ROBO
void DIRECAO(int vetMotor[4], int Movimento[4]){
  
  for(i=0 ; i < 4 ; i++)
    digitalWrite(vetMotor[i], Movimento[i]);

}

//FUNCAO PARA LEITURA DO ULTRASSONICO
int ULTRASSONICO (int K){
 
 digitalWrite(TRIGGER[K], HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIGGER[K], LOW);
 TEMPO = pulseIn(ECHO[K], HIGH);
 
 VALOR_CM = ( unsigned int) TEMPO / 29 / 2;
 
 return VALOR_CM;
 

}

int GIRO(){
  
  free(fp);
  
  if(Dir)
    intervalo = 2500;
  else
    intervalo = 1500;

          
  do{
     
  fp = cria_FilaPrio();
  PRIORIDADE_CM0 = 0;
  PRIORIDADE_CM1 = 0;
 
  //LENDO OS SENSORES
  for(i = 0 ; i < 2 ; i++)
    TEMPO_CM[i] = ULTRASSONICO(i);
  
  // SE ENCONTRAR ALGUEM COM O SENSOR DA FRENTE
  if(TEMPO_CM[0] <= RETORNO_ULTRASSONICO)
    PRIORIDADE_CM0 = 2;

  // SE ENCONTRAR ALGUEM COM O SENSOR DE TRAS
  if(TEMPO_CM[1] <= RETORNO_ULTRASSONICO)
    PRIORIDADE_CM1 = 1;

  //Inserindo na fila de prioridade
  insere_FilaPrio(fp,PRIORIDADE_CM0);
  insere_FilaPrio(fp,PRIORIDADE_CM1);
  insere_FilaPrio(fp,0);

  if((PRIORIDADE_CM1 <= RETORNO_ULTRASSONICO) || (PRIORIDADE_CM0 <= RETORNO_ULTRASSONICO)){
    executa_FilaPrio(fp);
    return 0;
  }
  
  free(fp);
  tempoAtual = millis();
  
  }while(tempoAtual - tempoAnterior <= intervalo);

  Dir = 1;
  DIRECAO(vetMotor, FRENTE);
  Serial.println("NAO ENCONTREI NINGUEM NO GIRO!!");   
  return 1;
}
