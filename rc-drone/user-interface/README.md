## Drone user interface overview

This GUI was written in C# using winforms for simplicity. It features a throttle bar, serial 
configuration parameters, pitch, yaw, and roll control (non-functional) and a message
send a receive display for debugging and data validation. 

## User guide
This software is intended to be used with arduino, such that confiuguration parameters populate 
when connected. If there is no arduino connected via USB-serial, an exception will occur. 
Assuming the arduino is  plugged in, to run this program one can simply press the green 
"configure" button as the default values work with the arduino. Pressing the ON/OFF button
enables the throttle bar, and dragging it will trigger events to transmit and receive data from
the arduino, which controls the BLDC through an ESC. Pressing the ON/OFF button again will
disable the throttle bar and turn off the motor. Pressing the close port button will safely 
stop serial transmission so the program can be closed.

## Future additions
The pitch, throttle, and yaw GUI elements will be functional after the flight software has been 
updated to handle 5 servos. One of the concerns here is computational capability for one arduino,
because 5 servos to control 3 degrees of freedom may clutter the transmissions or create 
cross-threading issues. I plan to add more modes like autopilot and landing, so the drone can
handle the rest of the flight at the push of a button. I also plan to add a camera feed element
into the GUI so controlling the drone is easier, because everything is relative to the same frame.
