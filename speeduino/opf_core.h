#include <Arduino.h>
#include "speeduino.h"

#include <src/STM32_CAN/STM32_CAN.h>

#define USE_I2C_BARO true
#define USE_CAN_DASH true
#define NUM_DIGITAL_PINS 103

#define CORE8_VERSION 24

#if (CORE8_VERSION == 23)
    #define USE_SPI_EEPROM PB12 
#else
    #define USE_SPI_EEPROM PD6
#endif //CORE8_VERSION

#ifdef USE_SPI_EEPROM
    
    #define PIN_SPI_SS USE_SPI_EEPROM
    #define PIN_SPI_MOSI PB15 // W25Q16 (on board flash)
    #define PIN_SPI_MISO PB14 // W25Q16 (on board flash)
    #define PIN_SPI_SCK PB13  // W25Q16 (on board flash)
#endif                    //USE_SPI_EEPROM

#ifdef USE_I2C_BARO
    #if (CORE8_VERSION == 23)
        #include <src/LPS25HB/LPS25HBSensor.h>
    #else
        #include <src/LPS22HH/LPS22HHSensor.h>
    #endif //CORE8_VERSION
#endif //USE_I2C_BARO

#define LED_RUNNING PG10
#define LED_WARNING PG11
#define LED_ALERT PG12
#define LED_COMS PG13

#define PIN_SERIAL_RX PA10
#define PIN_SERIAL_TX PA9

#define PIN_WIRE_SDA PB11
#define PIN_WIRE_SCL PB10


void setupBoard();
void setPins();
void runLoop();





































