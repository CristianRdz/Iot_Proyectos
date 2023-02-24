#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const int Trigger = 8;
const int Echo = 9;
const int sen = A0;
SoftwareSerial BTSerial(10, 11);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  dht.begin();
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
   // Enviamos la cabecera
  BTSerial.print("Distancia (cm),");
  BTSerial.print("Luz (%),");
  BTSerial.print("Humedad (%),");
  BTSerial.print("Temperatura (C),");
  BTSerial.println("");
}

void loop() {
  long p;
  long d;
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  p = pulseIn(Echo, HIGH);
  d = p / 2 * 0.034;
  int humedad = analogRead(sen);
  int h = map(humedad, 0, 1023, 100, 0);
  int luzLeida = analogRead(A1);
  int luz = map(luzLeida, 0, 1023, 0, 100);
  float t = dht.readTemperature();
 

  // Enviamos los valores
  BTSerial.print(d);
  BTSerial.print(",");
  BTSerial.print(luz);
  BTSerial.print(",");
  BTSerial.print(h);
  BTSerial.print(",");
  BTSerial.print(t);
  BTSerial.print(",");
  BTSerial.println("");
  
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }
  if (Serial.available()) {
   BTSerial.write(Serial.read());
  }

  delay(1000);
}
