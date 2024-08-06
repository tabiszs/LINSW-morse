# LINSW-morse-transmitter-receiver
Program for laboratory no. 2 from Linux in Systems Embeded lecture.

Transmiter and revicer morse code with usage gpiod library.

# Environment
## Real
Program works on RapsberryPi4 with adapter.
https://gitlab.com/WZab/wz_edu_boards/-/tree/main/rpi4_adapter

## Virtual
Program works also on Virtual Machine with virtual adapter.
https://github.com/wzab/BR_Internet_Radio/tree/gpio_simple_2021.02
In this case it is needed to change gpiod pins.

# Logic
1. Type text to transmit
2. Transmit code via led on 24 pin.
3. Revice code from user via button on 10 pin.

# Bouncing
Program provide handling bouncing inside buttons. Bouncing time is set for 40ms.

# Morse Code
Program revice and transimit in MORSE-UNIT which is 1sec.
After 10sec waiting for change button state program close.

# Handling button
- When button is pressed then occured falling edge.
- When button is released then occured rising edge.
- When bouncing occures then is set bouncin timeout which is set again after changing edge in bouncing time.

# Click time
Bouncing time need to press button for more then 40ms. My experimets shows that quick clicking take only 25-50ms.
If you are really fast in transmitting morse code. Be careful!
