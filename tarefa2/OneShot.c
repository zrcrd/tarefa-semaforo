/*
    Tarefa 2 - Aula sincrona 29/01 - Unidade 4 - Microcontroladores
    Projeto de um Temporizador por um Disparo (One shot)
    Jose Ricardo
 */
#include <stdio.h>        // Biblioteca padrão
#include "pico/stdlib.h" // Biblioteca padrão do Raspberry Pi Pico para controle de GPIO, temporização e comunicação serial.
#include "pico/time.h"  // Biblioteca para gerenciamento de temporizadores e alarmes.

#define red 12      // Define o pino GPIO 12 para o LED vermelho.
#define blue 11    // Define o pino GPIO 11 para o LED azul.
#define green 13  // Define o pino GPIO 13 para o LED verde.
#define button 5 // Define o pino GPIO 5 para ler o estado do botão.

bool cicle = false;      // Indica se o ciclo de LEDs está ativo.
int estado_atual = 1;   // Controla o estado atual dos LEDs.
int tempo = 3000;      // Atraso de 3 segundos do temporizadorn de alarme

// Inicializa os pinos dos leds
void iniciar_leds() {
    gpio_init(red);
    gpio_set_dir(red, GPIO_OUT);
    gpio_init(blue);
    gpio_set_dir(blue, GPIO_OUT);
    gpio_init(green);
    gpio_set_dir(green, GPIO_OUT);
}

// Função para ligar todos os leds
// Os leds poderão ser acionados com a estrutura state(b,r,g);
void state(bool b, bool r, bool g) {
    gpio_put(blue, b);
    gpio_put(red, r);
    gpio_put(green, g);
}

//Função para inicializar o botão
void iniciar_botao() {
    gpio_init(button);
    gpio_set_dir(button, GPIO_IN);
    gpio_pull_up(button);  // Ativa o resistor pull-up interno
}

void verifica_estado() {
    switch (estado_atual) {
        case 1:
            state(1,1,1);
            break;
        case 2:
            state(0,1,1);
            break;
        case 3:
            state(0,0,1);
            break;
        case 4:
            state(0,0,0);
            break;
}}

// Função de callback para mudar o estado dos LEDs a cada 3 segundos
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    estado_atual++;  // Muda para o próximo estado dos LEDs
    if (estado_atual > 4) {
        cicle = false;  // Permite que o botão funcione novamente quando todos os LEDs estiverem apagados
        return 0; // O alarme não se repete
    }
    verifica_estado();  // Atualiza os LEDs para o próximo estado
    add_alarm_in_ms(tempo, turn_off_callback, NULL, false);  // Reagenda o alarme para 3 segundos
    return 0;
}

int main() {
    // Inicializa os pinos dos LEDs
    iniciar_leds();
    // Inicializa o pino do botão
    iniciar_botao();

    while (true) {
        // Verifica se o botão foi pressionado e os LEDs estão apagados
        if (gpio_get(button) == 0 && !cicle) {
            sleep_ms(50);  // Debounce

            // Verifica novamente o estado do botão após o debounce
            if (gpio_get(button) == 0) {
                cicle = true;  // Marca que o ciclo dos LEDs começou
                estado_atual = 1;   // Inicia o ciclo de LEDs com todos acesos
                verifica_estado();   // Atualiza os LEDs para o primeiro estado
                add_alarm_in_ms(tempo, turn_off_callback, NULL, false);  // Inicia o temporizador de 3 segundos
        }}

        sleep_ms(10);  // Pequeno atraso para reduzir o uso da CPU
    }
    return 0;
}
