/*11) Elaborar um programa quando um botão 1 for pressionado, apareça
num display o número 1 e os LEDs ficam ( 1-ON, 2-OFF e 3- Piscando).
Quando um botão 2 for pressionado, apareça num display o número 2 e os
LEDs ficam ( 1-Piscando, 2-ON e 3-ON) e se o botão 3 for pressionado,
apareça num display o número 3 e os LEDs ficam ( 1-OFF, 2-Piscando e 3-
OFF).*/

#define BOTAO1_PIN PB0
#define BOTAO2_PIN PB1
#define BOTAO3_PIN PB2
#define DISPLAY_PIN PORTD
#define LED1_PIN PB3
#define LED2_PIN PB4
#define LED3_PIN PB5
#define DEBOUNCE_DELAY 50 // Atraso para debouncing em ms

void setup() {
  DDRB &= ~((1 << BOTAO1_PIN) | (1 << BOTAO2_PIN) | (1 << BOTAO3_PIN)); // Configurar os pinos dos botões como entrada
  PORTB |= (1 << BOTAO1_PIN) | (1 << BOTAO2_PIN) | (1 << BOTAO3_PIN); // Ativar resistores de pull-up internos
  DDRB |= (1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN); // Configurar os pinos dos LEDs como saída
  DDRD = 0xFF; // Configurar todos os pinos do display como saída
}

void loop() {
  static uint8_t last_estado_botao1 = 0;
  static uint8_t last_estado_botao2 = 0;
  static uint8_t last_estado_botao3 = 0;

  uint8_t estado_botao1 = !(PINB & (1 << BOTAO1_PIN));
  uint8_t estado_botao2 = !(PINB & (1 << BOTAO2_PIN));
  uint8_t estado_botao3 = !(PINB & (1 << BOTAO3_PIN));

  // Limpar o display e os LEDs
  DISPLAY_PIN = 0x00;
  PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN));

  // Verificar se houve uma mudança de estado no botão 1
  if (estado_botao1 != last_estado_botao1) {
    last_estado_botao1 = estado_botao1;
    if (estado_botao1) {
      // Se o botão 1 foi pressionado, mostrar o número 1 no display
      DISPLAY_PIN = 0x06; // Display segmentos para o número 1
      // Acender LED1 e piscar LED3
      PORTB |= (1 << LED1_PIN);
      _delay_ms(500); // Piscar LED3
      PORTB ^= (1 << LED3_PIN);
    }
  }

  // Verificar se houve uma mudança de estado no botão 2
  if (estado_botao2 != last_estado_botao2) {
    last_estado_botao2 = estado_botao2;
    if (estado_botao2) {
      // Se o botão 2 foi pressionado, mostrar o número 2 no display
      DISPLAY_PIN = 0x5B; // Display segmentos para o número 2
      // Acender LED2 e LED3, e piscar LED1
      PORTB |= ((1 << LED2_PIN) | (1 << LED3_PIN));
      _delay_ms(500); // Piscar LED1
      PORTB ^= (1 << LED1_PIN);
    }
  }

  // Verificar se houve uma mudança de estado no botão 3
  if (estado_botao3 != last_estado_botao3) {
    last_estado_botao3 = estado_botao3;
    if (estado_botao3) {
      // Se o botão 3 foi pressionado, mostrar o número 3 no display
      DISPLAY_PIN = 0x4F; // Display segmentos para o número 3
      // Piscar LED2
      _delay_ms(500); // Piscar LED2
      PORTB ^= (1 << LED2_PIN);
    }
  }

  _delay_ms(DEBOUNCE_DELAY); // Atraso para debouncing
}
