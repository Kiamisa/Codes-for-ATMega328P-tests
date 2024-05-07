/*10) Elaborar um programa que faça 4 LEDS( 1, 2, 3, 4)serem acesos da
seguinte forma: Se apertar um botão 1, acende todos os LEDs. Se apertar o
botão 2, acende os LEDs( 1 e 2). Se apertar o botão 3, acende os LEDs( 3 e
4). Se apertar os botões 1 e 3, todos apagam.*/

// Define os pinos usados para os botões e LEDs
#define BOTAO1_PIN PORTB0 // Definir o pino do botão 1
#define BOTAO2_PIN PORTB1 // Definir o pino do botão 2
#define BOTAO3_PIN PORTB2 // Definir o pino do botão 3
#define LED1_PIN PORTB3   // Definir o pino do LED 1
#define LED2_PIN PORTB4   // Definir o pino do LED 2
#define LED3_PIN PORTB5   // Definir o pino do LED 3
#define LED4_PIN PORTD2   // Definir o pino do LED 4

void setup() {
  // Configura os pinos dos botões como entrada
  DDRB &= ~((1 << BOTAO1_PIN) | (1 << BOTAO2_PIN) | (1 << BOTAO3_PIN)); // Configurar os pinos dos botões como entrada
  
  // Configura os pinos dos LEDs como saída
  DDRB |= (1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN); // Configurar os pinos dos LEDs 1, 2 e 3 como saída
  DDRD |= (1 << LED4_PIN); // Configurar o pino do LED 4 como saída
}

void loop() {
  // Lê o estado dos botões (0 significa que o botão está pressionado)
  uint8_t estado_botao1 = PINB & (1 << BOTAO1_PIN);
  uint8_t estado_botao2 = PINB & (1 << BOTAO2_PIN);
  uint8_t estado_botao3 = PINB & (1 << BOTAO3_PIN);

  // Verifica o estado dos botões e executa as ações correspondentes
  if (estado_botao1 == 0) {
    // Se apenas o botão 1 estiver pressionado, acende todos os LEDs
    PORTB |= (1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN);
    PORTD |= (1 << LED4_PIN);
  } else if (estado_botao2 == 0) {
    // Se apenas o botão 2 estiver pressionado, acende os LEDs 1 e 2
    PORTB |= (1 << LED1_PIN) | (1 << LED2_PIN);
    PORTB &= ~(1 << LED3_PIN); // Desliga o LED 3
    PORTD &= ~(1 << LED4_PIN); // Desliga o LED 4
  } else if (estado_botao3 == 0) {
    // Se apenas o botão 3 estiver pressionado, acende os LEDs 3 e 4
    PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN)); // Desliga os LEDs 1 e 2
    PORTB |= (1 << LED3_PIN);
    PORTD |= (1 << LED4_PIN);
  } else if (estado_botao1 == 0 && estado_botao3 == 0) {
    // Se os botões 1 e 3 estiverem pressionados, apaga todos os LEDs
    PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN));
    PORTD &= ~(1 << LED4_PIN);
  } else {
    // Se nenhum dos botões estiver pressionado, apaga todos os LEDs
    PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN));
    PORTD &= ~(1 << LED4_PIN);
  }
}
