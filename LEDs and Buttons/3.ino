/*3) Elaborar um programa quando um botão for pressionado, 3 LEDs devem
ser acionados na sequência (1, 2 e 3) e ficar nesse loop, se for pressionado
novamente o botão, o a sequência será (3, 2, 1).*/


// Define os pinos usados para o botão e os LEDs
#define BOTAO_PIN PORTB0   // Definir o pino do botão
#define LED1_PIN PORTB1    // Definir o pino do LED 1
#define LED2_PIN PORTB2    // Definir o pino do LED 2
#define LED3_PIN PORTB3    // Definir o pino do LED 3

// Enumeração para representar os dois estados possíveis da sequência dos LEDs
enum Estado { SEQUENCIA_123, SEQUENCIA_321 };
Estado estado = SEQUENCIA_123; // Inicialmente, a sequência começa com a ordem 1-2-3

void setup() {
  // Configura o pino do botão como entrada
  DDRB &= ~(1 << BOTAO_PIN);  // Configurar o pino do botão como entrada
  
  // Configura os pinos dos LEDs como saída
  DDRB |= (1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN); // Configurar os pinos dos LEDs como saída
}

void loop() {
  static uint8_t estado_anterior = 0;
  uint8_t estado_atual = PINB & (1 << BOTAO_PIN);

  // Verificar se o botão foi pressionado
  if (estado_atual == 0 && estado_anterior != 0) {  // Se o botão foi pressionado
    // Inverter a sequência
    estado = (estado == SEQUENCIA_123) ? SEQUENCIA_321 : SEQUENCIA_123;
  }

  estado_anterior = estado_atual;

  // Executar a sequência de LEDs com base no estado atual
  switch (estado) {
    case SEQUENCIA_123:
      // Chama a função para executar a sequência 1-2-3
      sequencia123();
      break;
    case SEQUENCIA_321:
      // Chama a função para executar a sequência 3-2-1
      sequencia321();
      break;
  }
}

// Função para executar a sequência 1-2-3
void sequencia123() {
  PORTB |= (1 << LED1_PIN); // Liga o LED 1
  delay(500);               // Espera 500 milissegundos
  PORTB &= ~(1 << LED1_PIN); // Desliga o LED 1
  PORTB |= (1 << LED2_PIN);  // Liga o LED 2
  delay(500);                // Espera 500 milissegundos
  PORTB &= ~(1 << LED2_PIN); // Desliga o LED 2
  PORTB |= (1 << LED3_PIN);  // Liga o LED 3
  delay(500);                // Espera 500 milissegundos
  PORTB &= ~(1 << LED3_PIN); // Desliga o LED 3
}

// Função para executar a sequência 3-2-1
void sequencia321() {
  PORTB |= (1 << LED3_PIN); // Liga o LED 3
  delay(500);               // Espera 500 milissegundos
  PORTB &= ~(1 << LED3_PIN); // Desliga o LED 3
  PORTB |= (1 << LED2_PIN);  // Liga o LED 2
  delay(500);                // Espera 500 milissegundos
  PORTB &= ~(1 << LED2_PIN); // Desliga o LED 2
  PORTB |= (1 << LED1_PIN);  // Liga o LED 1
  delay(500);                // Espera 500 milissegundos
  PORTB &= ~(1 << LED1_PIN); // Desliga o LED 1
}
