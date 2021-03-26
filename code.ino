#include <HCSR04.h>
#include <Keypad.h>
#define echoPin 22// mask picking
#define trigPin 24
#define echoPin2 3//motion sensing
#define trigPin2 2

// include the library code:
#include <LiquidCrystal.h>
//********************************************************************
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int red=13 ;// led triggered by the motion
int green = 5;//mask picked
int buzzer= 13;
int distance;
int motion;
int duration;
int duration2;
//lcd initializations
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {31, 32, 33, 39}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {41, 43, 45, 49}; //connect to the column pinouts of the keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); 

// int facemasks
int facemask = 0;
int manufacturer =0;
 
 void setup() 
   {
          Serial.begin(9600);
  
           pinMode(trigPin,OUTPUT);
            pinMode (echoPin, INPUT);
             pinMode(trigPin2,OUTPUT);
              pinMode (echoPin2, INPUT);
  // set up the LCD's number of columns and rows:
       lcd.begin(16, 2);
       pinMode(buzzer, OUTPUT); 
        pinMode(red, OUTPUT);
         pinMode(green, OUTPUT);
         
   }

void loop()
{
//*************************************************
//case 1: when there is no face mask (intialization)
 digitalWrite(red,LOW);
 digitalWrite(green, LOW);
  int fm_temp = 0;
  while(facemask==0)
     {
       lcd.setCursor(0,0);
         lcd.print("Number of mask:");
           lcd.setCursor(0,1);
             lcd.print("Max 100: ");

//input number of face mask

             char key = kpd.getKey();
            if(key){
            if(key == '0') fm_temp = fm_temp * 10 + 0;
            if(key == '1') fm_temp = fm_temp * 10 + 1;
            if(key == '2') fm_temp = fm_temp * 10 + 2;
            if(key == '3') fm_temp = fm_temp * 10 + 3;
            if(key == '4') fm_temp = fm_temp * 10 + 4;
            if(key == '5') fm_temp = fm_temp * 10 + 5;
            if(key == '6') fm_temp = fm_temp * 10 + 6;
            if(key == '7') fm_temp = fm_temp * 10 + 7;
            if(key == '8') fm_temp = fm_temp * 10 + 8;
            if(key == '9') fm_temp = fm_temp * 10 + 9;
            if(key == 'C') fm_temp = fm_temp / 10;

         lcd.setCursor(9,1);
           lcd.print(fm_temp);
             lcd.print(" ");
             }
//once you press Enter (D) After refilling masks
      if(key == 'D')
        { 
          if(fm_temp > 100)
            { 
              facemask = -1;
            }
          else
             {
               facemask = fm_temp;
             }
        fm_temp = 0;
       } 
       if (key == 'A')
       {
        manufacturer=1;
        }
     } 
 //*********************************************************   
//if number exceeds 100, reset facemask to -1
    if(facemask== -1)
       {
       lcd.clear(); 
        lcd.setCursor(0,0);
         lcd.print("Invalid Entry    ");
            lcd.setCursor(0,1);
              lcd.print("                          ");
                delay (2000);
                lcd.clear();
                facemask=0;
                 
        }
//************************************************************
//display of the current amount of masks
         
          lcd.setCursor(0,0);
           lcd.print("Current amount:");
            lcd.setCursor(0,1);
              lcd.print(facemask);  
                lcd.print("             ");
             
//***********************************************************        
//when there is one or more face mask and motion sensor triggered
//***********************************************************       
           
while(facemask>1)
{

//ultrasonic sensor for motion sensing
digitalWrite(trigPin2, LOW);
            delayMicroseconds(2);
              digitalWrite(trigPin2, HIGH);
               delayMicroseconds(10);
                 digitalWrite(trigPin2, LOW);
 

  duration2= pulseIn(echoPin2, HIGH);
  motion= duration2 * 0.034 / 2;
    Serial.print( "Motion: ");
            Serial.print( motion);
               Serial.println ("cm");

//  int newmotion;
//digitalWrite (red,HIGH);

//ultrasonic sensor for mask pick
digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
              digitalWrite(trigPin, HIGH);
               delayMicroseconds(10);
                 digitalWrite(trigPin, LOW);
 

  duration= pulseIn(echoPin, HIGH);
  distance= duration * 0.034 / 2;

          Serial.print( "Distance: ");
            Serial.print( distance);
               Serial.println ("cm");  
 //digitalWrite(red,HIGH);

if (motion<10)
{
  digitalWrite(red,HIGH);
  if (distance<5)
  {
   digitalWrite (green,HIGH);
        facemask--;
        delay (500);
         lcd.setCursor(0,0);
          lcd.print("current amount :");
            lcd.setCursor(0,1);
             lcd.print(facemask);  
                lcd.print("             ");
           //   newmotion=0;
  }
  }
  
   //case 3: Mask is picked so reduce by one
   
      
              else if (distance >5 && motion>10)
                 {
                   digitalWrite (green,LOW);
                   digitalWrite (red, LOW);
                  
                  }
                  
               } 
//digitalWrite(red,LOW);
               
if (facemask==1)
 {
  lcd.clear();
  lcd.setCursor(0,0);
   lcd.print("Please...             ") ;
    lcd.setCursor(0,1);
     lcd.print("Refill the Masks");
    delay(2000);
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("Manufactured by           ") ;
    lcd.setCursor(0,1);
     lcd.print("GROUP B        ");
    delay(20000);
    lcd.clear();
    facemask=0;
   }
      
                   
         }
           
