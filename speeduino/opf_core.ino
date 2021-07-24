#ifndef OPF_CORE
#define OPF_CORE

#include "opf_core.h"

void setupBoard()
{
  resetPins();
  setPins();
  configPage2.pinMapping = 60;

  STM32_CAN Can0(_CAN1, DEF);
  STM32_CAN Can1(_CAN2, DEF);

  //STATUS LED
  pinMode(LED_RUNNING, OUTPUT);
  digitalWrite(LED_RUNNING, LOW);
  pinMode(LED_WARNING, OUTPUT);
  digitalWrite(LED_WARNING, LOW);
  pinMode(LED_ALERT, OUTPUT);
  digitalWrite(LED_ALERT, LOW);
  pinMode(LED_COMS, OUTPUT);
  digitalWrite(LED_COMS, LOW);

  SPIClass SPI_for_flash(PIN_SPI_MOSI, PIN_SPI_MISO, PIN_SPI_SCK); //SPI1_MOSI, SPI1_MISO, SPI1_SCK

  //windbond W25Q16 SPI flash EEPROM emulation
  EEPROM_Emulation_Config EmulatedEEPROMMconfig{255UL, 4096UL, 31, 0x00100000UL};
  Flash_SPI_Config SPIconfig{USE_SPI_EEPROM, SPI_for_flash};
  SPI_EEPROM_Class EEPROM(EmulatedEEPROMMconfig, SPIconfig);

  initialiseAll();
  //SPI FLASH
}

void setPins()
{

  //******************************************
  //******** Trigger CONNECTIONS ***************
  //******************************************

  pinTrigger = PE2;
  pinTrigger2 = PE3;
  pinTrigger3 = PE4;
  pinVSS = PE5;

  //******************************************
  //******** ANALOG CONNECTIONS ***************
  //******************************************
  //ADC1 = STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 6, 0)

  pinBat = PA0;  //ADC123
  pinCLT = PA3;  //ADC12
  pinTPS = PA1;  //ADC12
  pinIAT = PA4;  //ADC12 LED_BUILTIN_1
  pinO2 = PC1;   //ADC12 LED_BUILTIN_2
  pinO2_2 = PC2; //ADC12 LED_BUILTIN_2
  pinBaro = PC5; //ADC12
  pinMAP = PA5;
  pinOilPressure = PB1;  //(DO NOT USE FOR SPEEDUINO) ADC123 - SPI FLASH CHIP CS pin
  pinFuelPressure = PB0; //ADC12

  //******************************************
  //******** INJECTOR CONNECTIONS ***************
  //******************************************

  pinInjector8 = PD13; //
  pinInjector7 = PD12; //
  pinInjector6 = PD11; //
  pinInjector5 = PD10; //
  pinInjector4 = PD9;  //
  pinInjector3 = PD8;  //
  pinInjector2 = PF14; //
  pinInjector1 = PF13; //

  //******************************************
  //******** COIL CONNECTIONS ***************
  //******************************************

  pinCoil1 = PE15; //
  pinCoil2 = PE14; //
  pinCoil3 = PE13; //
  pinCoil4 = PE12; //
  pinCoil5 = PE11; //
  pinCoil6 = PF15; //
  pinCoil7 = PG0;  //
  pinCoil8 = PG1;  //

  //******************************************
  //******** OTHER CONNECTIONS ***************
  //******************************************

  pinTachOut = PD14;    //Tacho output pin
  pinIdle1 = PD15;      //Single wire idle control
  pinIdle2 = PG2;       //2 wire idle control
  pinBoost = PG3;       //Boost control
  pinStepperDir = PG4;  //Direction pin  for DRV8825 driver
  pinStepperStep = PG5; //Step pin for DRV8825 driver
  pinFuelPump = PG6;    //Fuel pump output
  pinFan = PG7;         //Pin for the fan output (Goes to ULN2803)
}
void resetPins()
{
  pinInjector1 = BOARD_MAX_IO_PINS;
  pinInjector2 = BOARD_MAX_IO_PINS;
  pinInjector3 = BOARD_MAX_IO_PINS;
  pinInjector4 = BOARD_MAX_IO_PINS;
  pinInjector5 = BOARD_MAX_IO_PINS;
  pinInjector6 = BOARD_MAX_IO_PINS;
  pinInjector7 = BOARD_MAX_IO_PINS;
  pinInjector8 = BOARD_MAX_IO_PINS;
  injectorOutputControl = 0;
  pinCoil1 = BOARD_MAX_IO_PINS;
  pinCoil2 = BOARD_MAX_IO_PINS;
  pinCoil3 = BOARD_MAX_IO_PINS;
  pinCoil4 = BOARD_MAX_IO_PINS;
  pinCoil5 = BOARD_MAX_IO_PINS;
  pinCoil6 = BOARD_MAX_IO_PINS;
  pinCoil7 = BOARD_MAX_IO_PINS;
  pinCoil8 = BOARD_MAX_IO_PINS;
  ignitionOutputControl = 0;
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

void runLoop()
{
  int recval = -1;
  if ((Serial.available()) > 0)
  {
    //recval = Serial.read();
    digitalToggle(LED_COMS);
  }
  else
  {
    digitalWrite(LED_COMS, LOW);
  }

  digitalWrite(LED_ALERT, currentStatus.engineProtectStatus);

  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_1HZ)) //1 hertz
  {      
      #ifdef USE_I2C_BARO
        float pressure;
        float temperature;
        lps.GetPressure(&pressure);
        lps.GetTemperature(&temperature);
        currentStatus.fuelTemp = temperature; 
        currentStatus.baro = pressure / 10.0f; 
      #endif
      
      #ifndef USE_I2C_BARO
      readBaro(); //Infrequent baro readings are not an issue.
      #endif   
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_4HZ)) //4 hertz
  {
    digitalToggle(LED_RUNNING);  
    //digitalToggle(LED_WARNING);
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_10HZ)) //10 hertz
  {
    //digitalToggle(LED_ALERT);
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_15HZ)) //15 hertz
  {
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_30HZ)) //30 hertz
  {
  }
}

#endif
