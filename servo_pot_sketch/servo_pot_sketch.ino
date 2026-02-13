#include <Servo.h>
#define echo
#define trig

Servo servo;

void setup() {
  servo.attatch(9);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned int distance = uss_pulse(10);
  float servo_angle = 6 * distance;
  servo.write(servo_angle);
  print("%d cm\n", distance);
  print("servo angle: %d", servo_angle);
  delay(400);

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
