/*8) Elaborar um programa quando nenhum botão estiver pressionado, dois
LEDs ficam piscando alternadamente. Ao pressionar um botão 1 os dois
LEDs ficam piscando juntos, se apertar o botão 2 os dois LEDS ficam acessos
e se apertar os botões os dois botões todos os legas apagam.*/

#include <avr/io.h>
#include <util/delay.h>

#define LED1_PIN    PB5  // Pino do LED 1 
#define LED2_PIN    PB4  // Pino do LED 2 
#define BUTTON1_PIN PD2  // Pino do botão 1 
#define BUTTON2_PIN PD3  // Pino do botão 2 

#define DEBOUNCE_DELAY 20 // Atraso para debouncing em ms

void setup() {
  DDRB |= (1 << LED1_PIN) | (1 << LED2_PIN); // Configurar os pinos dos LEDs como saída
  DDRD &= ~((1 << BUTTON1_PIN) | (1 << BUTTON2_PIN)); // Configurar os pinos dos botões como entrada
  PORTD |= (1 << BUTTON1_PIN) | (1 << BUTTON2_PIN); // Ativar resistores de pull-up internos
}

uint8_t debounce(uint8_t pin) {
  if (!(PIND & (1 << pin))) {
    _delay_ms(DEBOUNCE_DELAY);
    if (!(PIND & (1 << pin))) {
      return 1; // Botão pressionado
    }
  }
  return 0; // Botão não pressionado
}

void loop() {
  uint8_t button1_pressed = debounce(BUTTON1_PIN);
  uint8_t button2_pressed = debounce(BUTTON2_PIN);

  if (button1_pressed && button2_pressed) {
    // Se ambos os botões estiverem pressionados, apagar os LEDs
    PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN));
  } else if (button1_pressed) {
    // Se o botão 1 estiver pressionado, piscar os LEDs juntos
    PORTB |= (1 << LED1_PIN) | (1 << LED2_PIN);
    _delay_ms(500);
    PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN));
    _delay_ms(500);
  } else if (button2_pressed) {
    // Se o botão 2 estiver pressionado, acender os LEDs
    PORTB |= (1 << LED1_PIN) | (1 << LED2_PIN);
  } else {
    // Se nenhum botão estiver pressionado, piscar os LEDs alternadamente
    PORTB |= (1 << LED1_PIN);
    _delay_ms(500);
    PORTB &= ~(1 << LED1_PIN);
    PORTB |= (1 << LED2_PIN);
    _delay_ms(500);
    PORTB &= ~(1 << LED2_PIN);
  }
}

int main() {
  setup();
  while (1) {
    loop();
  }
  return 0;
}
