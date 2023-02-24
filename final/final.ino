const int Trigger = 9;
  const int Echo = 10;
  const int buzzer =2;
  const int led1=3;
  const int led2=4;
void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(Echo, INPUT);
  
  digitalWrite(Trigger, LOW);
}

void loop() {
  long t;
  long d;
  digitalWrite(Trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger,LOW);
  t=pulseIn(Echo,HIGH);
  d=t/59;
  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.print("cm");
  Serial.println();
  verificarDistancia(d);
  delay(100);
}
void verificarDistancia(long distancia){
  // igual a 50 y mayor a 30
if (distancia <= 50 && distancia > 30){
  digitalWrite(led1,HIGH);
  digitalWrite(buzzer,LOW);
  digitalWrite(led2,LOW);
  Serial.println("Hay un objeto entre a 50cm y 31cm");
  // menor o igual a 30 y mayor a 20
  } else if (distancia <= 30 && distancia > 20){
    digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(buzzer,LOW);
  Serial.println("Hay un objeto entre a 30cm y 21cm");
  // menor o igual a 20 
  } else if (distancia <= 20){
    digitalWrite(buzzer,HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
  Serial.println("Hay un objeto a menos o a 20cm");
  } else {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(buzzer,LOW);
  }
}
