//Arduino Piano

//keyboard library
#include <KeyboardController.h>
#include "NewToneLib.h"
MyTone t(false);
// Initialize USB Controller
USBHost usb;

// Attach keyboard controller to USB
KeyboardController keyboard(usb);

#define T_A 220
#define T_S 233
#define T_D 247

#define T_Q 262
#define T_W 294
#define T_E 330
#define T_R 349
#define T_T 392
#define T_Y 440
#define T_U 493

#define T_I 523
#define T_O 554
#define T_P 587

const int ledQ = 8;
const int ledW = 7;
const int ledE = 6;
const int ledR = 5;
const int ledT = 4;
const int ledY = 3;
const int ledU = 2;

#define Buzz 11 
//const int LED = 13;







// This function intercepts key press
//void keyPressed() {
//  Serial.print("Pressed:  ");
//  printKey();
//}

// This function intercepts key release
void keyReleased() {
  Serial.print("Released: ");
  char ch = printKey();
 if(ch == 'q')
  {
    t.tone(Buzz,T_Q,200);
    digitalWrite(ledQ,HIGH);
    delay(30);
    digitalWrite(ledQ,LOW);
  }

    if(ch == 'w')
  {
    t.tone(Buzz,T_W,200);
    digitalWrite(ledW,HIGH);
        delay(30);
    digitalWrite(ledW,LOW);
  }
    if(ch == 'e')
  {
    t.tone(Buzz,T_E,200);
    digitalWrite(ledE,HIGH);
        delay(30);
    digitalWrite(ledE,LOW);
  }
    if(ch == 'r')
  {
    t.tone(Buzz,T_R,200);
    digitalWrite(ledR,HIGH);
        delay(30);
    digitalWrite(ledR,LOW);
  }
    if(ch == 't')
  {
    t.tone(Buzz,T_T,200);
    digitalWrite(ledT,HIGH);
        delay(30);
    digitalWrite(ledT,LOW);
  }
    if(ch == 'y')
  {
    t.tone(Buzz,T_Y,200);
    digitalWrite(ledY,HIGH);
        delay(30);
    digitalWrite(ledY,LOW);
  }
    if(ch == 'u')
  {
    t.tone(Buzz,T_U,200);
    digitalWrite(ledU,HIGH);
        delay(30);
    digitalWrite(ledU,LOW);
  }
  if(ch == 'a')
  {
    t.tone(Buzz,T_A,200);
  }
  if(ch == 's')
  {
    t.tone(Buzz,T_S,200);
  }
  if(ch == 'd')
  {
    t.tone(Buzz,T_D,200);
  }

  if(ch == 'i')
  {
    t.tone(Buzz,T_I,200);
  }
    
   if(ch == 'o')
  {
    t.tone(Buzz,T_O,200);
  }
    if(ch == 'p')
  {
    t.tone(Buzz,T_P,200);
  }
//  t.tone(Buzz,0,0);
//  digitalWrite(ledQ,LOW);
//  digitalWrite(ledW,LOW);
//  digitalWrite(ledE,LOW);
//  digitalWrite(ledR,LOW);
//  digitalWrite(ledT,LOW);
//  digitalWrite(ledY,LOW);
//  digitalWrite(ledU,LOW);
  
}

int printKey() {
  // getOemKey() returns the OEM-code associated with the key
  Serial.print(" key:");
  Serial.print(keyboard.getOemKey());

  // getModifiers() returns a bits field with the modifiers-keys
  int mod = keyboard.getModifiers();
  Serial.print(" mod:");
  Serial.print(mod);

  Serial.print(" => ");

  if (mod & LeftCtrl) {
    Serial.print("L-Ctrl ");
  }
  if (mod & LeftShift) {
    Serial.print("L-Shift ");
  }
  if (mod & Alt) {
    Serial.print("Alt ");
  }
  if (mod & LeftCmd) {
    Serial.print("L-Cmd ");
  }
  if (mod & RightCtrl) {
    Serial.print("R-Ctrl ");
  }
  if (mod & RightShift) {
    Serial.print("R-Shift ");
  }
  if (mod & AltGr) {
    Serial.print("AltGr ");
  }
  if (mod & RightCmd) {
    Serial.print("R-Cmd ");
  }

  // getKey() returns the ASCII translation of OEM key
  // combined with modifiers.
  //Serial.write(keyboard.getKey());
  //Serial.println(keyboard.getKey());
  char c = (char)keyboard.getKey();
  return c;
}








void setup()
{

    Serial.begin(9600);
  Serial.println("Program started");
  delay(200);
  
//  pinMode(LED, OUTPUT);
//   digitalWrite(LED,LOW);
     pinMode(Buzz, OUTPUT);
  pinMode(ledQ, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledT, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledU, OUTPUT);
   
}

void loop()
{
        usb.Task();
  

}
