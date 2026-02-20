#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 4;
const int LED_PIN_V = 6;
const int BTN_PIN_R = 28;
const int BTN_PIN_V = 26;

int main() {
  stdio_init_all();

  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_V);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_V, GPIO_OUT);
  gpio_init(BTN_PIN_R);
  gpio_init(BTN_PIN_V);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_set_dir(BTN_PIN_V, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);
  gpio_pull_up(BTN_PIN_V);

  int led_state_r = 0;
  int led_state_v = 0;

  while (true) {
    if (!gpio_get(BTN_PIN_R)) {
      if (led_state_r == 0) {
        gpio_put(LED_PIN_R, 1);
        led_state_r = 1; 
      } 
      else {
        gpio_put(LED_PIN_R, 0);
        led_state_r = 0;
      }
      while (!gpio_get(BTN_PIN_R)) {
      };
      sleep_ms(20);
    }

    if (!gpio_get(BTN_PIN_V)) {
      if (led_state_v == 0) {
        gpio_put(LED_PIN_V, 1);
        led_state_v = 1;
      } else {
        gpio_put(LED_PIN_V, 0);
        led_state_v = 0;
      }
      while (!gpio_get(BTN_PIN_V)) {
      };
      sleep_ms(20);
    }
  }
}
