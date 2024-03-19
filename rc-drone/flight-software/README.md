## Drone flight software overview

This drone control software was written in arduino C++. It currently features different modes
for programming the electronic speed controller (ESC) to either test the BLDC or prepare it
for intense flight use.

## User guide
This software is more hardware intensive and requires good wiring to run correctly. The three
different arduino files serve different purposes and different methods of doing so. The code
loops after pushing it to the arduino code and waits for input from the GUI. Please look
at the individual arduino files for wiring guides to ensure clean data TX and RX.

## Future additions
The pitch, throttle, and yaw controls are crucial for a fully functioning drone, and they
will be implemented via servos. The same libraries will be used, with slightly different code
due to how servos differ from BLDC's. A CRC is also going to be implemented for data
protection as there are currently cross threading issues between the arduino and GUI.
