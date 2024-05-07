/*b) Ligue sequencialmente 1 LED da esquerda para a direita, mesma lógica
da letra (a).*/

#include <avr/io.h> // Biblioteca para acesso aos registradores de I/O
#include <util/delay.h> // Biblioteca para atrasos

int main(void) {
    DDRD = 0xFF; // Define todos os pinos do PORTD como saída

    while (1) { // Loop infinito
        for (int8_t i = 7; i >= 0; i--) { // Loop para acender cada LED
            PORTD |= 1 << i; // Define o bit correspondente ao LED como 1 (acende o LED)
            _delay_ms(500); // Espera meio segundo
        }

        _delay_ms(500); // Espera meio segundo antes de apagar todos os LEDs

        PORTD = 0x00; // Apaga todos os LEDs de uma vez

        _delay_ms(500); // Espera meio segundo antes de repetir o processo
    }

    return 0; // Nunca alcançado
}
