#include <SoftwareSerial.h>
String server = "192.168.100.34";
int led=1;
SoftwareSerial esp8266(2, 3);
void setup() {
  Serial.begin(9600);   // monitor serial del arduino
  esp8266.begin(9600);  // baud rate del ESP8255

  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);

  sendData("AT+RST\r\n", 2000);                          // resetear módulo
  sendData("AT+CWMODE=1\r\n", 3000);                     // configurar como cliente
  sendData("AT+CWJAP=\"Totalplay-2.4G-9cd0\",\"tmVyxwb8jbuzUNcj\"\r\n", 8000);  //SSID y contraseña para unirse a red
  //AT+CWJAP="Totalplay-2.4G-9cd0","tmVyxwb8jbuzUNcj"
  sendData("AT+CIFSR\r\n", 5000);                        // obtener dirección IP
  sendData("AT+CIPMUX=1\r\n", 3000);                     // configurar para multiples conexiones
  sendData("AT+CIPSTART=\"TCP\",\""+server+"\",80",3000);//Hacemos la conexion con el servidor

}
void loop() {
  if (esp8266.available()) {
    Serial.write(esp8266.read());
  }
  if (Serial.available()) {
    esp8266.write(Serial.read());
  }
}
/*
Enviar comando al esp8266 y verificar la respuesta del módulo, todo esto dentro del tiempo timeout
*/
void sendData(String comando, const int timeout) {
  long int time = millis();  // medir el tiempo actual para verificar timeout

  esp8266.print(comando);  // enviar el comando al ESP8266

  while ((time + timeout) > millis())  //mientras no haya timeout
  {
    while (esp8266.available())  //mientras haya datos por leer
    {
      // Leer los datos disponibles
      char c = esp8266.read();  // leer el siguiente caracter
      Serial.print(c);
    }
  }
  return;
}