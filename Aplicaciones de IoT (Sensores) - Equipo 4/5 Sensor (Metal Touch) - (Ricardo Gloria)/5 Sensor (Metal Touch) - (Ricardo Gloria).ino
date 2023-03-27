const int sensorTouch = 4;
const int ledRed = 13;
int value;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorTouch, INPUT); 
  pinMode(ledRed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = digitalRead(sensorTouch);

  if (value = HIGH) {
    digitalWrite(ledRed, HIGH);
  } else {
    digitalWrite(ledRed, LOW);
  }
}
