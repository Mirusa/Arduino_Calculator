#include <LiquidCrystal.h>
#include <Wire.h>
#include <String.h>
#include <math.h>

LiquidCrystal lcd(8,9,4,5,6,7);

//Pin
#define BUTTON_PIN   A0

//Return Values for ReadButtons()
#define BUTTON_NONE   0
#define BUTTON_RIGHT  1
#define BUTTON_UP     2
#define BUTTON_DOWN   3
#define BUTTON_LEFT   4
#define BUTTON_SELECT 5

//Variables
byte buttonPressed  = false;
byte buttonReleased = false;
byte buttonWas      = BUTTON_NONE;

int SelectingMenu  = true;
int scrollMenu     = 0;
int scrollElement  = 0;
int button         = 0;
int menu           = 1;
int element        = 0;
int MenuChoice;
int ElementChoice;
int sus = 0;
float Answer;

String menu0 = "0123456789";
String menu1 = "+-*/%=";

/*==== Character ================================================*/
byte susr[8] = {
  B00000,
  B00000,
  B01110,
  B11000,
  B11110,
  B11110,
  B01010,
  B00000
};

/*==== Basic Functions ================================================*/
void setting()
{
  //pro-process
  Serial.begin(9600);                  //Serial port set at 9600
  Serial.println("Preparing...");//Serial confirm
  pinMode(BUTTON_PIN,INPUT);           //ensure A0 is an input
  digitalWrite(BUTTON_PIN,LOW);        //ensure pullup is off on A0
  lcd.begin(16,2);
  lcd.createChar(0,susr);
}//End void setting()

void intro() 
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Mirusa's");
  delay(500);
  lcd.setCursor(5,1);
  lcd.print("Calculator");
  delay(500);
  lcd.clear();
  return;
}//End void intro()

void wait(int temp) {
  for(int i=0; i<=temp; i++){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Wait A Second");
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
  }
}//End void wait()

/*==== Functions ======================================================*/
int ReadButtons() //read button
{
  //Variables
  unsigned int buttonVoltage;
  byte button = BUTTON_NONE; //return no button pressed

  //Read A0 signal
  buttonVoltage = analogRead(BUTTON_PIN);

  //sense if buttonVoltage fit the keyValues
  if( buttonVoltage<60 )
  {
    button = BUTTON_RIGHT;
  }
  else if( (buttonVoltage >=  60) && (buttonVoltage <= 200) ) 
  {
    button = BUTTON_UP;
  }
  else if( (buttonVoltage >= 200) && (buttonVoltage <= 400) )
  {
    button = BUTTON_DOWN;
  }
  else if( (buttonVoltage >= 400) && (buttonVoltage <= 600) )
  {
    button = BUTTON_LEFT;
  }
  else if( (buttonVoltage >= 600) && (buttonVoltage <= 800) )
  {
    button = BUTTON_SELECT;
  }  

  //see if ther buttons are pressed or released
  if( (buttonWas == BUTTON_NONE) && (button != BUTTON_NONE) )//Pa.(N) Pre.(Y)
  {
    buttonPressed  = true;
    buttonReleased = false;
  }
  if( (buttonWas != BUTTON_NONE) && (button == BUTTON_NONE) )//Pa.(Y) Pre.(N)
  {
    buttonPressed  = false;
    buttonReleased = true;
  }

  //save the lastest button value
  buttonWas = button;

  return button;
}//End byte ReadButtons()

int Menu()//select meuns
{
  button = ReadButtons();

  if(buttonPressed == true)
  {
    scrollMenu = button;
    buttonPressed = false;
  }
  if(buttonReleased == true)
  {
    buttonReleased = false;
    switch(scrollMenu)
    {
      case BUTTON_UP:
      {
        menu--;
        break;
      }
      case BUTTON_DOWN:
      {
        menu++;
        break;
      }
    }//End switch
  }//End if buttonReleased...
  return menu;
}

int Element()
{
  button = ReadButtons();

  if(buttonPressed == true)
  {
    scrollElement = button;
    buttonPressed = false;
  }
  if(buttonReleased == true)
  {
    buttonReleased = false;
    switch(scrollElement)
    {
      case BUTTON_LEFT:
      {
        element--;
        break;
      }
      case BUTTON_RIGHT:
      {
        element++;
      }
      case BUTTON_SELECT:
      {
        break;
      }
    }//End switch
  }//End if buttonReleased
  return element;
}//End int Element()
 
int limit()
{

}

int cursor()
{
    lcd.setCursor(element,0);
    lcd.write(sus);
    delay(100);
}