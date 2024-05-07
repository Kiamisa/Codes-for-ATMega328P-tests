/*5) Elaborar um programa para aumentar a frequência em que um LED liga e
desliga, cada clic no botão deve aumentar a frequência do LED, até ficar
continuamente ligado. Se o botão ficar pressionado por 5s, o LED deve
apagar.*/

#include <avr/io.h>
#define LED_PIN 2 // Assuming LED is connected to pin 2
#define BUTTON_PIN 3 // Assuming button is connected to pin 3


void delay_ms(unsigned int ms) {
    for (unsigned int i = 0; i < ms; i++) {
        for (unsigned int j = 0; j < 2000; j++) {
            asm volatile ("nop");
        }
    }
}

int main(void) {
    DDRB |= (1 << LED_PIN); // Configura o pino do LED como saída
    DDRD &= ~(1 << BUTTON_PIN); // Configura o pino do botão como entrada
    PORTD |= (1 << BUTTON_PIN); // Ativar resistor de pull-up interno

    int delay = 1000; // Inicia com 1 segundo de delay

    while (1) {
        if (PIND & (1 << BUTTON_PIN)) { // Se o botão estiver pressionado
            delay_ms(5000); // Aguarda 5 segundos
            if (PIND & (1 << BUTTON_PIN)) { // Se o botão ainda estiver pressionado
                PORTB &= ~(1 << LED_PIN); // Desliga o LED
                continue;
            }
            delay /= 2; // Diminui pela metade o delay
            if (delay < 1) delay = 1; // Garante que o delay nunca seja zero
        }
        PORTB ^= (1 << LED_PIN); // Alterna o estado do LED
        delay_ms(delay); // Aguarda o tempo determinado
    }

    return 0;
}
