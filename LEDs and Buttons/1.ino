/*1) Elaborar um programa para ligar imediatamente um LED após o
pressionar de um botão, se pressionar novamente o botão o LED deve
apagar;*/


// Define os pinos usados para o botão e o LED
#define BOTAO_PIN PORTB0 // Definir o pino do botão
#define LED_PIN PORTB1 // Definir o pino do LED

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
    // Inverte o estado do LED quando o botão é pressionado
    PORTB ^= (1 << LED_PIN);
  }

  // Armazena o estado atual do botão para a próxima iteração
  estado_anterior = estado_atual;
}
