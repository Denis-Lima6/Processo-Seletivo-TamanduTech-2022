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
    sensor[0] = digitalRead (sensor0);
    sensor[1] = digitalRead (sensor1);
    sensor[2] = digitalRead (sensor2);
    sensor[3] = digitalRead (sensor3);
    sensor[4] = digitalRead (sensor4);
    sensor[5] = digitalRead (sensor5);
    sensor[6] = digitalRead (sensor6);
}
 
/*Função que faz o carrinho seguir em linha reta*/
void Linha_Reta(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWM_A, vel_A*(0.85));
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(PWM_B, vel_B*(0.85))
}
 
/*Função que faz o carrinho virar levemente a direita*/
void Curva_Leve_Direita(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWM_A, vel_A*(0.5));
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(PWM_B, vel_B*(0.8))
}
 
/*Função que faz o carrinho virar levemente a esquerda*/
void Curva_Leve_Esquerda(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWM_A, vel_A*(0.5));
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(PWM_B, vel_B*(0.5))
}
 
/*Função que faz o carrinho virar acentuadamente a direita*/
void Curva_Acentuada_Direita(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWM_A, vel_A*(0.2));
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(PWM_B, vel_B*(0.8))
}
 
/*Função que faz o carrinho virar acentuadamente a esquerda*/
void Curva_Acentuada_Esquerda(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWM_A, vel_A*(0.8));
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(PWM_B, vel_B*(0.2))
}
 
/*Função que faz o carrinho virar na curva e fazer uma curva acentuada a direita*/
void Curva_Curva_Acentuada_Direita(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWM_A, vel_A*(0.1));
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(PWM_B, vel_B*(0.8))  
}
 
/*Função que faz o carrinho virar na curva e fazer uma curva acentuada a direita*/
void Curva_Curva_Acentuada_Esquerda(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWM_A, vel_A*(0.8));
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(PWM_B, vel_B*(0.1))  
}
 
/*Função que faz o carrinho virar 90° a direita*/
void Curva90_Direita(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(PWM_A, 0.1*vel_A);
    analogWrite(PWM_B, 0.80*vel_B);
    delay(850);
}
 
/*Função que faz o carrinho virar 90° a esquerda*/
void Curva90_Esquerda(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(PWM_A, 0.90*vel_A);
    analogWrite(PWM_B, 0.05*vel_B);
    delay(850);
}
 
/*Função que faz o carrinho parar*/
void Parada(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
}
 
/*Função que calcula em qual erro o carrinho se encontra*/
void calcula_erro(){
    if((sensor[0]==1) && (sensor[1]==1) && (sensor[2]==1) && (sensor[3]==0) && (sensor[4]==1) && (sensor[5]==1) && (sensor[6]==1)){
        erro = 0;
    }
 
    else if((sensor[0]==1) && (sensor[1]==1) && (sensor[2]==1) && (sensor[3]==0) && (sensor[4]==0) && (sensor[5]==1) && (sensor[6]==1)){
        erro = 1;
    }
 
    else if((sensor[0]==1) && (sensor[1]==1) && (sensor[2]==0) && (sensor[3]==0) && (sensor[4]==1) && (sensor[5]==1) && (sensor[6]==1)){
        erro = -1;
    }
 
    else if((sensor[0]==1) && (sensor[1]==1) && (sensor[2]==1) && (sensor[3]==1) && (sensor[4]==0) && (sensor[5]==1) && (sensor[6]==1)){
        erro = 1.5;
    }
 
    else if((sensor[0]==1) && (sensor[1]==1) && (sensor[2]==0) && (sensor[3]==1) && (sensor[4]==1) && (sensor[5]==1) && (sensor[6]==1)){
        erro = -1.5;
    }
 
    else if((sensor[0]==1) && (sensor[1]==1) && (sensor[2]==1) && (sensor[3]==1) && (sensor[4]==0) && (sensor[5]==0) && (sensor[6]==1)){
        erro = 1.75;
    }
 
    else if((sensor[0]==1) && (sensor[1]==0) && (sensor[2]==0) && (sensor[3]==1) && (sensor[4]==1) && (sensor[5]==1) && (sensor[6]==1)){
        erro = -1.75;
    }
 
    else if((sensor[0]==1) && (sensor[1]==1) && (sensor[2]==1) && (sensor[3]==1) && (sensor[4]==1) && (sensor[5]==0) && (sensor[6]==1)){
        erro = 2;
    }
 
    else if((sensor[0]==1) && (sensor[1]==0) && (sensor[2]==1) && (sensor[3]==1) && (sensor[4]==1) && (sensor[5]==1) && (sensor[6]==1)){
        erro = -2;
    }
 
}
 
/*Função que calcula o PID */
void Calcula_PID(){
    if(erro == 0){
        I = 0;
    }
 
    P = erro;
    I = I + erro;
    if(I > 255){
        I = 255;
    }
 
    else if(I < -255){
        I = -255;
    }
 
    D = erro - erro_anterior;
    PID = (Kp*P) + (Ki*I) + (Kd*D);
    erro_anterior = erro;
}
 
/*FUnção que controla o motor do carrinho.*/
void Controle_Motor(){
    if(PID >= 0){
        velesq = vel_B;
        veldir = vel_A - PID;
    }
    else{
        velesq = vel_B + PID;
        veldir = vel_A
    }
 
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(PWN_A, veldir);
    analogWrite(PWN_B, velesq);
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
void loop() {
    LerSensor();
    calcula_erro();
    Calcula_PID();
 
    if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 0 && sensor[4 ] == 1 && sensor[5] == 1 && sensor[6] == 1){
        Linha_Reta();
    }
 
    else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 0 && sensor[4] == 0 && sensor[5] == 1 && sensor[6] == 1){
        Curva_Leve_Direita();
    }
 
    else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 0 && sensor[3] == 0 && sensor[4] == 1 && sensor[5] == 1 && sensor[6] == 1){
        Curva_Leve_Esquerda();
    }
 
    else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 0 && sensor[5] == 1 && sensor[6] == 1){
        Curva_Acentuada_Direita();
    }
 
    else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 0 && sensor[3] == 1 && sensor[4] == 1 && sensor[5] == 1 && sensor[6] == 1){
        Curva_Acentuada_Esquerda();
    }
 
    else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 1 && sensor[5] == 0 && sensor[6] == 1){
        Curva_Curva_Acentuada_Direita()
    }
 
    else if(sensor[0] == 1 && sensor[1] == 0 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 1 && sensor[5] == 1 && sensor[6] == 1){
        Curva_Curva_Acentuada_Esquerda()
    }
 
    else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 0 && sensor[4] == 1 && sensor[5] == 1 && sensor[6] == 0){
        Curva90_Direita();
    }
 
    else if(sensor[0] == 0 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 0 && sensor[4] == 1 && sensor[5] == 1 && sensor[6] == 1){
        Curva90_Esquerda();
    }
 
    else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 1 && sensor[5] == 1 && sensor[6] == 1){
        Parada();
    }
 
 
}
