#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;
const int LED_PIN_R = 5;
const int LED_PIN_P = 8;
const int LED_PIN_B = 11;
const int LED_PIN_A = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_P);
  gpio_init(LED_PIN_B);
  gpio_init(LED_PIN_A);

  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_P, GPIO_OUT);
  gpio_set_dir(LED_PIN_B, GPIO_OUT);
  gpio_set_dir(LED_PIN_A, GPIO_OUT);

  while (true) {

    if (!gpio_get(BTN_PIN)) {

      // Vermelho
      gpio_put(LED_PIN_R, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_R, 0);

      // Roxo
      gpio_put(LED_PIN_P, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_P, 0);

      // Azul
      gpio_put(LED_PIN_B, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_B, 0);

      // Verde
      gpio_put(LED_PIN_A, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_A, 0);

      while (!gpio_get(BTN_PIN));  // espera soltar
      sleep_ms(20);                // debounce
    }
  }
}