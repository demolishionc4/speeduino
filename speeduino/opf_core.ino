#ifndef OPF_CORE
#define OPF_CORE

#include "opf_core.h"

//unsigned boot_count __attribute__((__section__(".noinit")));

void setupBoard()
{
  
  #define PIN_SERIAL_RX        PA10
  #define PIN_SERIAL_TX        PA9
  #define PIN_SERIAL2_RX        PA10
  #define PIN_SERIAL2_TX        PA9
  #define PIN_SERIAL3_RX        PB10
  #define PIN_SERIAL3_TX        PB11

  pinMode(PB12, OUTPUT);
  pinMode(PB13, OUTPUT);
  pinMode(PB14, OUTPUT);
  pinMode(PB15, OUTPUT);


#if defined(USE_SPI_EEPROM)


  SPIClass SPI_for_flash(113, 112, 111); //SPI1_MOSI, SPI1_MISO, SPI1_SCK

  SPI_for_flash.setMOSI(113);
  SPI_for_flash.setMISO(112);
  SPI_for_flash.setSCLK(111);
  SPI_for_flash.setSSEL(110);

  EEPROM_Emulation_Config EmulatedEEPROMMconfig{255UL, 4096UL, 31, 0x00100000UL};
  Flash_SPI_Config SPIconfig{USE_SPI_EEPROM, SPI_for_flash};
  SPI_EEPROM_Class EEPROM(EmulatedEEPROMMconfig, SPIconfig);
  
  #define pinIsReserved(pin) (((pin) == PA11) || ((pin) == PA12) || ((pin) == USE_SPI_EEPROM))
#endif

}

void initialiseBoard()
{
  //CAN BUS
  STM32_CAN Can0(_CAN1, DEF);
  STM32_CAN Can1(_CAN2, ALT);

  //STATUS LED
  pinMode(PG9, OUTPUT);
  pinMode(PG10, OUTPUT);
  pinMode(PG11, OUTPUT);
  pinMode(PG12, OUTPUT);

  //SPI FLASH
}

void runLoop()
{
  if ( (Serial.available()) > 0){
    digitalToggle(PG12);
  }

  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_1HZ)) //1 hertz
  {
    digitalToggle(PG9);
    
    pinMode(PB12, OUTPUT);
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_4HZ)) //4 hertz
  {
    digitalToggle(PG10);
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_10HZ)) //10 hertz
  {
    digitalToggle(PG11);
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
