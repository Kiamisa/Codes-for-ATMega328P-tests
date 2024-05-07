/*2) Elaborar um programa para ligar imediatamente um LED após o
pressionar de um botão, se pressionar novamente o botão o LED deve
piscar, se pressionar o botão novamente o LED deve piscar mais rápido e se
pressionar o botão novamente o LED deve apagar;*/

// Define os pinos usados para o botão e o LED
#define BOTAO_PIN PORTB0 // Definir o pino do botão
#define LED_PIN PORTB1 // Definir o pino do LED

// Enumeração para representar os diferentes estados do LED
enum Estado { DESLIGADO, LIGADO, PISCANDO, PISCANDO_RAPIDO };
Estado estado = DESLIGADO; // Inicialmente, o LED está desligado

void setup() {
  // Configura o pino do botão como entrada
  DDRB &= ~(1 << BOTAO_PIN); // Configurar o pino do botão como entrada
  
  // Configura o pino do LED como saída
  DDRB |= (1 << LED_PIN); // Configurar o pino do LED como saída
}

void loop() {
  // Variável para armazenar o estado anterior do botão
  static uint8_t estado_anterior = 0;
  
  // Lê o estado atual do botão
  uint8_t estado_atual = PINB & (1 << BOTAO_PIN);

  // Verifica se o botão foi pressionado
  if (estado_atual != 0 && estado_anterior == 0) {
    // Avança para o próximo estado circularmente
    estado = (Estado)((estado + 1) % 4);
  }

  estado_anterior = estado_atual;

  // Switch case para controlar o comportamento do LED com base no estado atual
  switch (estado) {
    case LIGADO:
      // Liga o LED
      PORTB |= (1 << LED_PIN);
      break;
    case DESLIGADO:
      // Desliga o LED
      PORTB &= ~(1 << LED_PIN);
      break;
    case PISCANDO:
      // Pisca o LED com um atraso de 500 ms
      delay(500);
      PORTB ^= (1 << LED_PIN); // Inverte o estado do LED
      break;
    case PISCANDO_RAPIDO:
      // Pisca o LED rapidamente com um atraso de 100 ms
      delay(100);
      PORTB ^= (1 << LED_PIN); // Inverte o estado do LED
      break;
  }
}
