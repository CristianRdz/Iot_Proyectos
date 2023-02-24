#include <Servo.h>

Servo servoMotor;
void setup() {
  Serial.begin(9600);
  servoMotor.attach(9);

}

void loop() {
  delay(1000);
  int luzLeida = analogRead(A0);
  int luz = map(luzLeida, 0, 1023, 0, 100);
  Serial.print(luz);
  Serial.print(" % LUZ ");
  delay(500);
  servoMotor.write(60);
  if (luz <= 0) {
    Serial.print("Esta a 0°");
    servoMotor.write(0);
  } else if (luz <= 20){
    servoMotor.write(25);
    Serial.print("Esta a 25°");
  } else if (luz <= 30){
    servoMotor.write(50);
    Serial.print("Esta a 50°");
  }else if(luz <= 40){
    servoMotor.write(75);
    Serial.print("Esta a 75°");
  }else if (luz <= 50 ){
    servoMotor.write(100);
    Serial.print("Esta a 100°");
  }else{
    servoMotor.write(150);
    Serial.print("Esta a 150°");
  }
  Serial.println("");
}
