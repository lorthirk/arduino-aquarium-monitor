#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(5);
DallasTemperature temp(&oneWire);

float tc, tf;

void setup() {
  Serial.begin(9600);
  temp.begin();
}

void loop() {
  temp.requestTemperatures();
  tc = temp.getTempCByIndex(0);
  tf = temp.toFahrenheit(tc);

  Serial.print(tc);
  Serial.print(" C \t");
  Serial.print(tf);
  Serial.println(" F");
  delay(1000);
}
