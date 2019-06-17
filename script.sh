#!/bin/bash
sudo chmod 777 /dev/ttyACM0 
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -o $1 $1.c   
avr-objcopy -O ihex -R .eeprom $1 $1.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:$1.hex