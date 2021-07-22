
#include <Arduino.h>
#include "globals.h"
#include "stm32yyxx_ll_bus.h"

void setupBoard();
void initialiseBoard();
void runLoop();

extern STM32_CAN Can0;
extern STM32_CAN Can1;