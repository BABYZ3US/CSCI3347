#include "DHT.h"

DHT dht(4, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  float celsius = dht.readTemperature();
  float farenheit = dht.readTemperature(true);
  float humidity = dht.readHumidity();
  float heatIndex = dht.computeHeatIndex(celsius, humidity, false);

  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.print("°C, ");
  Serial.print(farenheit);
  Serial.print("°F\n Humidity: ");
  Serial.print(humidity);
  Serial.print("%\n Heat Index: ");
  Serial.print("°C");

  delay(2000);
}
