#include "functions.h"

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
/*int SelectingMenu = true;
int scroll     = 0;
int button     = 0;
int menu       = 1;
int FunctionChoice;
float Answer;

/*==== Main Code ====================================================*/
void setup() 
{
  setting();
  intro();
  wait(1);
}//End void setup()

void loop() 
{   
   SelectingMenu = true;  
   while(SelectingMenu == true)
   {
    MenuChoice  = Menu();
    ElementChoice = Element();

    switch(MenuChoice)
    {
      case 0:
      {
        MenuChoice =  2;
        menu = 2;
        break;
      }
      case 1:
      {
        lcd.clear();
        lcd.print(menu0);
        delay(100);
        break;
      }
      case 2:
      {
        lcd.clear();
        lcd.print(menu1);
        delay(100);
        break;
      }
      case 3:
      {
        MenuChoice = 1;
        menu = 1;
        break;
      }
    }//End switch

    switch(ElementChoice)
    {
      
    }
   }//End while
}//End void loop()
