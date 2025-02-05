#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_BLUE 11
#define LED_RED 12
#define LED_GREEN 13
#define BUTTON 5

bool button_pressed = false;
int state = 0; // Estado atual

// Callback para mudar o estado após 3 segundos
int64_t change_state(alarm_id_t id, void *user_data) {
    state = (state + 1) % 3; // Alterna entre 0, 1 e 2
    
    // Define os LEDs conforme o estado
    switch (state) {
        case 0:
            gpio_put(LED_BLUE, 1);
            gpio_put(LED_RED, 1);
            gpio_put(LED_GREEN, 1);
            break;
        case 1:
            gpio_put(LED_BLUE, 1);
            gpio_put(LED_RED, 1);
            gpio_put(LED_GREEN, 0);
            break;
        case 2:
            gpio_put(LED_BLUE, 0);
            gpio_put(LED_RED, 1);
            gpio_put(LED_GREEN, 1);
            break;
    }
    
    // Agenda a próxima transição se o botão ainda estiver pressionado
    add_alarm_in_ms(3000, change_state, NULL, false);
    return 0;
}

// Callback do botão
void button_callback(uint gpio, uint32_t events) {
    if (!button_pressed) {
        button_pressed = true;
        state = 0; // Reinicia o ciclo
        
        // Liga todos os LEDs
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
        gpio_put(LED_GREEN, 1);
        
        // Inicia a transição de estados
        add_alarm_in_ms(3000, change_state, NULL, false);
    }
}

int main() {
    stdio_init_all();

    // Inicializa LEDs e botão
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(BUTTON);

    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    // Configura interrupção no botão
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    // Loop principal
    while (1) {
        sleep_ms(1000);
    }
}
