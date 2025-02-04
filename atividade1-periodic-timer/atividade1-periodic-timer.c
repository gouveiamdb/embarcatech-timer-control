#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos GPIOs dos LEDs
#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

bool repeating_timer_callback(struct repeating_timer *t);
static volatile int cont = 0; 

// Callback do temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (cont) {
        case 0: // Vermelho
            gpio_put(LED_VERMELHO, 1);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERDE, 0);
            printf("Sinal: VERMELHO\n");
            cont = 1;
            break;
        case 1: // Amarelo
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_AMARELO, 1);
            gpio_put(LED_VERDE, 0);
            printf("Sinal: AMARELO\n");
            cont = 2;
            break;
        case 2: // Verde
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERDE, 1);
            printf("Sinal: VERDE\n");
            cont = 0;
            break;
    }
    return true; // Mantém o temporizador rodando
}

int main() {
    // Inicializa a comunicação serial
    stdio_init_all();

    // Inicializa os GPIOs dos LEDs
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Inicializa o temporizador periódico
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Liga o estado inicial chamando o callback diretamente
    repeating_timer_callback(NULL);

    // Loop principal para outras tarefas
    while (true) {
        sleep_ms(100);
        printf("Semáforo operando...\n");
    }

    return 0;
}
