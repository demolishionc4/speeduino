#ifndef OPF_CORE
#define OPF_CORE

#include "opf_core.h"

#ifdef USE_I2C_BARO
TwoWire LPS_dev(PIN_WIRE_SDA, PIN_WIRE_SCL);
LPS22HHSensor LPS_Sensor(&LPS_dev, LPS22HH_I2C_ADD_L);
#endif //USE_I2C_BARO

#ifdef USE_DBW_IFX9201

HardwareTimer Timer10(TIM10);
IFX9201 IFX9201_HBridge = IFX9201( );

#endif //USE_DBW_IFX9201

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
  #ifdef USE_SPI_EEPROM
    EEPROM.begin(SPI_for_flash, PIN_SPI_SS);
  #endif
  #ifdef USE_I2C_BARO
    LPS_dev.begin();
    LPS_Sensor.begin();
    LPS_Sensor.Enable();
  #endif //USE_I2C_BARO

  #ifdef USE_DBW_IFX9201
    // Timer10.setMode(1, TIMER_OUTPUT_COMPARE_PWM1, DIS_PIN);  //DBW PWM output fixed to PB8/
    // Timer10.setOverflow(20000, HERTZ_FORMAT);
    // Timer10.setCaptureCompare(1, 0, RESOLUTION_12B_COMPARE_FORMAT);
    // Timer10.resume();
    //IFX9201_HBridge.begin( DIR_PIN, STP_PIN, DIS_PIN );

    //IFX9201_HBridge.forwards( 50 );       // Same as forwards( )
    //IFX9201_HBridge.stop( );
    //IFX9201_HBridge.backwards( 50 );
    //IFX9201_HBridge.stop( );

    // TIM_TypeDef *Instance = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(DIS_PIN), PinMap_PWM);
    // uint32_t channel = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(DIS_PIN), PinMap_PWM));
    //Timer10->setPWM(channel, DIS_PIN, 10, 50, dbwScheduleInterrupt);

    //DBWMotor.begin();
    //DBWMotor.setSpeed(100);
  #endif //USE_DBW_IFX9201

  initialiseAll();
  
  Can0.begin();
  Can0.setBaudRate(500000);
  Can0.enableFIFO();
  
  Can1.begin();
  Can1.setBaudRate(500000);
  Can1.enableFIFO();
}

#ifdef USE_DBW_IFX9201
void dbwScheduleInterrupt(){
  digitalToggle(LED_WARNING);
}
#endif //USE_DBW_IFX9201


void setPins()
{

  //******************************************
  //******** Trigger CONNECTIONS ***************
  //******************************************

  pinTrigger = PE2; //106
  pinTrigger2 = PE3;  //107
  pinTrigger3 = PE4;  //104
  pinVSS = PE5;       //105

  //******************************************
  //******** ANALOG CONNECTIONS ***************
  //******************************************
  //ADC1 = STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 6, 0)

  pinBat = PA0;  //A12
  pinCLT = PA3;  //A7
  pinTPS = PA1;  //A9
  pinIAT = PA4;  //A8
  pinO2 = PC1;   //A13
  pinO2_2 = PC2; //A14
  pinBaro = PC5; //A1
  pinMAP = PA5;   //A5
  pinOilPressure = PA7;  //A0
  pinFuelPressure = PC4; //A2

  //******************************************
  //******** INJECTOR CONNECTIONS ***************
  //******************************************

  pinInjector8 = PD13; //9
  pinInjector7 = PD12; //8
  pinInjector6 = PD11; //7
  pinInjector5 = PD10; //6
  pinInjector4 = PD9;  //5
  pinInjector3 = PD8;  //4
  pinInjector2 = PF14; //71
  pinInjector1 = PF13; //70

  //******************************************
  //******** COIL CONNECTIONS ***************
  //******************************************

  pinCoil1 = PE15; //59
  pinCoil2 = PE14; //58
  pinCoil3 = PE13; //61
  pinCoil4 = PE12; //60
  pinCoil5 = PE11; //63
  pinCoil6 = PF15; //68
  pinCoil7 = PG0;  //69
  pinCoil8 = PG1;  //66

  //******************************************
  //******** OTHER CONNECTIONS ***************
  //******************************************

  pinTachOut = PD14;    //10
  pinIdle1 = PD15;      //11
  pinIdle2 = PG2;       //12
  pinBoost = PG3;       //13
  pinStepperDir = PG4;  //14
  pinStepperStep = PG5; //15
  pinFuelPump = PG6;    //16
  pinFan = PG7;         //17
  pinLaunch = PF5;      
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
  #ifdef USE_CAN_DASH
    dash_generic(&Can1);
  #endif
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_1HZ)) //1 hertz
  {

    //DBWMotor.move_revolution(4);
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_4HZ)) //4 hertz
  {
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_10HZ)) //10 hertz
  {
    digitalToggle(LED_RUNNING);
    #ifdef USE_I2C_BARO
        float pressure;
        float temperature;
        LPS_Sensor.GetPressure(&pressure);
        LPS_Sensor.GetTemperature(&temperature);
        currentStatus.fuelTemp = temperature;
        currentStatus.baro = pressure / 10.0f;
    #endif
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_15HZ)) //15 hertz
  {
    //Timer10.setCaptureCompare(1, abs(2048), RESOLUTION_12B_COMPARE_FORMAT);
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_30HZ)) //30 hertz
  {
  }
}

void dash_generic(STM32_CAN *can)
{
  //BMW iDrive controller
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_1HZ))
  {
    outMsg.id = 0x202;
    outMsg.len = 1;
    outMsg.buf[0] = 0xFD;
    can->write(outMsg);

    outMsg.id = 0x563;
    outMsg.len = 1;
    outMsg.buf[0] = 0x63;
    can->write(outMsg);

    outMsg.id = 0x273;
    outMsg.len = 8;
    outMsg.buf[0] = 0x1D;
    outMsg.buf[1] = 0xE1;
    outMsg.buf[2] = 0x00;
    outMsg.buf[3] = 0xF0;
    outMsg.buf[4] = 0xFF;
    outMsg.buf[5] = 0x7F;
    outMsg.buf[6] = 0xDE;
    outMsg.buf[7] = 0x00;
    can->write(outMsg);

    delay(1);
  }
  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_4HZ))
  {

    outMsg.id = 0x370 + 2;
    outMsg.len = 8;
    outMsg.buf[0] = highByte(currentStatus.battery10);
    outMsg.buf[1] = lowByte(currentStatus.battery10);
    outMsg.buf[2] = highByte(0x00);
    outMsg.buf[3] = lowByte(0x00);
    outMsg.buf[4] = highByte(currentStatus.boostTarget);
    outMsg.buf[5] = lowByte(currentStatus.boostTarget);
    outMsg.buf[6] = highByte(currentStatus.baro);
    outMsg.buf[7] = lowByte(currentStatus.baro);
    can->write(outMsg);

    outMsg.id = 0x3E0 + 0;
    outMsg.len = 4;
    outMsg.buf[0] = highByte(currentStatus.coolant);
    outMsg.buf[1] = lowByte(currentStatus.coolant);
    outMsg.buf[2] = highByte(currentStatus.IAT);
    outMsg.buf[3] = lowByte(currentStatus.IAT);
    can->write(outMsg);

    outMsg.id = 0x368 + 1;
    outMsg.len = 2;
    outMsg.buf[0] = highByte(currentStatus.syncLossCounter);
    outMsg.buf[1] = lowByte(currentStatus.syncLossCounter);
    can->write(outMsg);
    delay(1);
  }

  if (BIT_CHECK(LOOP_TIMER, BIT_TIMER_30HZ))
  {
    outMsg.id = 0x3E8;
    outMsg.len = 8;
    outMsg.buf[0] = 0;
    outMsg.buf[1] = 0;
    outMsg.buf[2] = lowByte(currentStatus.RPM);
    outMsg.buf[3] = highByte(currentStatus.RPM);
    outMsg.buf[4] = lowByte(currentStatus.MAP - currentStatus.baro);
    outMsg.buf[5] = highByte(currentStatus.MAP - currentStatus.baro);
    outMsg.buf[6] = 0;
    outMsg.buf[7] = 0;
    can->write(outMsg);

    outMsg.id = 0x3E8;
    outMsg.len = 8;
    outMsg.buf[0] = 0 + 1;
    outMsg.buf[1] = 0;
    outMsg.buf[2] = lowByte(currentStatus.baro * 10);
    outMsg.buf[3] = highByte(currentStatus.baro * 10);
    outMsg.buf[4] = lowByte(currentStatus.TPS * 10);
    outMsg.buf[5] = highByte(currentStatus.TPS * 10);
    outMsg.buf[6] = 0;
    outMsg.buf[7] = 0;
    can->write(outMsg);

    outMsg.id = 0x3E8;
    outMsg.len = 8;
    outMsg.buf[0] = 0 + 2;
    outMsg.buf[1] = 0;
    outMsg.buf[2] = 0;
    outMsg.buf[3] = 0;
    outMsg.buf[4] = lowByte(currentStatus.PW1);
    outMsg.buf[5] = highByte(currentStatus.PW1);
    outMsg.buf[6] = lowByte(currentStatus.coolant + 50);
    outMsg.buf[7] = highByte(currentStatus.coolant + 50);
    can->write(outMsg);

    delay(1);

    outMsg.id = 0x3E8;
    outMsg.len = 8;
    outMsg.buf[0] = 0 + 3;
    outMsg.buf[1] = 0;
    outMsg.buf[2] = lowByte(currentStatus.IAT + 50);
    outMsg.buf[3] = highByte(currentStatus.IAT + 50);
    outMsg.buf[4] = lowByte(currentStatus.battery10 * 10);
    outMsg.buf[5] = highByte(currentStatus.battery10 * 10);
    outMsg.buf[6] = 0;
    outMsg.buf[7] = 0;
    can->write(outMsg);

    outMsg.id = 0x3E8;
    outMsg.len = 8;
    outMsg.buf[0] = 0 + 6;
    outMsg.buf[1] = 0;
    outMsg.buf[2] = 0;
    outMsg.buf[3] = 0;
    outMsg.buf[4] = lowByte((uint8_t)(currentStatus.O2 * 100 / configPage2.stoich));
    outMsg.buf[5] = highByte((uint8_t)(currentStatus.O2 * 100 / configPage2.stoich));
    outMsg.buf[6] = 0;
    outMsg.buf[7] = 0;
    can->write(outMsg);

    outMsg.id = 0x3E8;
    outMsg.len = 8;
    outMsg.buf[0] = 0 + 7;
    outMsg.buf[1] = 0;
    outMsg.buf[2] = lowByte(currentStatus.syncLossCounter);
    outMsg.buf[3] = highByte(currentStatus.syncLossCounter);
    outMsg.buf[4] = 0;
    outMsg.buf[5] = 0;
    outMsg.buf[6] = lowByte(currentStatus.fuelPressure * 10);
    outMsg.buf[7] = highByte(currentStatus.fuelPressure * 10);
    can->write(outMsg);

    delay(1);

    outMsg.id = 0x3E8;
    outMsg.len = 8;
    outMsg.buf[0] = 0 + 8;
    outMsg.buf[1] = 0;
    outMsg.buf[2] = 0;
    outMsg.buf[3] = 0;
    outMsg.buf[4] = lowByte(currentStatus.oilPressure * 10);
    outMsg.buf[5] = highByte(currentStatus.oilPressure * 10);
    outMsg.buf[6] = 0;
    outMsg.buf[7] = 0;
    can->write(outMsg);

    //
  }
}

#endif
