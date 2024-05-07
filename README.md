# Codes-for-ATMega328P-tests

Códigos feitos para testes em microprocessador do Arduino Uno - ATMega328P para principalmente controle de LEDs e funções com Botões e displays de 7 segmentos. 
Foi feito utilizando a IDE do Arduino e o software Proteus para teste em simulação, atendendo todos os requisitos para um teste bem sucedido.

LIGANDO LEDs:

1) Desenvolva um programa para piscar um LED rapidamente 3 vezes e 3
vezes lentamente.
2) Desenvolva os seguintes códigos em C, para ligar os 8 LEDs do Bar Graf da
seguinte forma:
a) Ligue sequencialmente 1 LED da direita para a esquerda (o LED deve
permanecer ligado até que todos os 8 estejam ligados, depois eles
devem ser desligados e o processo repetido);
b) Ligue sequencialmente 1 LED da esquerda para a direita, mesma lógica
da letra (a).
c) Ligue sequencialmente 1 LED da direita para a esquerda, desta vez
somente um LED deve ser ligado por vez.
d) Ligue sequencialmente 1 LED da esquerda para a direita e vice-versa (vai
e volta), só um LED deve ser ligado por vez.
e) Ligue todos os LEDs e apague somente 1 LED de cada vez, da direita para
a esquerda e vice-versa (vai e volta), somente um LED deve ser
apagado por vez.
f) Ligue sequencialmente 1 LED da esquerda para a direita (o LED deve
permanecer ligado até que todos os 8 estejam ligados), depois todos eles
devem piscar (ligar e desligar) 5 vezes, depois todos devem apagar.
g) Ligue sequencialmente 1 LED da direita para a esquerda (o LED deve
permanecer ligado até que todos os 8 estejam ligados), depois todos devem
apagar e depois devem ser ligados em sequência contrária (esquerda para
direita) como no início.
h) Mostre uma contagem binária crescente (0-255) com passo de 250 ms.
i) Mostre uma contagem binária decrescente (255-0) com passo de 250 ms.
3) Usando 2 displays de 7 segmentos, faça uma contagem crescente de 0 a
F (um display) e uma contagem decrescente de F a 0 (outro display).

LENDO BOTÃO:

1) Elaborar um programa para ligar imediatamente um LED após o
pressionar de um botão, se pressionar novamente o botão o LED deve
apagar;
2) Elaborar um programa para ligar imediatamente um LED após o
pressionar de um botão, se pressionar novamente o botão o LED deve
piscar, se pressionar o botão novamente o LED deve piscar mais rápido e se
pressionar o botão novamente o LED deve apagar;
3) Elaborar um programa quando um botão for pressionado, 3 LEDs devem
ser acionados na sequência (1, 2 e 3) e ficar nesse loop, se for pressionado
novamente o botão, o a sequência será (3, 2, 1).
4) Elaborar um programa para aumentar a frequência em que um LED liga e
desliga, enquanto um botão estiver sendo pressionado, até o
momento em que o LED ficará continuamente ligado. Quando o botão é
solto o LED deve ser desligado.
5) Elaborar um programa para aumentar a frequência em que um LED liga e
desliga, cada clic no botão deve aumentar a frequência do LED, até ficar
continuamente ligado. Se o botão ficar pressionado por 5s, o LED deve
apagar.
6) Elaborar um programa que controle dois botões e um LED. O LED deverá
ser acionado(aceso) quando qualquer um dos dois botões forem
pressionados e o LED desliga quando os dois forem pressionados.
7) Elaborar um programa quando um botão 1 for pressionado, um LED deve
ser acionado(aceso) e outro LED deverá ficar piscando, se apertar o botão 2
inverterá o sentido, se pressionar os dois, apaga os LEDs.
8) Elaborar um programa quando nenhum botão estiver pressionado, dois
LEDs ficam piscando alternadamente. Ao pressionar um botão 1 os dois
LEDs ficam piscando juntos, se apertar o botão 2 os dois LEDS ficam acessos
e se apertar os botões os dois botões todos os legas apagam.

9) Elaborar um programa quando um botão 1 for pressionado, 3 LEDs devem
ser acionados (1, 2 e 3), se for pressionado o botão 2, a sequência será (3,
2, 1) e se pressionar os dois, apaga os LEDS.
10) Elaborar um programa que faça 4 LEDS( 1, 2, 3, 4)serem acesos da
seguinte forma: Se apertar um botão 1, acende todos os LEDs. Se apertar o
botão 2, acende os LEDs( 1 e 2). Se apertar o botão 3, acende os LEDs( 3 e
4). Se apertar os botões 1 e 3, todos apagam.
11) Elaborar um programa quando um botão 1 for pressionado, apareça
num display o número 1 e os LEDs ficam ( 1-ON, 2-OFF e 3- Piscando).
Quando um botão 2 for pressionado, apareça num display o número 2 e os
LEDs ficam ( 1-Piscando, 2-ON e 3-ON) e se o botão 3 for pressionado,
apareça num display o número 3 e os LEDs ficam ( 1-OFF, 2-Piscando e 3-
OFF).

Códigos feitos para 1ª avaliação da disciplina Microprocessadores e Microcontroladres por 

Silas Henrique de Matos Cerqueira
Engenharia da Computação - 6º Período
Universidade Estadual do Maranhão, 2024
