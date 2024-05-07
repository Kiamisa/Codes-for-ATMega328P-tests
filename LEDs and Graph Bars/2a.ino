/*2) Desenvolva os seguintes códigos em C, para ligar os 8 LEDs do Bar Graf da
seguinte forma:
a) Ligue sequencialmente 1 LED da direita para a esquerda (o LED deve
permanecer ligado até que todos os 8 estejam ligados, depois eles
devem ser desligados e o processo repetido);*/


#include <avr/io.h> // Biblioteca para acesso aos registradores de I/O
#include <util/delay.h> // Biblioteca para atrasos

int main(void) {
    DDRD = 0xFF; // Define todos os pinos do PORTD como saída

    while (1) { // Loop infinito
        for (uint8_t i = 0; i < 8; i++) { // Loop para acender cada LED
            PORTD |= 1 << i; // Define o bit correspondente ao LED como 1 (acende o LED)
            _delay_ms(500); // Espera meio segundo
        }

        _delay_ms(500); // Espera meio segundo antes de apagar todos os LEDs

        PORTD = 0x00; // Apaga todos os LEDs de uma vez

        _delay_ms(500); // Espera meio segundo antes de repetir o processo
    }

    return 0; // Nunca alcançado
}
