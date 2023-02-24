#include <SoftwareSerial.h>

SoftwareSerial esp8266(2, 3); // RX | TX

void setup()

{
  Serial.begin(9600);
  esp8266.begin(9600);
  Serial.println("");
  Serial.println("Recuerda cambiar el modo de comunicación como:  Ambos NL y CR En el monitor serial.");
  Serial.println("Listo");
  Serial.println("");
}

void loop()

{
  if (esp8266.available())
  {
    Serial.write(esp8266.read());
  }
  if (Serial.available())
  {
    esp8266.write(Serial.read());
  }
}
