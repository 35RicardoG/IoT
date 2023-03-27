#include <ESP32Servo.h>

Servo servo;
int pinServo = 13;
int sensorFlame = 2; //Inicializacion del sensor
int pinFlame; //Estado del sensor

void setup() {
  pinMode(sensorFlame, INPUT);
  Serial.begin(115200);
  servo.attach(pinServo, 500, 2500);
  servo.write(0);  
}

void loop() {
  pinFlame = digitalRead(sensorFlame);

  if (pinFlame == HIGH) {
    Serial.println("Fuego detectado");
    servo.write(90);
    delay(1000);
  } else {
    Serial.println("No hay fuego");
    servo.write(0);
    delay(1000);
  }

  delay(1000);
}
