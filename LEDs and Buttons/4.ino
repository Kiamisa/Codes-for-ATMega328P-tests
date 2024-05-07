/*4) Elaborar um programa para aumentar a frequência em que um LED liga e
desliga, enquanto um botão estiver sendo pressionado, até o
momento em que o LED ficará continuamente ligado. Quando o botão é
solto o LED deve ser desligado.*/

#define BOTAO_PIN PORTB0 // Definir o pino do botão
#define LED_PIN PORTB1   // Definir o pino do LED

void setup() {
  DDRB &= ~(1 << BOTAO_PIN); // Configurar o pino do botão como entrada
  DDRB |= (1 << LED_PIN);    // Configurar o pino do LED como saída
}

void loop() {
  static uint16_t delay_time = 1000; // Iniciar com um delay de 1 segundo
  uint8_t estado_atual = PINB & (1 << BOTAO_PIN);

  // Verificar se o botão está sendo pressionado
  if (estado_atual == 0) {
    // Diminuir o tempo de delay até um mínimo de 1 ms
    if (delay_time > 1) {
      delay_time /= 2;
    }

    // Ligar e desligar o LED com o tempo de delay atual
    PORTB |= (1 << LED_PIN);
    delay(delay_time);
    PORTB &= ~(1 << LED_PIN);
    delay(delay_time);
  } else {
    // Desligar o LED e resetar o tempo de delay
    PORTB &= ~(1 << LED_PIN);
    delay_time = 1000;
  }
}
