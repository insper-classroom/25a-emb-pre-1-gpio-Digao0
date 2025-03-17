#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;

const int BTNR_PIN = 28;
const int BTNG_PIN = 26;


int main() {
  stdio_init_all();

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  gpio_init(BTNR_PIN);
  gpio_set_dir(BTNR_PIN, GPIO_IN);
  gpio_pull_up(BTNR_PIN);

  gpio_init(BTNG_PIN);
  gpio_set_dir(BTNG_PIN, GPIO_IN);
  gpio_pull_up(BTNG_PIN);

  bool ledR_state = false;
  bool ledG_state = false;

  while (true) {
    if (!gpio_get(BTNR_PIN)) {
      ledR_state = !ledR_state;
      gpio_put(LED_PIN_R, ledR_state);

      while (!gpio_get(BTNR_PIN)) {
      };
    }


    if (!gpio_get(BTNG_PIN)) {
      ledG_state = !ledG_state;
      gpio_put(LED_PIN_G, ledG_state);

      while (!gpio_get(BTNG_PIN)) {
      };
    }


  }


}
