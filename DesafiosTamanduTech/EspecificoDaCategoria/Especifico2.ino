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
 
/*Função que faz o carrinho parar*/
void Parada(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
}
 
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
 
void loop() {
    LerSensor();
    calcula_erro();
    Calcula_PID();
 
    if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 1 && sensor[5] == 0 && sensor[6] == 0){
        Parada();
    }
 
    else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 0 && sensor[5] == 0 && sensor[6] == 0){
        Parada();
    }
 
    else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 0 && sensor[5] == 1 && sensor[6] == 0){
        Parada();
    }
 
    else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 0 && sensor[4] == 0 && sensor[5] == 0 && sensor[6] == 1){
        Parada();
    }
 
}
