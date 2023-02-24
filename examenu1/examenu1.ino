#include <Servo.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
Servo servoMotor;
const int Trigger = 10;
const int Echo = 11;
const int sen = A0;
const int bomba = 3;
void setup() {
  Serial.begin(9600);
  dht.begin();
  servoMotor.attach(9);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
  pinMode(bomba, OUTPUT);
}

void loop() {
  long p;
  long d;
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  p = pulseIn(Echo, HIGH);
  d = p / 2 * 0.034;
  if (d < 30) {
    Serial.print(" Objeto a menos de 30 ");
    servoMotor.write(150);
    delay(1000);
    servoMotor.write(0);
  }

  int humedad = analogRead(sen);
  int h = map(humedad, 0, 1023, 100, 0);
  if (h < 50) {
    Serial.print(" Bomba activada ");
    digitalWrite(bomba, HIGH);
    delay(500);
    digitalWrite(bomba, LOW);
  }

  int luzLeida = analogRead(A1);
  int luz = map(luzLeida, 0, 1023, 0, 100);
  Serial.print(luz);
  Serial.print(" % LUZ ");
  float t = dht.readTemperature();
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("% Temperatura: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(d);
  Serial.print("cm ");
  Serial.print(h);
  Serial.print("% de humedad ");
  Serial.println("");
}
