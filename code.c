#include <Servo.h>

// Define the pins for the ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Define the pin for the servo motor
Servo servo;
const int servoPin = 3;

// Variables for calculating distance
long duration;
int distance;

void setup() {
  // Initialize the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Attach the servo motor
  servo.attach(servoPin);
  servo.write(0); // Initial position

  // Start the serial monitor
  Serial.begin(9600);
}

void loop() {
  // Send a 10µs pulse to the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the echo pin's pulse width
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor (optional)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If hand is detected within 10 cm, activate the servo
  if (distance <= 10 && distance > 0) {
    servo.write(90); // Push sanitizer pump
    delay(1000);     // Hold for a second
    servo.write(0);  // Reset servo to original position
  }

  delay(500); // Small delay to avoid rapid triggering
}
