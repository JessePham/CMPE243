#include "periodic_callbacks.h"
#include "switch_led_logic.h"

#include "FreeRTOS.h"
#include "board_io.h"
#include "task.h"

/******************************************************************************
 * Your board will reset if the periodic function does not return within its deadline
 * For 1Hz, the function must return within 1000ms
 * For 1000Hz, the function must return within 1ms
 */
void periodic_callbacks__initialize(void) { switch_led_logic__initialize(); }

void periodic_callbacks__1Hz(uint32_t callback_count) {
  gpio__toggle(board_io__get_led0());

  switch_led_logic__run_once();

  // On the fifth function call to this function, sleep for 1000ms
  if (callback_count >= 5) {
    vTaskDelay(1000);
  }
}

void periodic_callbacks__10Hz(uint32_t callback_count) {
  gpio__toggle(board_io__get_led1());
  // Add your code here
}
void periodic_callbacks__100Hz(uint32_t callback_count) {
  gpio__toggle(board_io__get_led2());
  // Add your code here
}

/**
 * @warning
 * This is a very fast 1ms task and care must be taken to use this
 * This may be disabled based on intialization of periodic_scheduler__initialize()
 */
void periodic_callbacks__1000Hz(uint32_t callback_count) {
  gpio__toggle(board_io__get_led3());
  // Add your code here
}