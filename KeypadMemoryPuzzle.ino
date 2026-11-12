//setup

//matrix membrane 4x3 keypad
//black and red cable not connected
//white cable 3
//gray cable 8
//purple cable 4
//blue cable 5
//green cable 2
//yellow cable 6
//orange cable 7

//lcd
//lcd gnd to gnd
//lcd vcc to 5V
//lcd sda to a4
//lcd scl to a5


#include <Keypad.h>
#include <Wire.h>
#include <LCDIC2.h>

LCDIC2 lcd(0x27, 16, 2);

const byte ROWS = 4; // Define the number of rows on the keypad
const byte COLS = 3; // Define the number of columns on the keypad
char keys[ROWS][COLS] = { // Matrix defining character to return for each key
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pins (R0-R3) of the keypad
byte colPins[COLS] = {4, 3, 2}; //connect to the column pins (C0-C2) of the keypad
//initialize an instance of class
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//all possible keys
const char keysArr[13] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#'};
int randNum;


void setup(){

  Serial.begin(9600);
  randomSeed(analogRead(0));
  lcd.begin();
  //generate 3 random numbers and store in array
  for (int i = 0; i < 3; i++){
    randNum = random(0,12);
    lcd.setCursor(i,0);
    lcd.print(keysArr[randNum]);
    delay(1000);
  }
}

void loop(){
  char key = keypad.getKey();
  

  if (key){     // If key is pressed, send it to the Serial Monitor Window
    Serial.println(key);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(key);
  }
  delay(50);
}
 