//const int Relay = 1;
void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
}

void loop() {
  digitalWrite(3, LOW);

}
