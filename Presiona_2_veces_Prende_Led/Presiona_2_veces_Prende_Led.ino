const int push1 = 5;
const int push2 = 6;
const int push3 = 7;
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
int counter = 0;


void setup() {
  pinMode(push1, INPUT);
  pinMode(push2, INPUT);
  pinMode(push3, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //Se mostrara las veces que se ha presionado el boton
  if (digitalRead(push3) == HIGH) {
    counter++;
    Serial.println(counter);
    delay(500);
  }
  if (counter >= 2) {
    digitalWrite(LED1, HIGH);
    delay(500);
    digitalWrite(LED1, LOW);
    counter=0;
    Serial.println("Prendio el led");
  }
}