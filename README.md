# Koala Bear Project
Personal notes: 
compiling:  
arduino-cli compile --fqbn arduino:avr:uno .
arduino-cli compile --fqbn arduino:avr:nano .

uploading:  
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno .
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:cpu=atmega328 .

checking:
arduino-cli board list  

## Functions  
This bear will sit and detect how far away you are from it, and if that distance doesn't change within a certain amount of time, it will yell at you so that you would go touch grass.

## Purpose
I noticed that a majority of my time is spent at the computer whether it is studying, gaming, homework, or rotting. Having a built in timer that I dont have to set every time would be dope. 

## Arduino parts (so far)
Uno R3 (later nano)
power supply
ultrasonic sensor
LED's
