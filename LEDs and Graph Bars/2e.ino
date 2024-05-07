/*e) Ligue todos os LEDs e apague somente 1 LED de cada vez, da direita para
a esquerda e vice-versa (vai e volta), somente um LED deve ser
apagado por vez.*/

#include <avr/io.h> // Biblioteca para acesso aos registradores de I/O
#include <util/delay.h> // Biblioteca para atrasos

int main(void) {
    DDRD = 0xFF; // Define todos os pinos do PORTD como saída

    while (1) { // Loop infinito
        PORTD = 0xFF; // Acende todos os LEDs
        _delay_ms(500); // Espera meio segundo

        for (int8_t i = 7; i >= 0; i--) { // Loop para apagar cada LED do MSB para o LSB
            PORTD &= ~(1 << i); // Define apenas o bit correspondente ao LED como 0 (apaga o LED)
            _delay_ms(500); // Espera meio segundo
        }

        PORTD = 0xFF; // Acende todos os LEDs
        _delay_ms(500); // Espera meio segundo

        for (uint8_t i = 0; i < 8; i++) { // Loop para apagar cada LED do LSB para o MSB
            PORTD &= ~(1 << i); // Define apenas o bit correspondente ao LED como 0 (apaga o LED)
            _delay_ms(500); // Espera meio segundo
        }
    }

    return 0; // Nunca alcançado
}
