const int pinLED = 8;
const int btn1 = 6;
const int btn2 = 5;
const int btn4 = 4;
const int btn8 = 3;
int acum = 0;
boolean estadoBtn1= 0;
boolean estadoBtn2= 0;
boolean estadoBtn4= 0;
boolean estadoBtn8= 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn8, INPUT);
}

void loop() {
  delay(300);
  estadoBtn1 = digitalRead(btn1);
  estadoBtn2 = digitalRead(btn2);
  estadoBtn4 = digitalRead(btn4);
  estadoBtn8 = digitalRead(btn8);
  Serial.print("Boton1 :");
  Serial.println(estadoBtn1);
  Serial.print("Boton2 :");
  Serial.println(estadoBtn2);
  Serial.print("Boton4 :");
  Serial.println(estadoBtn4);
  Serial.print("Boton8 :");
  Serial.println(estadoBtn8);
  if (estadoBtn1  == HIGH) {
    acum = acum +1;
  }
  if (estadoBtn2  == HIGH) {
    acum = acum + 2;
  }
  if (estadoBtn4  == HIGH) {
    acum = acum + 4;
  }
  if (estadoBtn8  == HIGH) {
    acum = acum + 8;
  }
  Serial.print("Acum : ");
  Serial.print(acum);
  Serial.println(""); 
  delay(100);
  int temp= 15-acum;
  if(temp>0){
      Serial.print(temp);
      for(int i=0; i<temp; i++){
        digitalWrite(pinLED, HIGH);  
        delay(50);
        digitalWrite(pinLED, LOW);  
      }
  }
  acum=0;
  temp=0;
}
