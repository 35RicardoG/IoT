#include <TM1651.h>

#define CLK 18    //pins definitions for TM1651 and can be changed to other ports       
#define DIO 2

TM1651 batteryDisplay(CLK, DIO);

#define CLK 5
#define DT 15
#define SW 4

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir = "";
unsigned long lastButtonPress = 0;


void setup(){
  Serial.begin(9600);
  batteryDisplay.init();
  batteryDisplay.set(2); //Fijar el brillo: 0---7
  pinMode(CLK,INPUT);
	pinMode(DT,INPUT);
	pinMode(SW, INPUT_PULLUP);
  lastStateCLK = digitalRead(CLK);
}

void loop(){
  currentStateCLK = digitalRead(CLK);

  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1) {
		// Si el estado DT es diferente la estado CLK entonces
		// el codificador esta girando en el sentido contrario a las agujas del reloj, por lo que disminuye
		if (digitalRead(DT) != currentStateCLK) {
			counter ++;
			currentDir ="CW";
      if(counter == 0) {
        batteryDisplay.displayLevel(0); //All off
      } else if (counter > 0 && counter <= 20) {
        batteryDisplay.displayLevel(1); //All off
      } else if (counter >= 21 && counter <= 40){
        batteryDisplay.displayLevel(2); //All off
      } else if (counter >= 41 && counter <= 60){
        batteryDisplay.displayLevel(3); //All off
	  	} else if (counter >= 61 && counter <= 80){
        batteryDisplay.displayLevel(4); //All off
	  	} else if (counter >= 81 && counter <= 100){
        batteryDisplay.displayLevel(5); //All off
	  	} else if (counter > 100){
        counter = 0;
        batteryDisplay.displayLevel(0);
      }
		}	
	}
  // Remember last CLK state
	lastStateCLK = currentStateCLK;

	// Put in a slight delay to help debounce the reading
	delay(1);
}
