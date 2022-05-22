/*Pinos da ponte H*/
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
 
/*Pinos do PWM*/
int PWM_A = 8;
int PWM_B = 9;
 
 
/*pinos nos quais os sensores estão conectados no arduino,
conectei os 7 sensores em pinos impares.
*/
int sensor0 = 33;
int sensor1 = 35;
int sensor2 = 37;
int sensor3 = 39;
int sensor4 = 41;
int sensor5 = 43;
int sensor6 = 45;
 
/* Array que ira armagezar os dados dos sensores. */
int sensor[7];
 
/*Velocidade maxima do motor direito e esquerdo respectivamente*/
int vel_A = 200;
int vel_B = 255;
 
/*Variaveis para calcular o erro,PID e para controlar o motor*/
float Ki = 0;
float Kp = 35;
float Kd = 35;
float P = 0, I = 0, D = 0, PID = 0;
float velesq = 0, veldir = 0;
float erro = 0, erro_anterior = 0;

/*Função que calcula o PID */
void vTaskCalcularPID(float *PKi, float *PKp, float *PKd, float *Pp, float *Pi, float *Pd, float *Ppid, float *Perro, float *Perro_anterior){
      if(*Perro == 0){
        *Pi = 0;
    }
 
    *Pp = *Perro;
    *Pi = *Pi + *Perro;
    if(*Pi > 255){
        *Pi = 255;
    }
 
    else if(*Pi < -255){
        *Pi = -255;
    }
 
    *Pd = *Perro - *Perro_anterior;
    *Ppid = ((*PKp)* (*Pp)) + ((*PKi) * (*Pi)) + ((*PKd) * (*Pd));
    *Perro_anterior = *Perro;
}

/*Função que será lida somente uma unica vez*/
void setup(){
/*Pinos da ponte H, configurados como saida*/
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
 
/*Pinos do PWM, configurados como saida*/
    pinMode(PWM_A, OUTPUT);
    pinMode(PWM_B, OUTPUT);
 
 
/* Sensores configurados como entradas*/
    pinMode(sensor0,INPUT);
    pinMode(sensor1,INPUT);
    pinMode(sensor2,INPUT);
    pinMode(sensor3,INPUT);
    pinMode(sensor4,INPUT);
    pinMode(sensor5,INPUT);
    pinMode(sensor6,INPUT);
 
}

/*Função que será lida até o arduino ser desligado*/
void loop(){
    
    vTaskCalcularPID(&Ki, &Kp, &Kd, &P, &I, &D, &PID, &erro, &erro_anterior);
 
}