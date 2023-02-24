const int led = 13;
const int boton = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(boton) == HIGH) {
    digitalWrite(led, HIGH);
    Serial.println("LED encendido");
  }
  else {
    digitalWrite(led, LOW);
    Serial.println("LED apagado");
  }
}
