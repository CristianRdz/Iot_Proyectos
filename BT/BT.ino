#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX

const int ledPin = 12; // Pin del LED

void setup() {
  pinMode(ledPin, OUTPUT);
  BT.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (BT.available()) {
    String message = "";

    while (BT.available()) {
      message += (char) BT.read();
      delay(10);
    }

    message.trim(); // Eliminamos espacios en blanco al principio y al final de la cadena
    Serial.println(message);

    if (message == "led1") {
      digitalWrite(ledPin, HIGH);
    } else if (message == "led0") {
      digitalWrite(ledPin, LOW);
    }
  }
}


