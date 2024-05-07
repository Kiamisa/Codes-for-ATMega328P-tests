/*d) Ligue sequencialmente 1 LED da esquerda para a direita e vice-versa (vai
e volta), só um LED deve ser ligado por vez.*/

#include <avr/io.h> // Biblioteca para acesso aos registradores de I/O
#include <util/delay.h> // Biblioteca para atrasos

int main(void) {
    DDRD = 0xFF; // Define todos os pinos do PORTD como saída

    while (1) { // Loop infinito
      
        for (int8_t i = 7; i >= 0; i--) { // Loop para acender cada LED do MSB para o LSB
            PORTD = 1 << i; // Define apenas o bit correspondente ao LED como 1 (acende o LED)
            _delay_ms(500); // Espera meio segundo
        }
        for (uint8_t i = 0; i < 8; i++) { // Loop para acender cada LED do LSB para o MSB
            PORTD = 1 << i; // Define apenas o bit correspondente ao LED como 1 (acende o LED)
            _delay_ms(500); // Espera meio segundo
        }
    }
    return 0; // Nunca alcançado
}
