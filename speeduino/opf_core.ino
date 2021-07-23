#ifndef OPF_CORE
#define OPF_CORE

#include "opf_core.h"

//unsigned boot_count __attribute__((__section__(".noinit")));

void setupBoard()
{
  pinMode(PIN_SPI_SS, OUTPUT);
  pinMode(PIN_SPI_SCK, OUTPUT);
  pinMode(PIN_SPI_MISO, OUTPUT);
  pinMode(PIN_SPI_MOSI, OUTPUT);

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

  #if defined(USE_SPI_EEPROM)
    SPIClass SPI_for_flash(PIN_SPI_MOSI, PIN_SPI_MISO, PIN_SPI_SCK); //SPI1_MOSI, SPI1_MISO, SPI1_SCK
    SPI_for_flash.begin();
      //windbond W25Q16 SPI flash EEPROM emulation
      EEPROM_Emulation_Config EmulatedEEPROMMconfig{255UL, 4096UL, 31, 0x00100000UL};
      Flash_SPI_Config SPIconfig{PIN_SPI_SS, SPI_for_flash};
      SPI_EEPROM_Class EEPROM(EmulatedEEPROMMconfig, SPIconfig);
    EEPROM.clear();
  #endif

  //analogWrite(PIN_SPI_SS, 128);

  // #define PIN_SPI_SS              PB12 // W25Q16 (on board flash)
  // #define PIN_SPI_MOSI            PB15 // W25Q16 (on board flash)
  // #define PIN_SPI_MISO            PB14 // W25Q16 (on board flash)
  // #define PIN_SPI_SCK             PB13 // W25Q16 (on board flash)

  // #define PIN_SERIAL_RX PA10
  // #define PIN_SERIAL_TX PA9

  // #if defined(USE_SPI_EEPROM)

  //   pinMode(PIN_SPI_SS, OUTPUT);
  //   pinMode(PIN_SPI_SCK, OUTPUT);
  //   pinMode(PIN_SPI_MISO, OUTPUT);
  //   pinMode(PIN_SPI_MOSI, OUTPUT);

  //   SPIClass SPI_for_flash(PIN_SPI_MOSI, PIN_SPI_MISO, PIN_SPI_SCK, PIN_SPI_SS); //SPI1_MOSI, SPI1_MISO, SPI1_SCK

  //   EEPROM_Emulation_Config EmulatedEEPROMMconfig{255UL, 4096UL, 31, 0x00100000UL};
  //   Flash_SPI_Config SPIconfig{USE_SPI_EEPROM, SPI_for_flash};
  //   SPI_EEPROM_Class EEPROM(EmulatedEEPROMMconfig, SPIconfig);

  // #define pinIsReserved(pin) (((pin) == PA11) || ((pin) == PA12) || ((pin) == PIN_SPI_SS))
  // #endif
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

  // #define PIN_SERIAL_RX PA10
  // #define PIN_SERIAL_TX PA9
  // #define PIN_SERIAL2_RX PA10
  // #define PIN_SERIAL2_TX PA9
  // #define PIN_SERIAL3_RX PB10
  // #define PIN_SERIAL3_TX PB11
}

void runLoop()
{
  int recval = -1;
  if (Serial.available())
  {
    //recval = Serial.read();
    digitalToggle(LED_COMS);
  }
  // if (recval != -1)
  // {
  //   Serial.write(recval);
  //   Serial1.write(recval);
  //   recval = -1;
  //   //delay(10);
  //   if (Serial1.available())
  //   {
  //     recval = Serial1.read();
  //   }
  //   if (recval != -1)
  //   {
  //     Serial.write(recval);
  //   }
  // }

  // if ((Serial.available()) > 0)
  // {
  //   digitalToggle(LED_COMS);
  // }

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
    digitalToggle(PB12);
    digitalToggle(PB13);
    digitalToggle(PB14);
    digitalToggle(PB15);
  }
}

#endif
