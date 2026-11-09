The Equipment Health Monitor is a simple program for the Raspberry Pi that watches system memory. If usage goes over 80%, it turns on an LED connected to GPIO 17 as a warning. The setup uses a Raspberry Pi and an LED wired to GPIO pin 17 with a resistor. The code is written in C (src/main.c) and uses the pigpio library. It takes a percentage input, checks if it is over 80.0%, and sends a high or low signal to the pin. There is also a small Python helper file (src/led_indicator.py).

The program gets the memory percentage.
It checks if the number is greater than 80.
If it is, it sets GPIO 17 high to turn the LED on. If not, it keeps it off.
When you exit, it cleans up the pin so it doesn't stay on.
