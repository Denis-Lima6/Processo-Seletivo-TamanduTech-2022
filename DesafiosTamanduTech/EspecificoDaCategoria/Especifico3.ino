// Arduino LM393
//Pino ligado ao pino do sensor
int pino = 2;
int rpm;
volatile byte pulsos;
long timeold;
 
// encoder de 20 furos
unsigned int pulsos_por_volta = 20;
 
// Funçao que incrementa 1 a cada rotaçao
void contador()
{
  //Incrementa 1 ao contador pulso
  pulsos++;
}
void setup()
{
 
  //Pino do sensor como entrada
  pinMode(pino, INPUT);
  //Interrupcao 0 - pino digital 2
 
 
  //Aciona o contador a cada pulso
  attachInterrupt(0, contador, FALLING);
  pulsos = 0;
  rpm = 0;
  timeold = 0;
}
void loop()
{
  //Atualiza contador a cada segundo
  
if (millis() - timeold >= 1000)
  {
    //Desabilita interrupcao durante o calculo
    detachInterrupt(0);
 
    /*primeiramente, multiplicamos 60 por 1000 e depois dividimos 
    pela quantidade de voltas dadas pelo encoder. 
    Depois dividimos utilizando a função millis(),
    que retorna a quantidade de segundos do processador 
    e subtraimos utilizando a variavel timeold e multiplicamos
     pela qauntidade de pulsos, assim descobrimos
    a quantidade de rotações.*/ 
    rpm = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold) * pulsos;
    timeold = millis();
    pulsos = 0;
    
 
    //Habilita interrupcao
    attachInterrupt(0, contador, FALLING);
  }
}
