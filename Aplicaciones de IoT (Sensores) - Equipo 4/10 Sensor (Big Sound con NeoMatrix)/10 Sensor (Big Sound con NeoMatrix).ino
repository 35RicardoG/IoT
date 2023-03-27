#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_GFX.h>

#define PIN 13

int sensor = 2;
int sensorValue;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(10, 8, 3, 1, PIN,
  NEO_TILE_TOP   + NEO_TILE_LEFT   + NEO_TILE_COLUMNS   + NEO_TILE_PROGRESSIVE +
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB + NEO_KHZ800);

const uint16_t colors[] = {matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255)};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);
}

int x = matrix.width();
int pass = 0;

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensor);
  Serial.println(sensorValue);
  delay(200);
  
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print("Ruido");
  matrix.print("");
  matrix.print(sensorValue);
  
  if(--x < -100) {
    x = matrix.width();
    if(++pass >= 1) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  
  matrix.show();
  delay(100);
}


