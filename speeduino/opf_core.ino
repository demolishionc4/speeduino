#ifndef OPF_CORE
#define OPF_CORE

#include "opf_core.h"

//unsigned boot_count __attribute__((__section__(".noinit")));

void setupBoard()
{
    #if defined(USE_SPI_EEPROM)
      pinMode(PIN_SPI_SS, OUTPUT);
      pinMode(PIN_SPI_SCK, OUTPUT);
      pinMode(PIN_SPI_MISO, OUTPUT);
      pinMode(PIN_SPI_MOSI, OUTPUT);
    #endif

  pinInjector1 = BOARD_MAX_IO_PINS;
  pinInjector2 = BOARD_MAX_IO_PINS;
  pinInjector3 = BOARD_MAX_IO_PINS;
  pinInjector4 = BOARD_MAX_IO_PINS;
  pinInjector5 = BOARD_MAX_IO_PINS;
  pinInjector6 = BOARD_MAX_IO_PINS;
  pinInjector7 = BOARD_MAX_IO_PINS;
  pinInjector8 = BOARD_MAX_IO_PINS;
  injectorOutputControl = BOARD_MAX_IO_PINS;
  pinCoil1 = BOARD_MAX_IO_PINS;
  pinCoil2 = BOARD_MAX_IO_PINS;
  pinCoil3 = BOARD_MAX_IO_PINS;
  pinCoil4 = BOARD_MAX_IO_PINS;
  pinCoil5 = BOARD_MAX_IO_PINS;
  pinCoil6 = BOARD_MAX_IO_PINS;
  pinCoil7 = BOARD_MAX_IO_PINS;
  pinCoil8 = BOARD_MAX_IO_PINS;
  ignitionOutputControl = BOARD_MAX_IO_PINS;
  pinTrigger = BOARD_MAX_IO_PINS;
  pinTrigger2 = BOARD_MAX_IO_PINS;
  pinTrigger3 = BOARD_MAX_IO_PINS;
  pinTPS = BOARD_MAX_IO_PINS;
  pinMAP = BOARD_MAX_IO_PINS;
  pinEMAP = BOARD_MAX_IO_PINS;
  pinMAP2 = BOARD_MAX_IO_PINS;
  pinIAT = BOARD_MAX_IO_PINS;
  pinCLT = BOARD_MAX_IO_PINS;
  pinO2 = BOARD_MAX_IO_PINS;
  pinO2_2 = BOARD_MAX_IO_PINS;
  pinBat = BOARD_MAX_IO_PINS;
  pinDisplayReset = BOARD_MAX_IO_PINS;
  pinTachOut = BOARD_MAX_IO_PINS;
  pinFuelPump = BOARD_MAX_IO_PINS;
  pinIdle1 = BOARD_MAX_IO_PINS;
  pinIdle2 = BOARD_MAX_IO_PINS;
  pinIdleUp = BOARD_MAX_IO_PINS;
  pinIdleUpOutput = BOARD_MAX_IO_PINS;
  pinCTPS = BOARD_MAX_IO_PINS;
  pinFuel2Input = BOARD_MAX_IO_PINS;
  pinSpark2Input = BOARD_MAX_IO_PINS;
  pinSpareTemp1 = BOARD_MAX_IO_PINS;
  pinSpareTemp2 = BOARD_MAX_IO_PINS;
  pinSpareOut1 = BOARD_MAX_IO_PINS;
  pinSpareOut2 = BOARD_MAX_IO_PINS;
  pinSpareOut3 = BOARD_MAX_IO_PINS;
  pinSpareOut4 = BOARD_MAX_IO_PINS;
  pinSpareOut5 = BOARD_MAX_IO_PINS;
  pinSpareOut6 = BOARD_MAX_IO_PINS;
  pinSpareHOut1 = BOARD_MAX_IO_PINS;
  pinSpareHOut2 = BOARD_MAX_IO_PINS;
  pinSpareLOut1 = BOARD_MAX_IO_PINS;
  pinSpareLOut2 = BOARD_MAX_IO_PINS;
  pinSpareLOut3 = BOARD_MAX_IO_PINS;
  pinSpareLOut4 = BOARD_MAX_IO_PINS;
  pinSpareLOut5 = BOARD_MAX_IO_PINS;
  pinBoost = BOARD_MAX_IO_PINS;
  pinVVT_1 = BOARD_MAX_IO_PINS;
  pinVVT_2 = BOARD_MAX_IO_PINS;
  pinFan = BOARD_MAX_IO_PINS;
  pinStepperDir = BOARD_MAX_IO_PINS;
  pinStepperStep = BOARD_MAX_IO_PINS;
  pinStepperEnable = BOARD_MAX_IO_PINS;
  pinLaunch = BOARD_MAX_IO_PINS;
  pinIgnBypass = BOARD_MAX_IO_PINS;
  pinFlex = BOARD_MAX_IO_PINS;
  pinVSS = BOARD_MAX_IO_PINS;
  pinBaro = BOARD_MAX_IO_PINS;
  pinResetControl = BOARD_MAX_IO_PINS;
  pinFuelPressure = BOARD_MAX_IO_PINS;
  pinOilPressure = BOARD_MAX_IO_PINS;
  pinWMIEmpty = BOARD_MAX_IO_PINS;
  pinWMIIndicator = BOARD_MAX_IO_PINS;
  pinWMIEnabled = BOARD_MAX_IO_PINS;
  pinMC33810_1_CS = BOARD_MAX_IO_PINS;
  pinMC33810_2_CS = BOARD_MAX_IO_PINS;
}

void initialiseBoard()
{
  //CAN BUS
  STM32_CAN Can0(_CAN1, DEF);
  STM32_CAN Can1(_CAN2, ALT);

  //STATUS LED
  pinMode(LED_RUNNING, OUTPUT);
  pinMode(LED_WARNING, OUTPUT);
  pinMode(LED_ALERT, OUTPUT);
  pinMode(LED_COMS, OUTPUT);

  //SPI FLASH
    #if defined(USE_SPI_EEPROM)
      pinMode(USE_SPI_EEPROM, OUTPUT);
    #endif
}

void runLoop()
{
  int recval = -1;
  if (Serial.available())
  {
    //recval = Serial.read();
    digitalToggle(LED_COMS);
  }

  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_1HZ)) //1 hertz
  {
    digitalToggle(LED_RUNNING);
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_4HZ)) //4 hertz
  {
    digitalToggle(LED_WARNING);
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_10HZ)) //10 hertz
  {
    digitalToggle(LED_ALERT);
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_15HZ)) //15 hertz
  {
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_30HZ)) //30 hertz
  {

  }
}

#endif
