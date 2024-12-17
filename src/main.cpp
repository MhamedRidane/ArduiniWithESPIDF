/**************************************************************************************************
// Includes
**************************************************************************************************/
#include <Arduino.h>
#include <driver/temp_sensor.h>

/**************************************************************************************************
// Variables
**************************************************************************************************/
uint32_t SERIAL_BAUDRATE = 115200;
uint32_t DELYAY = 1000;

/**************************************************************************************************
 * @brief Setup function
 * @return Nothing
 * This function is automatically called once when the program starts.
 * It configures the serial port with the specified baud rate.
 *************************************************************************************************/
void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println("Hello, ESP32-C3 with Arduino and ESP-IDF!\r\n");
}

/**************************************************************************************************
 * @brief Loop function
 * @return Nothing
 * This function is called repeatedly after setup()
 *************************************************************************************************/
void loop() {
  float temperature = temperatureRead(); 
  Serial.printf("temp:%.2f\r\n", temperature);
  delay(DELYAY);
}

