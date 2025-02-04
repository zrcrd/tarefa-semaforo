#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 11    // Pino correto para o LED vermelho
#define LED_YELLOW 12 // Pino correto para o LED amarelo
#define LED_GREEN 13  // Pino correto para o LED verde

volatile int estado = 0;

void iniciar() {
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
}

void state(bool r, bool y, bool g) {
    gpio_put(LED_RED, r);
    gpio_put(LED_YELLOW, y);
    gpio_put(LED_GREEN, g );
}

// Função que altera o estado do semáforo
void atualizar_semaforo() {
    // Alterna os LEDs do semáforo usando switch-case
    switch (estado) {
        case 0:
            state(1,0,0);   // Vermelho acende
            printf("LED Vermelho ON - PARE\n");
            break;
        case 1:
            state(0,1,0);   
            printf("LED Amarelo ON - ATENÇÃO\n");
            break;
        case 2:
            state(0,0,1);   
            printf("LED Verde ON - PROSSIGA\n");
            break;
    }

    // Atualiza o estado do semáforo
    estado = (estado + 1) % 3;
}

// Callback do temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t) {
    atualizar_semaforo();
    return true;
}

int main() {
    stdio_init_all();
    iniciar();
    
    // Garante que o primeiro LED acenda assim que o programa iniciar
    state(1, 0, 0);
    printf("LED Vermelho ON - PARE\n");
    
    // Configura temporizador para alternar os LEDs a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
    }
}
