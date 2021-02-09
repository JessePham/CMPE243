#include "switch_led_logic.h"

static gpio_s my_led;
static gpio_s my_switch;

void switch_led_logic__initialize() {
  my_led = gpio__construct_as_output(GPIO__PORT_1, 18U);
  my_switch = gpio__construct_as_input(GPIO__PORT_0, 29U);
}

void switch_led_logic__run_once() {
  if (gpio__get(my_switch)) {
    gpio__set(my_led);
  } else {
    gpio__reset(my_led);
  }
}