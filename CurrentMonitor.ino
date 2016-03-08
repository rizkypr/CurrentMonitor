
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


int inPin1 = 3;
int inPin2 = 4;
float current = 0;
int current2 = 0;


void setup()   {               
  
  Serial.begin(9600);
  pinMode(inPin1, INPUT_PULLUP);
  pinMode(inPin2, INPUT_PULLUP);
  
  
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
  // init done
  
  display.display();
  delay(500);

  }


void loop() {

  for(int i = 0; i < 500; i++) {
  current = current + ((analogRead(A1) * 0.0049) - 2.5) ;
  delay(1); }
  
  current = current /500;
  
  current = current / 0.1;
  current2 = current*1000;
  
 
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(24,20);
  display.setTextSize(1);
  display.setCursor(24,50);
  display.print(current);     
  display.display();
  delay(10);
    
}
