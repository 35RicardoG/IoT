const int sensorPin = 2;
int value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(sensorPin);
  if(value <= 4000) {
    Serial.println("Luz");
  }
}
