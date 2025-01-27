/**************************************************************************************************
// Includes
**************************************************************************************************/
#include <stdint.h>
#include <Arduino.h>
// #include <driver/temp_sensor.h>

#include <micro_ros_platformio.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/float32.h>

// Wrapped atomic functions
uint64_t __wrap___atomic_load_8(const volatile void *ptr) {
    return __atomic_load_n((const volatile uint64_t*)ptr, __ATOMIC_SEQ_CST);
}

uint64_t __wrap___atomic_exchange_8(volatile void *ptr, uint64_t val) {
    return __atomic_exchange_n((volatile uint64_t*)ptr, val, __ATOMIC_SEQ_CST);
}

uint64_t __wrap___atomic_fetch_add_8(volatile void *ptr, uint64_t val) {
    return __atomic_fetch_add((volatile uint64_t*)ptr, val, __ATOMIC_SEQ_CST);
}

void __wrap___atomic_store_8(volatile void *ptr, uint64_t val) {
    __atomic_store_n((volatile uint64_t*)ptr, val, __ATOMIC_SEQ_CST);
}

rcl_publisher_t temperaturePublisher;
std_msgs__msg__Float32 temperatureMessage;

rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer;

/**************************************************************************************************
// Private constants
**************************************************************************************************/
static const uint32_t SERIAL_BAUDRATE = 115200;
static const uint32_t DELYAY_MS = 1000;
static const char NODE_NAME[] = "temp_esp32_c3";

// void timerCallBack(rcl_timer_t *timer, int64_t lastCallTime) {
//   RCLC_UNUSED(lastCallTime);

//   temperatureMessage.data = temperatureRead();
//   rcl_publish(&temperaturePublisher, &temperatureMessage, NULL);
// }

/**************************************************************************************************
 * @brief This function is automatically called once when the program starts.
          It configures the serial port with the specified baud rate.
 * @return Nothing
 *************************************************************************************************/
void setup() {
  // Config serial transport
  Serial.begin(SERIAL_BAUDRATE);
  set_microros_serial_transports(Serial);
  delay(DELYAY_MS);

  allocator = rcl_get_default_allocator();
  // TODO: Fix atomic error
  rclc_support_init(&support, 0, NULL, &allocator);

  // // Create node
  // rclc_node_init_default(&node, NODE_NAME, "", &support);
  // // Create publisher
  // rclc_publisher_init_default(
  //   &temperaturePublisher,
  //   &node,
  //   ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
  //   NODE_NAME);
  // // Create timer
  // const unsigned int timerTimeOut = 1000;
  // rclc_timer_init_default(
  //   &timer,
  //   &support,
  //   RCL_MS_TO_NS(timerTimeOut),
  //   timerCallBack);
  // // Create executor
  // rclc_executor_init(&executor, &support.context, 1, &allocator);
  // rclc_executor_add_timer(&executor, &timer);
}

/**************************************************************************************************
 * @brief This function is called repeatedly after setup()
 * @return Nothing
 *************************************************************************************************/
void loop() {
  delay(DELYAY_MS);
  // rclc_executor_spin_some(&executor, RCL_MS_TO_NS(DELYAY_MS));
}

