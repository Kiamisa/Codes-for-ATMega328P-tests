/*i) Mostre uma contagem binária decrescente (255-0) com passo de 250 ms.*/

#include <avr/io.h> // Biblioteca para acesso aos registradores de I/O
#include <util/delay.h> // Biblioteca para atrasos

int main(void) {
    DDRD = 0xFF; // Define todos os pinos do PORTD como saída

    while (1) { // Loop infinito
        for (int8_t i = 255; i >= 0; i--) { // Loop para a contagem binária decrescente de 255 a 0
            PORTD = i; // Define o valor binário nos LEDs conectados ao PORTD
            _delay_ms(250); // Espera 250 milissegundos
        }
    }

    return 0; // Nunca alcançado
}
