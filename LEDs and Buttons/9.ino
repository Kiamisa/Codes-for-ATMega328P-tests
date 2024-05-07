/*9) Elaborar um programa quando um botão 1 for pressionado, 3 LEDs devem
ser acionados (1, 2 e 3), se for pressionado o botão 2, a sequência será (3,
2, 1) e se pressionar os dois, apaga os LEDS.*/

// Define os pinos usados para os botões e LEDs
#define BOTAO1_PIN PORTB0
#define BOTAO2_PIN PORTB1
#define LED1_PIN PORTB2
#define LED2_PIN PORTB3
#define LED3_PIN PORTB4

void setup() {
  // Configura os pinos dos botões como entrada
  DDRB &= ~((1 << BOTAO1_PIN) | (1 << BOTAO2_PIN)); // Configurar os pinos dos botões como entrada
  
  // Configura os pinos dos LEDs como saída
  DDRB |= (1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN); // Configurar os pinos dos LEDs como saída

  // Desliga todos os LEDs no início
  PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN));
}

void loop() {
  // Lê o estado dos botões (invertido porque o botão quando pressionado retorna 0)
  uint8_t estado_botao1 = !(PINB & (1 << BOTAO1_PIN));
  uint8_t estado_botao2 = !(PINB & (1 << BOTAO2_PIN));

  // Verifica o estado dos botões e executa as ações correspondentes
  if (estado_botao1 && !estado_botao2) {
    // Se apenas o botão 1 estiver pressionado, acende os LEDs na sequência 1, 2, 3
    PORTB |= (1 << LED1_PIN); // Liga o LED 1
    delay(500);               // Espera 500 milissegundos
    PORTB &= ~(1 << LED1_PIN); // Desliga o LED 1
    PORTB |= (1 << LED2_PIN); // Liga o LED 2
    delay(500);               // Espera 500 milissegundos
    PORTB &= ~(1 << LED2_PIN); // Desliga o LED 2
    PORTB |= (1 << LED3_PIN); // Liga o LED 3
    delay(500);               // Espera 500 milissegundos
    PORTB &= ~(1 << LED3_PIN); // Desliga o LED 3
  } else if (!estado_botao1 && estado_botao2) {
    // Se apenas o botão 2 estiver pressionado, acende os LEDs na sequência 3, 2, 1
    PORTB |= (1 << LED3_PIN); // Liga o LED 3
    delay(500);               // Espera 500 milissegundos
    PORTB &= ~(1 << LED3_PIN); // Desliga o LED 3
    PORTB |= (1 << LED2_PIN); // Liga o LED 2
    delay(500);               // Espera 500 milissegundos
    PORTB &= ~(1 << LED2_PIN); // Desliga o LED 2
    PORTB |= (1 << LED1_PIN); // Liga o LED 1
    delay(500);               // Espera 500 milissegundos
    PORTB &= ~(1 << LED1_PIN); // Desliga o LED 1
  } else if (estado_botao1 && estado_botao2) {
    // Se ambos os botões estiverem pressionados, apaga todos os LEDs
    PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN)); // Desliga todos os LEDs
  } else {
    // Se nenhum dos botões estiver pressionado, não faz nada
  }
}
