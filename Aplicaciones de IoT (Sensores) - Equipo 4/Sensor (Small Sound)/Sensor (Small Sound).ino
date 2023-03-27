int analogPin = 35; 
int digitalPin = 2; 
  
void setup() {
  pinMode(analogPin, INPUT);
  pinMode(digitalPin, INPUT);
       
  Serial.begin(115200);  
}
  
void loop() {
  float analogValue;
  int digitalValue;
    
  //Se leen los valores de corriente, se convierten en el valor de tensión...
  analogValue = analogRead(analogPin) * (5.0 / 1023.0); 
  digitalValue = digitalRead(digitalPin);
    
  //... y emetido en este punto.
  Serial.print("Valor de tensión analógica: ");  
  Serial.print(analogValue, 4);   
  Serial.print("V, ");
  Serial.print("Valor limite: ") ;
  
  if (digitalValue == 1) {
    Serial.println("alcanzado");
  } else {
    Serial.println("aun no se ha alcanzado");
  }
  
  Serial.println( " ----------------------------------------------------------------") ;
  delay(1000) ;
}