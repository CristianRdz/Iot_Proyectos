const int sen = A0;
void setup() {
Serial.begin(9600);
}

void loop() {
int humedad = analogRead(sen);
int h = map(humedad, 0, 1023, 100, 0);
if (h <= 20 && h >= 0) {
Serial.print("Tienes que regar tu planta, tiene ");
Serial.print(h);
Serial.print("% de humedad ");
Serial.println("");
}else if (h > 20 && h < 60){
Serial.print("Humedad adecuada, tiene ");
Serial.print(h);
Serial.print("% de humedad ");
Serial.println("");
} else{
Serial.print("Planta recien regada, tiene ");
Serial.print(h);
Serial.print("% de humedad ");
Serial.println("");
}
}
