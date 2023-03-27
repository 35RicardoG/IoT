int value;
int pinCLK = 2;
int pinDT = 4;
int pinSW = 5;

int posicion = 0;
int pinCLK_Anterior = LOW;
int n = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinCLK, INPUT);
  pinMode(pinDT, INPUT);
  pinMode(pinSW, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  n = digitalRead(pinCLK);

  if ((pinCLK_Anterior == LOW) && (n == HIGH)) {
    if (digitalRead(pinDT) == LOW) {
      posicion--;
    } else {
      posicion++;
    }     

    Serial.println(posicion);
  }

  pinCLK_Anterior = n;

  if (digitalRead(pinSW) == LOW) {
    posicion = 0;
  }
}
