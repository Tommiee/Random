//Code door Tom Warmerdam, met hulp van internet.
#include <Keypad.h>
String INP = "";
String Pass = "0000";
int INPC = 0;
int red = 13;
int green = 12;
int yellow = 11;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 8, 7, 6, 5 };
byte colPins[COLS] = { 4, 3, 2, 9 }; 

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  digitalWrite(yellow,HIGH);
}

void loop()
{
  char key = kpd.getKey();
  if(key)
  {
    digitalWrite(yellow,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    INP = INP + key;
    INPC++;
    if (INPC == 4) {
      Serial.println(INP);
      if(INP == Pass){
        digitalWrite(red,LOW);
        digitalWrite(yellow,LOW);
        digitalWrite(green,HIGH); 
      } else {
        digitalWrite(green,LOW);
        digitalWrite(yellow,LOW);
        digitalWrite(red,HIGH); 
      }
      INP = "";
      INPC = 0; 
    }
  }
}
