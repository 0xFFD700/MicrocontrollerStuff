/*include and initialize bluetooth and LED strip*/
#include <SoftwareSerial.h>
SoftwareSerial BT(10,11);

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 6, NEO_GRB + NEO_KHZ800);

/*predefined colors + rainbowarray*/
uint32_t red = strip.Color(255, 0, 0); 
uint32_t orange = strip.Color(255, 128, 0);
uint32_t yellow = strip.Color(255, 255, 0);
uint32_t green = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t lilac = strip.Color(255, 0, 255);
uint32_t pink = strip.Color(255, 0, 128);
uint32_t white = strip.Color(255, 255, 255);
uint32_t off = strip.Color(0, 0, 0);
uint32_t rainbow[] = {
  red, orange, yellow, green, blue, lilac, pink, white};


void setup() {
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  BT.begin(9600);
  BT.println("Connected");
}

void loop() {
  if (BT.available() > 0) {
    executeCommand(readUserInput());
  }    
}

/*reads incoming serial user input*/
String readUserInput() {
  String text = BT.readString();
  text.toLowerCase();
  return text;
}

/*compares color or sets brightness*/
void executeCommand(String text) {
  if (isDigit(text.charAt(0)) && text.charAt(0) != '0') {
    strip.setBrightness(text.toInt());
    BT.println("Brightness set to " + text);     
  } 
  else if(text == "red"){
    setColorWholeStrip(red);
    BT.println("Red"); 
  } 
  else if(text == "orange") {
    setColorWholeStrip(orange);
    BT.println("Orange"); 
  }
  else if(text == "yellow") {
    setColorWholeStrip(yellow);
    BT.println("Yellow");
  }
  else if(text == "green") {
    setColorWholeStrip(green);
    BT.println("Green");
  }
  else if(text == "blue") {
    setColorWholeStrip(blue);
    BT.println("Blue"); 
  }
  else if(text == "lilac") {
    setColorWholeStrip(lilac);
    BT.println("Lilac"); 
  }
  else if(text == "pink") {
    setColorWholeStrip(pink);
    BT.println("Pink"); 
  }
  else if(text == "white") {
    setColorWholeStrip(white);
    BT.println("White"); 
  }
  else if(text == "off") {
     setColorWholeStrip(off);
    BT.println("Off"); 
  }
  else if (text == "rainbow") {
    rainbowColor(); 
    BT.println("Rainbow");
  }  
  else {
    BT.println("Invalid input");
  }
  strip.show();
}

/*sets all leds to chosen color*/
void setColorWholeStrip(uint32_t color) {
  for(int j = 0; j <= 60; j++) {
    strip.setPixelColor(j, color);
  }
}

/*rainbowColor*/
void rainbowColor() {
  int l = 0;
  for (int k = 0; k <= 60; k++) {
    strip.setPixelColor(k, rainbow[l]); 
    l++; 
    if (l == 8){
      l = 0;
    }
  }
}
