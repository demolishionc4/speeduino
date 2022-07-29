#!/bin/bash

# backup
cp speeduino/board_stm32_official.h build/backup/board_stm32_official.h
cp speeduino/board_stm32_official.ino build/backup/board_stm32_official.ino
cp speeduino/speeduino.ino build/backup/speeduino.ino

cp build/core8.h speeduino/core8.h
cp build/core8.ino speeduino/core8.ino
cp build/core8.h speeduino/core8.h

cp -R build/src speeduino

if ! grep -q 'extern STM32_CAN Can1;' speeduino/board_stm32_official.h; then
  gsed -i 's/extern STM32_CAN Can0;/extern STM32_CAN Can0;\nextern STM32_CAN Can1;/gI' speeduino/board_stm32_official.h
fi

if ! grep -q 'STM32_CAN Can1 (CAN2, ALT, RX_SIZE_256, TX_SIZE_16);' speeduino/board_stm32_official.ino; then
  gsed -i 's/STM32_CAN Can0 (CAN1, ALT_2, RX_SIZE_256, TX_SIZE_16);/STM32_CAN Can0 (CAN1, ALT_2, RX_SIZE_256, TX_SIZE_16);\nSTM32_CAN Can1 (CAN2, ALT, RX_SIZE_256, TX_SIZE_16);/gI' speeduino/board_stm32_official.ino
fi

if ! grep -q '#include "core8.h"' speeduino/board_stm32_official.h; then
  gsed -i 's/#include <HardwareSerial.h>/#include <HardwareSerial.h>\n#include "core8.h"/gI' speeduino/board_stm32_official.h
fi

if ! grep -q '#include "core8.h"' speeduino/speeduino.ino; then
  gsed -i 's/int ignition1StartAngle = 0;/#include "core8.h"\n\nint ignition1StartAngle = 0;/gI' speeduino/speeduino.ino
fi

if ! grep -q 'runLoop();' speeduino/speeduino.ino; then
  gsed -i 's/LOOP_TIMER = TIMER_mask;/LOOP_TIMER = TIMER_mask;\nrunLoop();/gI' speeduino/speeduino.ino
fi

printf "Build for Core8 v2.3\n"

NOW=$(date +"%Y-%m-%d")

cd build

pio run -c core8_23.ini -t clean
pio run -c core8_23.ini

cd ..

FILE="core8_23_$NOW"

mkdir /Users/developer/Code/speeduino-opf/build/"$FILE"
cp /Users/developer/Code/speeduino-opf/build/.pio/build/CORE8/firmware.bin /Users/developer/Code/speeduino-opf/build/"$FILE"/
cp /Users/developer/Code/speeduino-opf/reference/speeduino.ini /Users/developer/Code/speeduino-opf/build/"$FILE"/

zip -vr /Users/developer/Code/speeduino-opf/build/"$FILE"/"$FILE".zip /Users/developer/Code/speeduino-opf/build/"$FILE" -x "*.DS_Store"
cp /Users/developer/Code/speeduino-opf/build/"$FILE"/"$FILE".zip /Users/developer/Library/CloudStorage/GoogleDrive-b.brazdziunas@gmail.com/My\ Drive/Speeduino/core8/

rm -R "$FILE"
rm "$FILE".zip

# pio run -c core8_24c.ini
# pio run -c core8_24d.ini
# pio run -c core8_24_mercedes_v8.ini

cp build/backup/board_stm32_official.h speeduino/board_stm32_official.h 
cp build/backup/board_stm32_official.ino speeduino/board_stm32_official.ino 
cp build/backup/speeduino.ino speeduino/speeduino.ino 

rm build/backup/board_stm32_official.h 
rm build/backup/board_stm32_official.ino 
rm build/backup/speeduino.ino 

rm -R speeduino/src/LPS22HH
rm -R speeduino/src/LPS25HB
rm speeduino/core8.h
rm speeduino/core8.ino

echo "All Done"
 
