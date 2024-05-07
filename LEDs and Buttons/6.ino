/*6) Elaborar um programa que controle dois botões e um LED. O LED deverá
ser acionado(aceso) quando qualquer um dos dois botões forem
pressionados e o LED desliga quando os dois forem pressionados.*/

// Define os pinos usados para os botões e o LED
#define BOTAO1_PIN PORTB0 // Definir o pino do botão 1
#define BOTAO2_PIN PORTB1 // Definir o pino do botão 2
#define LED_PIN PORTB2    // Definir o pino do LED

void setup() {
  // Configura os pinos dos botões como entrada
  DDRB &= ~((1 << BOTAO1_PIN) | (1 << BOTAO2_PIN)); // Configurar os pinos dos botões como entrada
  
  // Configura o pino do LED como saída
  DDRB |= (1 << LED_PIN); // Configurar o pino do LED como saída
}

void loop() {
  // Lê o estado dos botões
  uint8_t estado_botao1 = PINB & (1 << BOTAO1_PIN);
  uint8_t estado_botao2 = PINB & (1 << BOTAO2_PIN);

  // Verificar o estado dos botões
  if (estado_botao1 != 0 && estado_botao2 != 0) {
    // Se ambos os botões estiverem pressionados, desligar o LED
    PORTB &= ~(1 << LED_PIN);
  } else if (estado_botao1 != 0 || estado_botao2 != 0) {
    // Se qualquer um dos botões estiver pressionado, ligar o LED
    PORTB |= (1 << LED_PIN);
  } else {
    // Se nenhum dos botões estiver pressionado, desligar o LED
    PORTB &= ~(1 << LED_PIN);
  }
}
