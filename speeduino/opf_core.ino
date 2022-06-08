#ifndef OPF_CORE
#define OPF_CORE

#include "opf_core.h"

void setupBoard()
{
  configPage2.pinMapping = 51;

  //STATUS LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  resetPins();
  setPins();
  initialiseAll();
  
}

void setPins()
{

  // //******************************************
  // //******** Trigger CONNECTIONS ***************
  // //******************************************

  pinTrigger = 47; //106
  pinTrigger2 = 48;  //107
  // pinTrigger3 = PE4;  //104
  // pinVSS = PE5;       //105

  // //******************************************
  // //******** ANALOG CONNECTIONS ***************
  // //******************************************

  pinBat = 49;  //A12
  pinCLT = A10;  //A7
  pinTPS = 21;  //A9
  pinIAT = A11;  //A8
  pinO2 = 22;   //A13
  //pinO2_2 = PC2; //A14
  pinBaro = A2; //A1
  pinMAP = A24;   //A5
  pinOilPressure = A0;  //A0
  //pinSpareTemp1 = PC4; //OIL TEMP
  pinFuelPressure = A1; //A2

  // //******************************************
  // //******** INJECTOR CONNECTIONS ***************
  // //******************************************

  pinInjector8 = 43; //9
  pinInjector7 = 44; //8
  pinInjector6 = 45; //7
  pinInjector5 = 46; //6
  pinInjector4 = 29;  //5
  pinInjector3 = 30;  //4
  pinInjector2 = 31; //71
  pinInjector1 = 32; //70

  // //******************************************
  // //******** COIL CONNECTIONS ***************
  // //******************************************

  pinCoil1 = 27; //59
  pinCoil2 = 28; //58
  pinCoil3 = 25; //61
  pinCoil4 = 26; //60
  pinCoil5 = 41; //63
  pinCoil6 = 40; //68
  pinCoil7 = 24;  //69
  pinCoil8 = 42;  //66

  // //******************************************
  // //******** OTHER CONNECTIONS ***************
  // //******************************************

  pinTachOut = 2;    //10
  pinIdle1 = 5;      //11
  //pinIdle2 = PG2;       //12
  pinBoost = 6;       //13
  pinStepperDir = 36;  //14
  pinStepperStep = 35; //15
  pinFuelPump = 8;    //16
  pinFan = 7;         //17
  pinLaunch = 37;      
}

void resetPins()
{
  pinInjector1 = BOARD_MAX_IO_PINS - 1;
  pinInjector2 = BOARD_MAX_IO_PINS - 1;
  pinInjector3 = BOARD_MAX_IO_PINS - 1;
  pinInjector4 = BOARD_MAX_IO_PINS - 1;
  pinInjector5 = BOARD_MAX_IO_PINS - 1;
  pinInjector6 = BOARD_MAX_IO_PINS - 1;
  pinInjector7 = BOARD_MAX_IO_PINS - 1;
  pinInjector8 = BOARD_MAX_IO_PINS - 1;
  injectorOutputControl = 0;
  pinCoil1 = BOARD_MAX_IO_PINS - 1;
  pinCoil2 = BOARD_MAX_IO_PINS - 1;
  pinCoil3 = BOARD_MAX_IO_PINS - 1;
  pinCoil4 = BOARD_MAX_IO_PINS - 1;
  pinCoil5 = BOARD_MAX_IO_PINS - 1;
  pinCoil6 = BOARD_MAX_IO_PINS - 1;
  pinCoil7 = BOARD_MAX_IO_PINS - 1;
  pinCoil8 = BOARD_MAX_IO_PINS - 1;
  ignitionOutputControl = 0;
  pinTrigger = BOARD_MAX_IO_PINS - 1;
  pinTrigger2 = BOARD_MAX_IO_PINS - 1;
  pinTrigger3 = BOARD_MAX_IO_PINS - 1;
  pinTPS = BOARD_MAX_IO_PINS - 1;
  pinMAP = BOARD_MAX_IO_PINS - 1;
  pinEMAP = BOARD_MAX_IO_PINS - 1;
  pinMAP2 = BOARD_MAX_IO_PINS - 1;
  pinIAT = BOARD_MAX_IO_PINS - 1;
  pinCLT = BOARD_MAX_IO_PINS - 1;
  pinO2 = BOARD_MAX_IO_PINS - 1;
  pinO2_2 = BOARD_MAX_IO_PINS - 1;
  pinBat = BOARD_MAX_IO_PINS - 1;
  pinDisplayReset = BOARD_MAX_IO_PINS - 1;
  pinTachOut = BOARD_MAX_IO_PINS - 1;
  pinFuelPump = BOARD_MAX_IO_PINS - 1;
  pinIdle1 = BOARD_MAX_IO_PINS - 1;
  pinIdle2 = BOARD_MAX_IO_PINS - 1;
  pinIdleUp = BOARD_MAX_IO_PINS - 1;
  pinIdleUpOutput = BOARD_MAX_IO_PINS - 1;
  pinCTPS = BOARD_MAX_IO_PINS - 1;
  pinFuel2Input = BOARD_MAX_IO_PINS - 1;
  pinSpark2Input = BOARD_MAX_IO_PINS - 1;
  pinSpareTemp1 = BOARD_MAX_IO_PINS - 1;
  pinSpareTemp2 = BOARD_MAX_IO_PINS - 1;
  pinSpareOut1 = BOARD_MAX_IO_PINS - 1;
  pinSpareOut2 = BOARD_MAX_IO_PINS - 1;
  pinSpareOut3 = BOARD_MAX_IO_PINS - 1;
  pinSpareOut4 = BOARD_MAX_IO_PINS - 1;
  pinSpareOut5 = BOARD_MAX_IO_PINS - 1;
  pinSpareOut6 = BOARD_MAX_IO_PINS - 1;
  pinSpareHOut1 = BOARD_MAX_IO_PINS - 1;
  pinSpareHOut2 = BOARD_MAX_IO_PINS - 1;
  pinSpareLOut1 = BOARD_MAX_IO_PINS - 1;
  pinSpareLOut2 = BOARD_MAX_IO_PINS - 1;
  pinSpareLOut3 = BOARD_MAX_IO_PINS - 1;
  pinSpareLOut4 = BOARD_MAX_IO_PINS - 1;
  pinSpareLOut5 = BOARD_MAX_IO_PINS - 1;
  pinBoost = BOARD_MAX_IO_PINS - 1;
  pinVVT_1 = BOARD_MAX_IO_PINS - 1;
  pinVVT_2 = BOARD_MAX_IO_PINS - 1;
  pinFan = BOARD_MAX_IO_PINS - 1;
  pinStepperDir = BOARD_MAX_IO_PINS - 1;
  pinStepperStep = BOARD_MAX_IO_PINS - 1;
  pinStepperEnable = BOARD_MAX_IO_PINS - 1;
  pinLaunch = BOARD_MAX_IO_PINS - 1;
  pinIgnBypass = BOARD_MAX_IO_PINS - 1;
  pinFlex = BOARD_MAX_IO_PINS - 1;
  pinVSS = BOARD_MAX_IO_PINS - 1;
  pinBaro = BOARD_MAX_IO_PINS - 1;
  pinResetControl = BOARD_MAX_IO_PINS - 1;
  pinFuelPressure = BOARD_MAX_IO_PINS - 1;
  pinOilPressure = BOARD_MAX_IO_PINS - 1;
  pinWMIEmpty = BOARD_MAX_IO_PINS - 1;
  pinWMIIndicator = BOARD_MAX_IO_PINS - 1;
  pinWMIEnabled = BOARD_MAX_IO_PINS - 1;
  pinMC33810_1_CS = BOARD_MAX_IO_PINS - 1;
  pinMC33810_2_CS = BOARD_MAX_IO_PINS - 1;
}

void runLoop()
{
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_1HZ)) //1 hertz
  {
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_4HZ)) //4 hertz
  {
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_10HZ)) //10 hertz
  {
    digitalToggle(LED_BUILTIN);
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_15HZ)) //15 hertz
  {
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_30HZ)) //30 hertz
  {
  }
}

#endif
