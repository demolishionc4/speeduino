#include <Arduino.h>
#include "speeduino.h"

#ifdef CORE_STM32
#include <src/STM32_CAN/STM32_CAN.h>
#endif  
#ifdef CORE_TEENSY
#include <FlexCAN_T4.h>
#endif  

#ifdef USE_SPI_EEPROM

    #undef USE_SPI_EEPROM
    #undef PIN_SPI_SS
    #undef PIN_SPI_MOSI
    #undef PIN_SPI_MISO
    #undef PIN_SPI_SCK
    
    #if (USE_CORE8_VERSION == 23)
        #define USE_SPI_EEPROM PB12 
    #else
        #define USE_SPI_EEPROM PD6
    #endif //USE_CORE8_VERSION

    #define PIN_SPI_SS USE_SPI_EEPROM
    #define PIN_SPI_MOSI PB15 // W25Q16 (on board flash)
    #define PIN_SPI_MISO PB14 // W25Q16 (on board flash)
    #define PIN_SPI_SCK PB13  // W25Q16 (on board flash)
#endif                    //USE_SPI_EEPROM

#ifdef USE_I2C_BARO
    #if (USE_CORE8_VERSION == 23)
        #include <src/LPS25HB/LPS25HBSensor.h>
    #else
        #include <src/LPS22HH/LPS22HHSensor.h>
    #endif //USE_CORE8_VERSION
#endif //USE_I2C_BARO

void setupBoard();
void setPins();
void resetPins();
void runLoop();





































