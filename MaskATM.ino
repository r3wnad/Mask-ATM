
#include <Keypad.h>

#include <LiquidCrystal.h>
#include <SR04.h>

#include "SR04.h"
#define TRIG_PIN 24
#define ECHO_PIN 22
//#define TRIG_PIN 3
//#define ECHO_PIN 2


// http://www.arduino.cc/en/Tutorial/LiquidCrystal
// */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int pirPin = 6; // Input for HC-S501
int ledPin =13 ;// led triggered by the motion
int buzzer= 13;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
int remMasks = 100;
String Remmasks = String(remMasks);
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {31, 32, 33, 39}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {41, 43, 45, 49}; //connect to the column pinouts of the keypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);


void setup() {
   Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  pinMode(buzzer, OUTPUT); 
  pinMode(ledPin, OUTPUT);
  
 digitalWrite(ledPin, LOW);
  
  
}

void loop() {

  //lcd.setCursor(0, 1);
  int entry = 0;
  int takenMasks = 0;
  lcd.setCursor(0, 0);
  lcd.print("Masks left: ");
  lcd.setCursor(0, 1);
  lcd.print(Remmasks);
  long a = sr04.Distance();
  
  if (a<7){
    digitalWrite(buzzer,HIGH);
    while (entry==0){
      
     char customKey = customKeypad.getKey();
     if (customKey=='0')
      takenMasks = takenMasks*10+0;
     if (customKey=='1')
      takenMasks = takenMasks*10+1;
     if (customKey=='2')
      takenMasks = takenMasks*10+2;
     if (customKey=='3')
      takenMasks = takenMasks*10+3;
     if (customKey=='4')
      takenMasks = takenMasks*10+4;
     if (customKey=='5')
      takenMasks = takenMasks*10+5;
     if (customKey=='6')
      takenMasks = takenMasks*10+6;
     if (customKey=='7')
      takenMasks = takenMasks*10+7;
     if (customKey=='8')
      takenMasks = takenMasks*10+8;
     if (customKey=='9')
      takenMasks = takenMasks*10+9;
     if (customKey=='C')
      takenMasks = takenMasks/10;
     if (customKey=='A'){
      if (takenMasks>remMasks){
      lcd.setCursor(0,0);
      lcd.print("Excess amount");
      delay(2000);
      takenMasks = 0;
      }
      entry = 1;
      break;}
     else{
      lcd.setCursor(0,0);
      lcd.print("Enter 0-9");
      lcd.setCursor(0,1);
      lcd.print("               ");
      //break;
     }
    String TakenMasks = String(takenMasks);
    lcd.setCursor(0, 1);
    lcd.print(TakenMasks);
    }
    Serial.println(takenMasks);
    digitalWrite(buzzer,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Taken masks: ");
    lcd.setCursor(0,1);
    String TakenMasks = String(takenMasks);
    lcd.print(TakenMasks);
    delay(3000);
    }
  remMasks = remMasks-takenMasks;
  Remmasks = String(remMasks);
}
