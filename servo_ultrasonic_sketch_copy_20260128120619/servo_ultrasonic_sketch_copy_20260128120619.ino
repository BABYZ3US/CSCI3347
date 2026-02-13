#include <Servo.h>
#define echo 6
#define trig 5

Servo servo;

void setup() {
  servo.attach(9);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned int distance = uss_pulse(10);
  float servo_angle = 6 * distance;
  servo.write(servo_angle);
  Serial.print("dist: ");
  Serial.print(distance);
  Serial.print("\n angle: ");
  Serial.print(servo_angle);
  Serial.print("\n");
  delay(200);

}

//time is in microseconds
double uss_pulse(unsigned int pulse_time) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(echo, HIGH);
  delayMicroseconds(pulse_time);
  digitalWrite(trig, LOW);
  
  long echo_time = pulseIn(echo, HIGH);

  return (echo_time * 17) / 1000;
}
