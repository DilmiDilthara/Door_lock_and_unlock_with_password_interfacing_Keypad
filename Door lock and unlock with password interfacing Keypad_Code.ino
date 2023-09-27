#include <LiquidCrystal.h>
#include<Keypad.h>

LiquidCrystal lcd(13,12,11,10,9,8);

char Keymap[4][3]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
  
  };

byte rowPins[4]={4,3,2,1};
byte colPins[4]={7,6,5};

Keypad numKeypad = Keypad(makeKeymap(Keymap),rowPins,colPins,4,3);

char password[4]={'1','9','9','8'};
char userpress[4];

void setup() {
 pinMode(0, OUTPUT);
 pinMode(A0, OUTPUT);
 pinMode(A1, OUTPUT);
 lcd.begin(16,2);
 lcd.clear();
 lcd.print("Press *");

}

void loop() {
  byte keyCount = 0;
  char keypress = numKeypad.getKey();
  if (keypress != NO_KEY){
    if(keypress == '*'){
      boolean a=1;
      lcd.clear();
      lcd.print("Enter password: ");
      lcd.setCursor(0,1);

      while(a){
        keypress = numKeypad.getKey();
        if (keypress != NO_KEY){
            userpress[keyCount] = keypress;
            lcd.print("*");
            keyCount++;
            if (keyCount==4) a=0;
        }
      }
    
    
  
  
    check_password();
    }
  }
}
void check_password(){
  byte b=0;
  for(int i=0; i<4; i++){
    if (userpress[i] == password[i]){
       b++;
    }
  }
   if (b==4){
      lcd.clear();
      lcd.print("Valid Password.");
      lcd.setCursor(0,2);
      lcd.print("Door Unlocked");
      digitalWrite(A0, 1);
      digitalWrite(A1, 0);
      delay(3000);
      digitalWrite(A0, 0);
      digitalWrite(A1, 0);
      lcd.clear();
      lcd.print("Door Locked");
      
     
      
      delay(2000);
      lcd.clear();
      lcd.print("Press *");
      digitalWrite(0, LOW);
   }

    else{
      lcd.clear();
      lcd.print("Invalid Password.");
      lcd.setCursor(3,2);
      lcd.print("Blocked!!");
      digitalWrite(0, 1);
      delay(2000);
      digitalWrite(0, 0);
      lcd.clear();
      lcd.print("Press *");
      digitalWrite(0, HIGH);
      
    }
}
