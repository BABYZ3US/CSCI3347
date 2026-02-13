void setup() {
  // put your setup code here, to run once:
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int thrmst_res = analogRead(A5);
  Serial.print((thrmst_res / 1023.0));
  Serial.print("\n");
  delay(200);
}
