//Arquivo FilaPrioridade.h
#define MAX 3
#define FAIXA 800 //SENSOR QRE
#define RETORNO_ULTRASSONICO 10 //SENSOR ULTRASSONICO - METADE DO DIAMETRO DA PISTA -

struct DEFINICAO_PRIORIDADE{
    int prio;
};

typedef struct fila_prioridade{
    int qtd;
    struct DEFINICAO_PRIORIDADE dados[MAX];
}FilaPrio; 

FilaPrio *fp;

/* ASSINATURA DE FUNÇÕES */
FilaPrio* cria_FilaPrio();
int insere_FilaPrio(FilaPrio* fp, int prioridade);
int executa_FilaPrio(FilaPrio* fp);
void DIRECAO(int vetMotor[4], int Movimento[4]);
int ULTRASSONICO (int K);
/* -------------------------*/

/*DECLARANDO TODAS AS PORTAS/PINAGEM DO ROBO 8 7 9 10*/
int vetMotor[4] = {8,7,9,10};
unsigned int PWM[2] = {6,11};
unsigned int INFRAVERMELHO[2] = {0,1};
unsigned int ECHO[2] = {3,12};
unsigned int TRIGGER[2] = {4,13}; //4,13
unsigned int QRE[2] = {0,0};
unsigned int i;
/* ------------------------------------------*/

/* DECLARANDO AS VARIAVEIS DE TEMPO*/
unsigned long tempoAtual,tempoAtualB;
unsigned long tempoAnterior = 0, tempoAnteriorB = 0; //MILLIS
long intervalo = 0 , intervaloB = 100; //MILLIS
/* ------------------------------------------*/

unsigned int TEMPO, TEMPO_CM[2], VALOR_CM;
int PRIORIDADE_CM0,PRIORIDADE_CM1,PRIORIDADE_QRE,PRIORIDADE_QRE1,Dir;

int PARADO[4] = {0,0,0,0},
    DIREITA[4] = {0,1,0,1},
    FRENTE[4] = {1,0,0,1},
    ESQUERDA[4] = {1,0,1,0},
    TRAS[4] = {0,1,1,0},
    TESTES[4] = {1,0,0,0};
