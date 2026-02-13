#define X_AXIS_PIN A0 //analog 0-1023
#define Y_AXIS_PIN A1 //analog 0-1023
#define SWITCH_PIN 2  //digital
#define POS_X_LED_PIN 3 //digital
#define POS_Y_LED_PIN 4//digital
#define NEG_X_LED_PIN 5//digital
#define NEG_X_LED_PIN 6//digital

void setup() {
  // put your setup code here, to run once:
  pinMode(X_AXIS_PIN, INPUT);
  pinMode(Y_AXIS_PIN, INPUT);
  pinMode(SWITCH_PIN, INPUT);
  digitalWrite(SWITCH_PIN, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(X_AXIS_PIN);
  int y = analogRead(Y_AXIS_PIN);
  bool switch_pressed = !(digitalRead(SWITCH_PIN)); // invert because HIGH = switch not pressed

  if (switch_pressed) {
    digitalWrite(POS_X_LED_PIN, 1);
    digitalWrite(POS_Y_LED_PIN, 1);
    digitalWrite(NEG_X_LED_PIN, 1);
    digitalWrite(NEG_Y_LED_PIN, 1);
  }
  else {
    
  }

  Serial.print("\nx: ");
  Serial.print(x);
  Serial.print("\ny: ");
  Serial.print(y);
  Serial.print("\n");
  Serial.print("Switch pressed: ");
  Serial.print(switch_pressed);
}
