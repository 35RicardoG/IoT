int servo = 2;
int sensorButton = 13; 

void setup() {
  // put your setup code here, to run once:
  pinMode(servo, OUTPUT);
  pinMode(sensorButton, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Move the DC motor forward at maximum speed
  digitalWrite(servo, digitalRead(sensorButton));
}
