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
int Ki = 0;
int Kp = 35;
int Kd = 35;
int P = 0, I = 0, D = 0, PID = 0;
int velesq = 0, veldir = 0;
int erro = 0, erro_anterior = 0;
 
/* Função que lê os dados dos sensores e armazena no array*/
void LerSensor(){
 
}
 
/*Função que faz o carrinho seguir em linha reta*/
void Linha_Reta(){
 
}
 
/*Função que faz o carrinho virar levemente a direita*/
void Curva_Leve_Direita(){
 
}
 
/*Função que faz o carrinho virar levemente a esquerda*/
void Curva_Leve_Esquerda(){
 
}
 
/*Função que faz o carrinho virar acentuadamente a direita*/
void Curva_Acentuada_Direita(){
 
}
 
/*Função que faz o carrinho virar acentuadamente a esquerda*/
void Curva_Acentuada_Esquerda(){
 
}
 
/*Função que faz o carrinho virar na curva e fazer uma curva acentuada a direita*/
void Curva_Curva_Acentuada_Direita(){
 
}
 
/*Função que faz o carrinho virar na curva e fazer uma curva acentuada a direita*/
void Curva_Curva_Acentuada_Esquerda(){
 
}
 
/*Função que faz o carrinho virar 90° a direita*/
void Curva90_Direita(){
 
}
 
/*Função que faz o carrinho virar 90° a esquerda*/
void Curva90_Esquerda(){
 
}
 
/*Função que faz o carrinho parar*/
void Parada(){
 
}
 
/*Função que calcula em qual erro o carrinho se encontra*/
void calcula_erro(){
 
}
 
/*Função que calcula o PID */
void Calcula_PID(){
 
}
 
/*FUnção que controla o motor do carrinho.*/
void Controle_Motor(){
 
}
 
/*Função que será lida somente uma unica vez*/
void setup(){
 
}
 
/*Função que será lida até o arduino ser desligado*/
void loop() {
 
}

