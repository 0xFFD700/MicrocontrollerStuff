# 💡 LALL
<b>Control a LED strip from the terminal with Arduino & Bluetooth LE. </b><br>

### Components
* [Arduino Uno](https://www.arduino.cc/en/Main/arduinoBoardUno)
* [Digital RGB LED Strip - 60 LED](https://www.adafruit.com/product/1138)
* [HC-06 4 Pin Serial Wireless Bluetooth RF Transceiver Module](https://www.sunfounder.com/bluetooth-transceiver-module-hc-06-rs232-4-pin-serial.html)
* Smartphone with bluetooth terminal app

### Setup
1. Connect the LED strip to the Arduino 
   * GND --> GND
   * D0/D1 --> ~6
   * 5V --> 5V
2. Connect Bluetooth module
   * +5V --> 3,3V
   * GND --> GND
   * TX -> ~10
   * RX --> ~11
3. Upload [code](https://github.com/0xFFD700/LALL-terminal-based-/blob/master/ArduinoControllerCode/ArduinoControllerCode.ino) to the Arduino 
4. Start Bluetooth terminal and connect with the module

### Commands
#### (not case-sensitive)
:high_brightness: number(!0) to set brightness <br>
:rainbow: rainbow <br>
:black_circle: off <br>
:white_circle: white <br>
:cherries: red <br>
:tangerine: orange <br>
:lemon: yellow <br>
:green_apple: green <br>
:eggplant: blue <br>
:grapes: lilac <br>
:peach: pink <br>






