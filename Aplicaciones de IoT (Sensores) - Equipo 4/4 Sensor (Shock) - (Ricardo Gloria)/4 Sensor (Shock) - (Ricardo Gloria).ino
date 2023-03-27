int shockSensor = 2;
bool alarmaChoque;

void setup() {
  // put your setup code here, to run once:
  pinMode(shockSensor, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  alarmaChoque = digitalRead(shockSensor);
  
  if (alarmaChoque == HIGH) {
    Serial.println("Choque");
  } 
}
