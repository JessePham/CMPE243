#include "unity.h"

#include "Mockgpio.h"

#include "switch_led_logic.h"

void setUp(void) {}

void tearDown(void) {}

void test__switch_led_logic__initialize(void) {
  gpio_s gpio = {};
  gpio__construct_as_output_ExpectAndReturn(GPIO__PORT_1, 18U, gpio);
  gpio__construct_as_input_ExpectAndReturn(GPIO__PORT_0, 29U, gpio);
  switch_led_logic__initialize();
}

void test__switch_led_logic__run_once_button_pressed(void) {
  gpio_s test_my_led = {};
  gpio_s test_my_switch = {};
  gpio__get_ExpectAndReturn(test_my_switch, true);
  gpio__set_Expect(test_my_led);
  switch_led_logic__run_once();
}

void test__switch_led_logic__run_once_button_released(void) {
  gpio_s test_my_led = {};
  gpio_s test_my_switch = {};
  gpio__get_ExpectAndReturn(test_my_switch, false);
  gpio__reset_Expect(test_my_led);
  switch_led_logic__run_once();
}