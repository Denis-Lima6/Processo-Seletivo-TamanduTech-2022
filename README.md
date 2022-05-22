<h1> Processo Seletivo TamanduTech 2022 </h1> 
  <h2>1. Organização de dados</h2>
    <p>Um robô seguidor de linha, assim como qualquer outro dispositivo sensorial, precisa
processar diversos dados para tomar “decisões” com padrões pré-estabelecidos. Com isso em
mente, devemos tomar o máximo de cuidado para não processar dados incorretamente, o que
acarretaria em problemas no resultado final.<br>Como você organizaria esses dados, pensando em formas de programação estruturada ou
orientada a objetos?</p>
  <h2>2. Otimização</h2>
    <p>Por se tratar de um robô com eletrônica básica, e processamento reduzido, devemos otimizar o
máximo possível nosso código para evitar desperdícios de processamento. Na linguagem C/C++
utilizamos bastante do recurso de ponteiros, que apontam endereços de memória para outros
métodos/funções, não necessitando assim que o dado seja copiado toda vez que passamos ele
para outro contexto. Abaixo temos a assinatura de um método, ele é a alma do controle do
segue linha, se trata do método de cálculo do PID, como é algo que deve ser processado diversas
vezes por segundo não podemos perder tempo duplicando dados na memória já existentes, por
isso passamos ponteiros (endereços de memória) no argumento do método para que ele possa
tratar os dados:

```
void vTaskCalcularPID(float *input, float *output);
```
Desenvolva o método com os argumentos buscando em paralelo o funcionamento básico do
PID.</p>

<h2> Específicos da categoria:</h2>

<h2>1.Descrever lógica para robô seguir a linha</h2>
  <p>
  - Levando em consideração a leitura dos sensores frontais do robô, ajustar a velocidade dos motores para que a linha seja seguida. Pode-se utilizar técnicas como "bang-bang" ou PID.
  - Se achar necessário pode-se utilizar encoders na lógica ou outro dispositivo que julgar adequado.</p>  

<h2>2. Descrever lógica para parada do robô</h2>
  <p>Em uma competição o robô pode percorrer a pista mais de uma vez. Isso possibilita o mapeamento da pista na primeira tomada de tempo com base nas marcações que são colocadas nela. Dessa forma, é possível identificar curvas, retas e o momento da parada. Com o intuito de utilizar esses dados para otimizar os parâmetros do robô quando ele percorrer a pista das próximas vezes. Com base nisso desenvolva os algoritmos solicitados abaixo:

- Considerar o sensor lateral direito para parada do robô, a parada deve ocorrer após a leitura de duas marcações na direita da pista.
- Fique livre para sugerir outras formas de parada do robô, por exemplo, pela leitura de pulsos dos encoders.</p>

<h2>3. Leitura de um encoder</h2>
  <p>Utilizando um encoder e, considerando que ele está acoplado num sistema motor-roda, descreva detalhadamente o algoritmo para converter os pulsos do encoder na velocidade média do motor (RPM) e distância percorrida (m). Considere que a roda possui um raio $R$

- Nesse desafio não é necessário programar, mas deve-se deixar explícito as fórmulas e a matemática por trás da conversão.
- Levar em conta os sinais elétricos enviados pelo encoder para fazer a contagem de pulsos.</p>

<h2>[Opcional] 4. Descrever algoritmo para leitura de um botão</h2>
  <p>Considerando que você está fazendo a leitura de um sinal enviado por um botão, desenvolva um algoritmo que conte a quantidade de vezes que ele foi pressionado.

- Só considere uma nova contagem se o botão for solto e depois pressionado novamente.
- Explique o que é o efeito bouncing em botões.</p>
