#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 26;
const int BTN2_PIN = 7;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(BTN2_PIN);
  gpio_set_dir(BTN2_PIN, GPIO_IN);
  gpio_pull_up(BTN2_PIN);

  while (true) {
    if (!gpio_get(BTN_PIN)) {
      printf("Botao 1\n");
      while (!gpio_get(BTN_PIN)) {
      };
    }

    if (!gpio_get(BTN2_PIN)) {
      printf("Botao 2\n");
      while (!gpio_get(BTN2_PIN)) {
      };
    }

  }
}
