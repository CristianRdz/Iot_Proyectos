const int LED1 = 2;
const int LED2 = 3;
int repeat = 1;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  if (repeat == 10) {
    digitalWrite(LED1, HIGH);
    delay(100);
    digitalWrite(LED1, LOW);
    delay(100);
    digitalWrite(LED2, HIGH);
    delay(100);
    digitalWrite(LED2, LOW);
    delay(100);

  } else {
    int i = 0;
    while (i != repeat) {
      digitalWrite(LED1, HIGH);
      delay(100);
      digitalWrite(LED1, LOW);
      delay(100);
      i = i + 1;
    }
    int j = 0;
    while (j != repeat) {
      digitalWrite(LED2, HIGH);
      delay(100);
      digitalWrite(LED2, LOW);
      delay(100);
      j = j + 1;
    }
    repeat = repeat + 1;
  }
}