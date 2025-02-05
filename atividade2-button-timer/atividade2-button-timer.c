#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos
#define LED_BLUE 11
#define LED_RED 12
#define LED_GREEN 13
#define BUTTON 5

// Variáveis globais
volatile bool sequence_running = false;

// Protótipos das funções
int64_t state_two_callback(alarm_id_t id, void *user_data);
int64_t state_three_callback(alarm_id_t id, void *user_data);
int64_t turn_off_callback(alarm_id_t id, void *user_data);

// Estado 1: Acende todos os LEDs
int64_t state_one_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_BLUE, 1);
    gpio_put(LED_RED, 1);
    gpio_put(LED_GREEN, 1);
    printf("[LOG] Estado 1: Todos os LEDs acesos.\n");
    add_alarm_in_ms(3000, state_two_callback, NULL, false);
    return 0;
}

// Estado 2: Apaga o LED azul
int64_t state_two_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_BLUE, 0);
    printf("[LOG] Estado 2: LED Azul apagado.\n");
    add_alarm_in_ms(3000, state_three_callback, NULL, false);
    return 0;
}

// Estado 3: Apaga o LED vermelho
int64_t state_three_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_RED, 0);
    printf("[LOG] Estado 3: LED Vermelho apagado.\n");
    add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    return 0;
}

// Estado final: Apaga o LED verde e volta ao estado inicial
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_GREEN, 0);
    sequence_running = false; // Permite reiniciar a sequência
    printf("[LOG] Estado final: Todos os LEDs apagados. Pronto para reiniciar.\n");
    return 0;
}

// Função para iniciar a sequência
void start_sequence() {
    if (!sequence_running) {
        sequence_running = true;
        state_one_callback(NULL, NULL);  // Inicia diretamente no estado 1
    }
}

// Callback para monitorar o botão
bool button_monitor_callback(struct repeating_timer *t) {
    static absolute_time_t last_press_time = 0;
    static bool button_last_state = false;

    bool button_pressed = !gpio_get(BUTTON);  // Botão ativo em nível baixo

    if (button_pressed && !button_last_state &&
        absolute_time_diff_us(last_press_time, get_absolute_time()) > 200000) { // Debounce de 200ms

        last_press_time = get_absolute_time();
        button_last_state = true;

        if (!sequence_running) {
            printf("[LOG] Botão pressionado! Iniciando sequência...\n");
            start_sequence();
        } else {
            printf("[LOG] Botão pressionado, mas sequência ainda está rodando. Aguarde.\n");
        }
    } else if (!button_pressed) {
        button_last_state = false;
    }

    return true;
}

int main() {
    stdio_init_all();
    sleep_ms(1000);
    printf("[LOG] Sistema inicializado. Pressione o botão para começar.\n");

    // Configuração dos LEDs
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Inicializa LEDs apagados
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
    gpio_put(LED_GREEN, 0);

    // Configuração do botão
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);  // Habilita o pull-up interno do botão (remova se houver conflito)

    // Inicializa um temporizador para verificar o botão a cada 100ms
    struct repeating_timer timer;
    add_repeating_timer_ms(100, button_monitor_callback, NULL, &timer);

    while (true) {
        sleep_ms(10);  // Pequeno delay para eficiência
    }
}
