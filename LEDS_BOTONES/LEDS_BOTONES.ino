const int btn1 = 2;
const int btn2 = 3;
const int btn4 = 4;
const int btn8 = 5;
const int led1 = 7;

void setup() {
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn8, INPUT);
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sumatoria = 0;
  delay(500);
  if (digitalRead(btn1) == HIGH) {
    sumatoria += 1;
  }
  if (digitalRead(btn2) == HIGH) {
    sumatoria += 2;
  }
  if (digitalRead(btn4) == HIGH) {
    sumatoria += 4;
  }
  if (digitalRead(btn8) == HIGH) {
    sumatoria += 8;
  }
  if (sumatoria > 0) {
    Serial.println("Suma total: " + String(sumatoria));
  }
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    if (input.startsWith("Enciendete: ")) {
      int numero = input.substring(12).toInt();
      for (int i = 0; i < numero; i++) {
        digitalWrite(led1, HIGH);
        delay(500);
        digitalWrite(led1, LOW);
        delay(500);
      }
    }
  }
}