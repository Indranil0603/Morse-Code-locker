#include <EEPROM.h>
#include <Servo.h>
#define DOT_PIN 2
#define DASH_PIN 3
#define Word_PIN 4
#define ENTER_PIN 5
#define RESET_PIN 7
#define RESET_LED 9
String letterCode = "";
String Word = "";
String Password = "AB";
bool Open = false;
bool reset = false;
Servo MyServo;

void setup() {
  pinMode(DOT_PIN, INPUT_PULLUP); // setup button used to enter dot
  pinMode(DASH_PIN, INPUT_PULLUP); // setup button used to enter dash
  pinMode(Word_PIN, INPUT_PULLUP); // setup button used to get the word for the morse code
  pinMode(ENTER_PIN, INPUT_PULLUP);// setup button used to open the lock with correct password and close the lock
  pinMode(RESET_PIN, INPUT_PULLUP);// setup button used to activate the reset password mode for the locker
  pinMode(RESET_LED, OUTPUT);// setup for led which glows when reset mode is activated
  MyServo.attach(6);
}

void loop() {
  
  if(digitalRead(DOT_PIN) == LOW){ // This statement executes when dot button is pressed
    letterCode += '.';
    delay(300);
  }else if(digitalRead(DASH_PIN) == LOW){ // Thus statement executes when the dash button is pressed
    letterCode += '-';
    delay(300);
  }
  else if(digitalRead(Word_PIN) == LOW){ // This statement executes when the letter button is pressed
    Word += Alphabet(letterCode);
    letterCode = "";
    delay(300);
  }
  else if(digitalRead(ENTER_PIN) == LOW){ // This statement executes when the enter button is pressed
    EnterSwitch();
    delay(300);
  }
  else if((digitalRead(RESET_PIN)== LOW )&& Open){ // This statement executes when the reset button is pressed
    ResetSwitch();
    delay(300);
  }
  LockOpen(); // This statement opens the lock when open is true
  if(reset == true){ //This turns on the LED when reset is true
    digitalWrite(RESET_LED, HIGH); 
  } 

}
//This function gives charecter for morse code
char Alphabet(String code){
  char Alphabets[26] = {'A','B','C','D','E','F','G','H','I','J','K',
                        'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  String Alphabetcode[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.",
                              "---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
  int flag = 0;
  for(int i =0 ; i<26; i++){
    if (code == Alphabetcode[i]){
      return Alphabets[i];
      flag +=1; 
    }
  }if(flag == 0){ 
      return ;
      }
}

//This is function for enter switch that is used to open/close the lock
void EnterSwitch(){
  Password = readStringFromEEPROM(1);
  if(Word == Password){
    Open = true;
    letterCode = "";
    Word = "";
  }else{
    Word = "";
    Open = false;
    letterCode= "";
    }
}

//Opens/closes the lock by trigering the servo motor
void LockOpen(){
  if(Open){
    MyServo.write(90);
  }else{
    MyServo.write(0);
  }
}

//function to write the password in EEPROM
void writeStringToEEPROM(int addrOffset, const String &strToWrite)
{
  byte len = strToWrite.length();
  EEPROM.write(addrOffset, len);
  for (int i = 0; i < len; i++)
  {
    EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
  }
}

//function to read the password from the EEPROM
String readStringFromEEPROM(int addrOffset)
{
  int newStrLen = EEPROM.read(addrOffset);
  char data[newStrLen + 1];
  for (int i = 0; i < newStrLen; i++)
  {
    data[i] = EEPROM.read(addrOffset + 1 + i);
  }
  data[newStrLen] = '\0'; 
  return String(data);
}

//function that works when reset button is pressed
void ResetSwitch(){
  if(!reset){
    reset = true;
    }
  else if(reset){
    writeStringToEEPROM(1, Word);
    Word = "";
    letterCode = "";
    reset = false;
    }
    digitalWrite(RESET_LED, LOW);
  delay(400);
  }
