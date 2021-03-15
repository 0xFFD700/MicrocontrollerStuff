//RFID
#include <SPI.h>
#include <RFID.h>
RFID rfid(10,9);

// LED
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 7, NEO_GRB + NEO_KHZ800);
uint32_t white = strip.Color(255, 255, 255);
uint32_t black = strip.Color(0, 0, 0);

int serNum[5];
int cards[][5] = {{136,4,172,172,140}};
boolean an = true;
bool access = false;


void setColor(uint32_t col) {
   for (int k = 0; k <= 60; k++) {
    strip.setPixelColor(k, col);
    Serial.println(k);
  }
  delay(200);
  }

void setup(){

    //RFID
    Serial.begin(9600);
    SPI.begin();
    rfid.init();
    
  strip.begin();
  strip.setBrightness(50);
  setColor(white);
  strip.show();
}

void loop(){
    
    if(rfid.isCard()){
    
        if(rfid.readCardSerial()){
            Serial.print(rfid.serNum[0]);
            Serial.print(" ");
            Serial.print(rfid.serNum[1]);
            Serial.print(" ");
            Serial.print(rfid.serNum[2]);
            Serial.print(" ");
            Serial.print(rfid.serNum[3]);
            Serial.print(" ");
            Serial.print(rfid.serNum[4]);
            Serial.println("");
            
            for(int x = 0; x < sizeof(cards); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] != cards[x][i]) {
                      access = false;
                      break;
                  } else {
                      access = true;
                  }
              }
              if(access) break;
            }
        }
        
       if(access){
           Serial.println("Welcome Jenny!");

           if (an){ 
            
           strip.setBrightness(0);
           setColor(black);
           strip.show();
            an = false;
            
            } else {
              strip.setBrightness(50);
               setColor(white);
           strip.show();
            an = true;
              } 
           access = false;
           
      } else {
           Serial.println("Not allowed!"); 
       }      
    }
        
    rfid.halt();
}




