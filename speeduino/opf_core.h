
#include <Arduino.h>
#include "globals.h"
#include "speeduino.h"
#include <src/STM32_CAN/STM32_CAN.h>


#define LED_RUNNING PG9
#define LED_WARNING PG10
#define LED_ALERT PG11
#define LED_COMS PG12

#define PIN_SPI_SS PB12   // W25Q16 (on board flash)
#define PIN_SPI_MOSI PB15 // W25Q16 (on board flash)
#define PIN_SPI_MISO PB14 // W25Q16 (on board flash)
#define PIN_SPI_SCK PB13  // W25Q16 (on board flash)

#define USE_SPI_EEPROM PIN_SPI_SS

#define PIN_SERIAL_RX PA10
#define PIN_SERIAL_TX PA9

#define USE_I2C_BARO

extern STM32_CAN Can0;
extern STM32_CAN Can1;

void setupBoard();
void resetPins();
void setPins();
void runLoop();
void dash_generic(STM32_CAN *can);
