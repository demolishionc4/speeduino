
#include <Arduino.h>
#include "globals.h"

#define LED_RUNNING PG9
#define LED_WARNING PG10
#define LED_ALERT PG11
#define LED_COMS PG12

//#define USE_I2C_BARO
#ifdef USE_I2C_BARO
#include <src/LPS25HB/LPS25HBSensor.h>
TwoWire dev_i2c(PB11, PB10);
LPS25HBSensor lps(&dev_i2c, LPS25HB_ADDRESS_LOW);
#endif //USE_I2C_BARO

void setupBoard();
void initialiseBoard();
void runLoop();

extern STM32_CAN Can0;
extern STM32_CAN Can1;