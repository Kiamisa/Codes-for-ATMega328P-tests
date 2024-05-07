/*f) Ligue sequencialmente 1 LED da esquerda para a direita (o LED deve
permanecer ligado até que todos os 8 estejam ligados), depois todos eles
devem piscar (ligar e desligar) 5 vezes, depois todos devem apagar.*/

#include <avr/io.h> // Biblioteca para acesso aos registradores de I/O
#include <util/delay.h> // Biblioteca para atrasos

int main(void) {
    DDRD = 0xFF; // Define todos os pinos do PORTD como saída

    while (1) { // Loop infinito
        for (uint8_t i = 0; i < 8; i++) { // Loop para acender cada LED
            PORTD |= 1 << i; // Define apenas o bit correspondente ao LED como 1 (acende o LED)
            _delay_ms(500); // Espera meio segundo
        }

        for (uint8_t j = 0; j < 5; j++) { // Loop para piscar todos os LEDs 5 vezes
            PORTD = 0x00; // Apaga todos os LEDs
            _delay_ms(500); // Espera meio segundo
            PORTD = 0xFF; // Acende todos os LEDs
            _delay_ms(500); // Espera meio segundo
        }

        PORTD = 0x00; // Apaga todos os LEDs
        _delay_ms(500); // Espera meio segundo antes de repetir o processo
    }

    return 0; // Nunca alcançado
}
