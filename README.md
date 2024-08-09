# Automated-hand-sanitizer-using-Arduino

Connect the Trig pin of the HC-SR04 to Arduino pin 9.
Connect the Echo pin of the HC-SR04 to Arduino pin 10.
Connect VCC and GND of the sensor to 5V and GND of Arduino, respectively.
Connect the control pin of the servo to Arduino pin 3.
Connect the servo's power and ground pins to the 5V and GND of Arduino, respectively.
This code will trigger the servo motor to move when a hand is detected within 10 cm of the sensor, simulating the pressing of a sanitizer pump. Adjust the distance and delays as needed for your specific setup.

Ultrasonic Sensor (HC-SR04): It sends out a sound wave, and the echo is detected when it bounces back. The time it takes for the sound to return is used to calculate the distance.
Servo Motor (SG90): The servo motor moves the pump mechanism of the hand sanitizer bottle when the hand is detected within a certain distance (10 cm in this example).
