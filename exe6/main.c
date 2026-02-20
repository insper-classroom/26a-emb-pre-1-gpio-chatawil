#include <stdio.h>

#include "hardware/gpio.h"
#include "pico/stdlib.h"

enum {
    FIRST_GPIO = 2,
    SEGMENTS = 7,
    MAX_DIGIT = 9,
    BTN_PIN_G = 28
};

/* Converte 0-9 em padrão de bits (a..g) */
static const int bits[10] = {
    0x3f,  // 0
    0x06,  // 1
    0x5b,  // 2
    0x4f,  // 3
    0x66,  // 4
    0x6d,  // 5
    0x7d,  // 6
    0x07,  // 7
    0x7f,  // 8
    0x67   // 9
};

static void seven_seg_init(void) {
    for (int gpio = FIRST_GPIO; gpio < (FIRST_GPIO + SEGMENTS); gpio++) {
        gpio_init((uint)gpio);
        gpio_set_dir((uint)gpio, GPIO_OUT);
        gpio_put((uint)gpio, 0);
    }
}

static void seven_seg_display(int digit) {
    if (digit < 0 || digit > MAX_DIGIT) {
        digit = 0; /* fallback seguro, não deve ocorrer */
    }

    const int value = bits[digit];

    for (int i = 0; i < SEGMENTS; i++) {
        const uint gpio = (uint)(FIRST_GPIO + i);
        const int bit = (value >> i) & 1;
        gpio_put(gpio, bit);
    }
}

int main(void) {
    stdio_init_all();

    gpio_init(BTN_PIN_G);
    gpio_set_dir(BTN_PIN_G, GPIO_IN);
    gpio_pull_up(BTN_PIN_G);

    seven_seg_init();

    int cnt = 0;
    int last_btn = 1; /* pull-up => solto = 1 */
    seven_seg_display(cnt);

    while (true) {
        const int btn = gpio_get(BTN_PIN_G);

        /* borda de descida: 1 -> 0 (apertou) */
        if ((last_btn != 0) && (btn == 0)) {
            cnt++;
            if (cnt > MAX_DIGIT) {
                cnt = 0;
            }
            seven_seg_display(cnt);
            printf("cnt: %d\n", cnt);
        }

        last_btn = btn;
        sleep_ms(10);
    }

    /* unreachable */
    /* return 0; */
}