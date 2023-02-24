const int Trigger = 9;
const int Echo = 10;

void setup() {
Serial.begin(9600);
pinMode(Trigger, OUTPUT);
pinMode(Echo, INPUT);
digitalWrite(Trigger, LOW);
}
void loop() {
long t;
long d;
digitalWrite(Trigger, HIGH);
delayMicroseconds(10);
digitalWrite(Trigger, LOW);
t = pulseIn(Echo, HIGH);
d = t / 2 * 0.034;
verificarDistancia(d);
}

void verificarDistancia(long distancia) {
if (distancia <= 20 && distancia < 21) {
  Serial.print("PELIGRO, objeto a ");
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println("");
} else if (distancia > 20 && distancia <= 300) {
  Serial.print("Objeto mas cercano a ");
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println("");
} else {
  Serial.println("FUERA DE RANGO");
}
}
