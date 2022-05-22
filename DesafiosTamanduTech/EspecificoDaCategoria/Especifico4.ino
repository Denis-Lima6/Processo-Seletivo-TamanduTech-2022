/*Porta em que o botao esta sendo lido*/
#define botao 2
 
/*Variavel contadora*/
int x = 0;
 
void setup(){
    /*Pino configurado como entrada*/
    pinMode(botao,INPUT_PULLUP);
}
 
void loop(){
/*Se o botao for pressionado ele entrará no if e será acrescentado mais 1 a variavel x */
    if (!digitalRead(botao)){
        x++;
    }
 
/*Enquanto o botao estiver pressionado, ele não saira do while, consequentemente não entrará novamente no if enquanto estiver com o botao pressionado*/
    while(!digitalRead(botao)){
 
    }
 
/*Pequeno delay para evitar o efeito bouncing*/
    delay(100);
}
 
/*Efeito Bouncing é em um intervalo de tempo muito pequeno, quando os contatos já estão bem próximos, pode ser que partes da placa se toquem em um ponto e se separem rapidamente,
 podem ocorrer pequenas vibrações ocasionando toques múltiplos entre as placas (efeito bem comum nos botões do tipo “push-up” por causa da mola que existe em seu interior),
 isso tudo antes das placas finalmente se encostarem completamente e fechar o circuito.*/

