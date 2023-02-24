const int sen = A0;
const int luzPresente = A1;
const int Trigger = 9;
const int Echo = 10;
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
  pinMode(LED1, OUTPUT); //VERDE
  pinMode(LED2, OUTPUT); //AMARILLO
  pinMode(LED3, OUTPUT); //ROJO
}

void loop() {
  int humedad = analogRead(sen);
  int h = map(humedad, 1018, 1021, 100, 0);
  int luzLeida = analogRead(luzPresente);
  int luz = map(luzLeida, 0, 1023, 0, 100);
  long t;
  long d;
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH);
  d = t / 2 * 0.034;
  verificarDistancia(d);
  verificarLuz(luz,h);

}
void verificarDistancia(long distancia) {
  if (distancia <= 19 && distancia < 20) {
    Serial.print("Esta en zona roja ");
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);
  } else if (distancia >= 20 && distancia <= 40) {
    Serial.print("Esta en zona amarilla ");
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW);
  } else {
    Serial.print("Esta en zona verde ");
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
  }
    Serial.print(distancia);
    Serial.print(" cm | ");
    Serial.println("");
}

void verificarLuz(int luz, int humedad) {
  if (luz <= 10 && luz < 11) {
    Serial.print("Hay poca luz ");
    Serial.print(luz);
    Serial.print("% Lúz | ");
    if (humedad <= 34 && humedad >= 0) {
      Serial.print("Se requiere riego, regar ahora mismo ");
    } else {
      Serial.print("Riego adecuado ");   
    }
  } else {
    Serial.print("Hay mucha luz ");
    Serial.print(luz);
    Serial.print("% Lúz | ");
    if (humedad <= 34 && humedad >= 0) {
      Serial.print("Se requiere riego, riegue en la noche ");
    } else {
      Serial.print("Riego adecuado ");
    }
    
  }
  Serial.print(humedad);
  Serial.print("% Humedad | ");
}
