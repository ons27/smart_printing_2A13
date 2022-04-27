#include <LiquidCrystal.h>

#include <Keypad.h>

#include <LiquidCrystal_I2C.h>//bibliotheque de ecran
#include<EEPROM.h> 


LiquidCrystal_I2C lcd(0x27,16,2); //initialisation de ecran 0*27 l'adressage analogique a4 et a5

char password[4];//taille de tableau pour saisir password
char data;


char array1[]="by rahma and haythem"; //the string to print on the LCD
int tim = 500; //the value of delay time


char initial_password[4];

int i=0;

char key_pressed=0;

const byte rows = 4; //taille clavier 4 ligne

const byte columns = 4; // taille clavier 4 colone 
//definition du clavier
char hexaKeys[rows][columns] = {

{'1','2','3','A'},

{'4','5','6','B'},

{'7','8','9','C'},

{'*','0','#','D'}

};

byte row_pins[rows] = {A0,A1,A2,A3};

byte column_pins[columns] = {5,4,3,2};   
//creation instance 
Keypad keypad_key = Keypad( makeKeymap(hexaKeys), row_pins, column_pins, rows, columns);

int t =1;


void setup()//config en arduino

{

  Serial.begin(9600);
 

    lcd.init(); //initialize the lcd
  lcd.backlight(); //ouvrir la limiere

   lcd.setCursor(15,0); // cursseur
  for (int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++)
  {
    // debut de l'affichage
    lcd.scrollDisplayLeft(); //animation
    lcd.print(array1[positionCounter1]); // afficher sur lcd
    delay(tim); //wait for 250 microseconds
  }
  lcd.clear(); //suuprimer l'ecran
  



}




void loop()

{

    if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
        if(data=='1') //si le caractère lu est égale à 1
        {
          lcd.print("Welcome Ali");
        }
        else if(data=='2'){
        lcd.print("Welcome Fatma");
        }else if(data=='3'){
        lcd.print("Welcome Nour");
        }else if(data=='4'){
        lcd.print("Welcome Haithem");
        }else if(data=='5'){
        lcd.print("Welcome Rahma");
        }
    }

  key_pressed = keypad_key.getKey();

 

  if (key_pressed)

  {

    password[i++]=key_pressed;//remplir le tableau
  

    lcd.print(key_pressed);// affichage

      }

  if(i==4)

  {

    delay(200);

    for(int j=0;j<4;j++)

      initial_password[j]=EEPROM.read(j);//lire a partir du clavier
      
      
   

    if(!(strncmp(password, "0001",4)))

    {
      if ( t){
         Serial.print("1");
         t =0;
      }

      lcd.clear();

      lcd.print("Welcome Ali");

      

      delay(2000);
   


    }

    else   if(!(strncmp(password, "0002",4)))

    {
        
      if ( t){
         Serial.print("2");
         t =0;
      }

     lcd.clear();

     lcd.print("Welcome Fatma");

      

      delay(2000);
      



    }



 else   if(!(strncmp(password, "0003",4)))

    {
         
      if ( t){
         Serial.print("3");
         t =0;
      }

     lcd.clear();

      lcd.print("Welcome Nour");

      

      delay(2000);
      



    }
      else   if(!(strncmp(password, "0004",4)))

    {
         
      if ( t){
         Serial.print("4");
         t =0;
      }

      lcd.clear();

      lcd.print("Welcome Haythem");

      

      delay(2000);
      



    }
      else   if(!(strncmp(password, "0005",4)))

    {
      
      if ( t){
         Serial.print("5");
         t =0;
      }

      lcd.clear();

      lcd.print("Welcome Rahma");

      

      delay(2000);
      



    }


  

    else

    {

Serial.print("0");



      lcd.clear();

      lcd.print("Wrong Password");

     

    
      delay(2000);
     



    }

  }

}
