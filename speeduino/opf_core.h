
#include <Arduino.h>
#include "globals.h"
#include "speeduino.h"
#include <src/STM32_CAN/STM32_CAN.h>


//#define USE_I2C_BARO
//#define USE_DBW_IFX9201
//#define USE_CAN_DASH
//#define USE_SPI_EEPROM PB12

#ifdef USE_SPI_EEPROM
#define PIN_SPI_SS PB12   // W25Q16 (on board flash)
#define PIN_SPI_MOSI PB15 // W25Q16 (on board flash)
#define PIN_SPI_MISO PB14 // W25Q16 (on board flash)
#define PIN_SPI_SCK PB13  // W25Q16 (on board flash)
#endif //USE_SPI_EEPROM

#ifdef USE_I2C_BARO
#include <src/LPS25HB/LPS25HBSensor.h>
#endif //USE_I2C_BARO

#ifdef USE_DBW_IFX9201
#include <src/IFX9201/src/IFX9201.h>
#define DIR_PIN PB9
#define STP_PIN PB7
#define DIS_PIN PB8_ALT1
#endif //USE_DBW_IFX9201



#define LED_RUNNING PG9
#define LED_WARNING PG10
#define LED_ALERT PG11
#define LED_COMS PG12

#define PIN_SERIAL_RX PA10
#define PIN_SERIAL_TX PA9

#define PIN_WIRE_SDA PB11
#define PIN_WIRE_SCL PB10

extern STM32_CAN Can0;
extern STM32_CAN Can1;
extern HardwareTimer Timer10;

void setupBoard();
void resetPins();
void setPins();
void runLoop();
void dash_generic(STM32_CAN *can);
