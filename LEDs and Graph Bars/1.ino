/*1) Desenvolva um programa para piscar um LED rapidamente 3 vezes e 3
vezes lentamente.*/


#define RAPIDO 100 // Definindo o tempo em milissegundos para piscadas rápidas
#define LENTO 1000 // Definindo o tempo em milissegundos para piscadas lentas

void setup() {
  DDRB |= B00100000; // Configura o pino digital 13 (PORTB5) como saída
}

void loop() {
  // Piscadas rápidas
  for(int i = 0; i < 3; i++) { // Repete três vezes
    PORTB |= B00100000; // Liga o LED conectado ao pino digital 13
    delay(RAPIDO); // Aguarda o tempo definido para piscadas rápidas
    PORTB &= B11011111; // Desliga o LED
    delay(RAPIDO); // Aguarda o tempo definido para piscadas rápidas
  }

  delay(1000); // Pausa entre as sequências de piscadas rápidas e lentas

  // Piscadas lentas
  for(int i = 0; i < 3; i++) { // Repete três vezes
    PORTB |= B00100000; // Liga o LED conectado ao pino digital 13
    delay(LENTO); // Aguarda o tempo definido para piscadas lentas
    PORTB &= B11011111; // Desliga o LED
    delay(LENTO); // Aguarda o tempo definido para piscadas lentas
  }

  delay(3000); // Pausa antes de repetir o ciclo
}
