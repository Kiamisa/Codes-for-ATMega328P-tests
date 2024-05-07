/*3) Usando 2 displays de 7 segmentos, faça uma contagem crescente de 0 a
F (um display) e uma contagem decrescente de F a 0 (outro display).*/

#include <avr/io.h> // Biblioteca para acesso aos registradores de I/O
#include <util/delay.h> // Biblioteca para atrasos

// Define os padrões para os números de 0 a F em um display de 7 segmentos
uint8_t numeros[16] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111, // 9
    0b01110111, // A
    0b01111100, // B
    0b00111001, // C
    0b01011110, // D
    0b01111001, // E
    0b01110001  // F
};

int main(void) {
    DDRD = 0xFF; // Define todos os pinos do PORTD como saída
    DDRB = (1 << PB0) | (1 << PB1); // Define os pinos PB0 e PB1 do PORTB como saída

    while (1) { // Loop infinito
        for(uint8_t i = 0; i <= 15; i++) { // Loop para contagem crescente de 0 a F
            PORTB &= ~(1 << PB0); // Desativa o display 1
            PORTB |= (1 << PB1); // Ativa o display 2
            PORTD = numeros[i]; // Mostra o número crescente no display 2
            _delay_ms(250); // Espera 250 milissegundos

            PORTB &= ~(1 << PB1); // Desativa o display 2
            PORTB |= (1 << PB0); // Ativa o display 1
            PORTD = numeros[15 - i]; // Mostra o número decrescente no display 1
            _delay_ms(250); // Espera 250 milissegundos
        }
    }
    return 0; // Nunca alcançado
}
