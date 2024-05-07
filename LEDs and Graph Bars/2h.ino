/*h) Mostre uma contagem binária crescente (0-255) com passo de 250 ms.*/

#include <avr/io.h> // Biblioteca para acesso aos registradores de I/O
#include <util/delay.h> // Biblioteca para atrasos

int main(void) {
    DDRD = 0xFF; // Define todos os pinos do PORTD como saída

    while (1) { // Loop infinito
        for (uint8_t i = 0; i < 255; i++) { // Loop para a contagem binária de 0 a 255
            PORTD = i; // Define o valor binário nos LEDs conectados ao PORTD
            _delay_ms(250); // Espera 250 milissegundos
        }
    }

    return 0; // Nunca alcançado
}
