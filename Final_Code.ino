#include <Servo.h>
#include <EEPROM.h>
#define MORSE_PIN 2
#define Enter_PIN 4
#define Reset_PIN 7
unsigned long start_t=0, end_t=0 ;
int dot = 200;
String letterCode = "";
String Word = "";
String Password = EEPROM.read(0);
bool Open = false;
bool reset = false;
Servo MyServo;

void setup() {
  pinMode(MORSE_PIN , INPUT);
  pinMode(Enter_PIN, INPUT);
  MyServo.attach(6)
  pinMode(Reset_PIN, INPUT);

}

void loop() {
  //for entering the morse code
  if(signal1 && !reset){
    morsecodeinput();
  }
  //Multifunctional Enter switch by which you can enter password and even clear
  if(digitalRead(Enter_PIN) == HIGH){
    EnterSwitch(); 
  }
  //Opening the lock
  LockOpen();
  // Reset switch for cahnging password
  if(digitalRead(Reset_PIN) == HIGH){
    if(reset){
      EEPROM.update(0,Word);
    }
    reset = !reset;
  }
  //When reset switch is pressed it works
  if(reset){
    if(Open){
      ResetSwitch();
    }
  }
}

//takes the morse code of new password
void ResetSwitch(){
  if(!reset){
    reset = true;
    }
  if(signal1){
    morsecodeinput();
    }
  }
  
//Matches the password with the code entered
void EnterSwitch(){
  Password = EEPROM.read(0);
  if(Word == Password){
    Open = true;
    Word = "";
  }else{
    Word = ""
    Open = false;
    }
}
//Opens/closes the lock by triggering the servo motor
void LockOpen(){
  if(Open){
    MyServo.write(90);
  }else{
    MyServo.write(0);
  }
}
//Takes the morse code input
void morsecodeinput(){
  start_t = millis();
  while(signal1()){}
  end_t = millis();

  unsigned long duration = end_t - start_t;//This gives us the time for which the switch was pressed
  char MorseChar = DotDash(duration);
  letterCode += MorseChar; //This stores the . or - in the letter code
  
  while(millis()- end_t < dot*3){//if the user does not press the morse code switch alphabet will be rendered
    if( signal1()){
      return;
      }
  }
  Word+= Alphabet(letterCode);
  letterCode = "";
}
//This function gives charector for morse code
char Alphabet(String code){
  char Alphabets[26] = {'A','B','C','D','E','F','G','H','I','J','K',
                        'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  String Alphabetcode[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.",
                              "---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
  for(int i =0 ; i<26; i++){
    if (code == Alphabetcode[i]){
      return Alphabets[i]; 
      }
    }else { return '';}
}
//Returns the signal if the Morse oin is pressed
bool signal1(){
  if( digitalRead(MORSE_PIN) == HIGH){
    return true;
  }else{
    return false;
  }
}
//This returns dot or dash on based on the duration of which switch was pressed
char DotDash(unsigned long duration){// this returns dot or dash on based on the duration of which switch was pressed
  if(duration < dot*1.5){
    return '.';
  }else if(duration > dot*2.5){
    return '-';
  }
}
