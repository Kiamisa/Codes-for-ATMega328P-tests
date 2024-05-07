/*7) Elaborar um programa quando um botão 1 for pressionado, um LED deve
ser acionado(aceso) e outro LED deverá ficar piscando, se apertar o botão 2
inverterá o sentido, se pressionar os dois, apaga os LEDs.*/

// Define os pinos usados para os botões e os LEDs
#define BOTAO1_PIN PORTB0 // Definir o pino do botão 1
#define BOTAO2_PIN PORTB1 // Definir o pino do botão 2
#define LED1_PIN PORTB2   // Definir o pino do LED 1
#define LED2_PIN PORTB3   // Definir o pino do LED 2

void setup() {
  // Configura os pinos dos botões como entrada
  DDRB &= ~((1 << BOTAO1_PIN) | (1 << BOTAO2_PIN)); // Configurar os pinos dos botões como entrada
  
  // Configura os pinos dos LEDs como saída
  DDRB |= (1 << LED1_PIN) | (1 << LED2_PIN); // Configurar os pinos dos LEDs como saída
}

void loop() {
  // Lê o estado dos botões
  uint8_t estado_botao1 = PINB & (1 << BOTAO1_PIN);
  uint8_t estado_botao2 = PINB & (1 << BOTAO2_PIN);

  // Verificar o estado dos botões
  if (estado_botao1 != 0 && estado_botao2 == 0) {
    // Se o botão 1 estiver pressionado e o botão 2 não, ligar o LED 1 e piscar o LED 2
    PORTB |= (1 << LED1_PIN); // Ligar o LED 1
    delay(500);                // Espera 500 milissegundos
    PORTB ^= (1 << LED2_PIN);  // Inverte o estado do LED 2 (pisca)
  } else if (estado_botao1 == 0 && estado_botao2 != 0) {
    // Se o botão 2 estiver pressionado e o botão 1 não, ligar o LED 2 e piscar o LED 1
    PORTB |= (1 << LED2_PIN); // Ligar o LED 2
    delay(500);                // Espera 500 milissegundos
    PORTB ^= (1 << LED1_PIN);  // Inverte o estado do LED 1 (pisca)
  } else if (estado_botao1 != 0 && estado_botao2 != 0) {
    // Se ambos os botões estiverem pressionados, desligar ambos os LEDs
    PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN)); // Desligar ambos os LEDs
  } else {
    // Se nenhum dos botões estiver pressionado, desligar ambos os LEDs
    PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN)); // Desligar ambos os LEDs
  }
}
