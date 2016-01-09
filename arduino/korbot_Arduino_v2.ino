
#include <Wire.h>
#include <NXShield.h>

/*
#include "LiquidCrystal.h"
LiquidCrystal lcd(22, 23, 24, 25, 26, 27);
int heures,minutes,secondes;
char message[16] = "";
long temps;
*/

/* LES GLOBALEs !!*/ 
const int pins_p[2] = { 50, 53 };  
const int pins_c[2] = { 51, 52 };

int puissance = 0;
int commande = 0;
int rep = 0;
NXShield    nxshield;

void setup() {
  pinMode(pins_p[0], INPUT);// gpio0
  pinMode(pins_p[1], INPUT);// gpio1
  pinMode(pins_c[0], INPUT);// gpio2
  pinMode(pins_c[1], INPUT);// gpio3
  
  //NXT STUFF:
  //nxshield.init( SH_SoftwareI2C ); // usefull for ultrasonic eyes
  nxshield.init( SH_HardwareI2C ); // usefull for nxtmotors
  
  nxshield.waitForButtonPress(BTN_GO);
  nxshield.bank_a.motorReset();
  nxshield.bank_b.motorReset();
  delay(1000);
  
}

int convert(int num) {
  int decimal_val = 0, base = 1, rem;
  while (num > 0) {
    rem = num % 10;
    decimal_val = decimal_val + rem * base;
    num = num / 10;
    base = base * 2;
  }
  return decimal_val;
}

int raspberry_p() {
  int base = 1, binary = 0;
  for(int i = 1; i >= 0; i--) {
    if(digitalRead(pins_p[i]) == HIGH) {
      binary += base;
    }
    base = base *10;
  }
  return binary;
}

int raspberry_c() {
  int base = 1, binary = 0;
  for(int i = 1; i >= 0; i--) {
    if(digitalRead(pins_c[i]) == HIGH) {
      binary += base;
    }
    base = base *10;
  }
  return binary;
}

void loop()
{ 
  puissance = convert(raspberry_p());
  commande = convert(raspberry_c());
  switch(commande) {
    case 0:
      if(rep == 0) { 
        //nxshield.bank_a.motorStop(SH_Motor_2, SH_Next_Action_Brake);
      } else if(rep == 1) {
        nxshield.bank_a.motorRunDegrees(SH_Motor_2,  
                     SH_Direction_Forward, //tourne gauche
                     35,
                     70,
                     SH_Completion_Wait_For,
                     SH_Next_Action_BrakeHold);
        rep = 0;
      } else if(rep == 2) {
        nxshield.bank_a.motorRunDegrees(SH_Motor_2,
                     SH_Direction_Reverse, //tourne droite
                     35,
                     70,
                     SH_Completion_Wait_For, 
                     SH_Next_Action_BrakeHold);
        rep = 0;
      }
      break;
    case 1:
      if(rep == 0) {
      nxshield.bank_a.motorRunDegrees(SH_Motor_2,
                     SH_Direction_Reverse, //tourne droite
                     35,
                     70,
                     SH_Completion_Wait_For, 
                     SH_Next_Action_BrakeHold);
       rep = 1;
       }
      break;
    case 2:
      if(rep == 0) {
      nxshield.bank_a.motorRunDegrees(SH_Motor_2,  
                     SH_Direction_Forward, //tourne gauche
                     35,
                     70,
                     SH_Completion_Wait_For,
                     SH_Next_Action_BrakeHold);
      rep = 2;
      }
      break;
    case 3:
      //nxshield.bank_a.motorStop(SH_Motor_2, SH_Next_Action_Brake);
      break;
  }
  switch(puissance) {
    case 0:
      nxshield.bank_a.motorStop(SH_Motor_1, SH_Next_Action_Brake);
      break;
    case 1:
      nxshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 20);
      break;
    case 3:
      nxshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 50);
      break;
    case 2:
      nxshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, 20);
      break;
  }
  
}
