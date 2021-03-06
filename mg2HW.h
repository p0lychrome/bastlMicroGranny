/* 
	
mg2HW.cpp library
this library is to be used with standuino MicroGranny hardware
MOZZI library compatible
documentation of the library you find here:
mg2HW library

Created by Vaclav Pelousek 2013 www.pelousek.eu
for Standuino wwww.standuino.eu

*/

#ifndef mg2HW_h
#define mg2HW_h

#include "Arduino.h"
#include <avr/pgmspace.h>
#include <shiftRegisterFast.h>
#include <portManipulations.h>

#define DEFAULT 0
#define UNFREEZE_EXTERNALY 1


#define NUMBER_OF_ROWS 6
#define BUTTON_ROW 6


//
#define LATCH_PIN 9
#define CLOCK_PIN 8	
#define DATA_PIN 19

#define BUTTON_PIN 	6
#define BUTTON_2_PIN 7

#define LED_PIN 6 //2
#define LED_2_PIN 7
#define LED_ROW 4
#define LED_2_ROW 5

#define DIGIT_1_PIN 5
#define DIGIT_2_PIN 2
#define DIGIT_3_PIN 3
#define DIGIT_4_PIN 4 //6



#define BIG_1 0
#define BIG_2 3
#define BIG_3 4
#define BIG_4 5
#define BIG_5 6
#define BIG_6 7
#define NUMBER_OF_BIG_BUTTONS 6


#define FN 11
#define PAGE 8

#define UP 10
#define DOWN 9

#define REC 2
#define HOLD 1

#define SEG_A 5 //Display pin 14
#define SEG_B 7 //Display pin 16
#define SEG_C 3 //Display pin 13
#define SEG_D 1 //Display pin 3
#define SEG_E 2 //Display pin 5
#define SEG_F 6 //Display pin 11
#define SEG_G 4 //Display pin 15
#define SEG_DOT 0

#define LED_R_PIN 9
#define LED_G_PIN 8
#define LED_B_PIN 10


#define KNOB_LED_1_PIN 15 //5
#define KNOB_LED_2_PIN 14 //2
#define KNOB_LED_3_PIN 13 //3
#define KNOB_LED_4_PIN 12 //6

#define KNOB_LED_1 15
#define KNOB_LED_2 14
#define KNOB_LED_3 13
#define KNOB_LED_4 12

#define KNOB_PIN_1 4
#define KNOB_PIN_2 3
#define KNOB_PIN_3 2
#define KNOB_PIN_4 1



//


/*
//

#define LATCH_PIN 8
#define CLOCK_PIN 19
#define DATA_PIN 9

#define BUTTON_PIN 	6
#define BUTTON_2_PIN 7



#define LED_PIN 2
#define LED_2_PIN 7
#define LED_ROW 4
#define LED_2_ROW 5

#define DIGIT_1_PIN 5
#define DIGIT_2_PIN 4
#define DIGIT_3_PIN 3
#define DIGIT_4_PIN 6


#define KNOB_PIN_1 1
#define KNOB_PIN_2 2
#define KNOB_PIN_3 3
#define KNOB_PIN_4 4

#define LED_R_PIN 9
#define LED_G_PIN 12
#define LED_B_PIN 8


#define KNOB_LED_1_PIN 13 //5
#define KNOB_LED_2_PIN 10 //2
#define KNOB_LED_3_PIN 11 //3
#define KNOB_LED_4_PIN 14 //6

#define KNOB_LED_1 13
#define KNOB_LED_2 10
#define KNOB_LED_3 11
#define KNOB_LED_4 14

#define SEG_A 7 //Display pin 14
#define SEG_B 5 //Display pin 16
#define SEG_C 1 //Display pin 13
#define SEG_D 3 //Display pin 3
#define SEG_E 4 //Display pin 5
#define SEG_F 6 //Display pin 11
#define SEG_G 0 //Display pin 15
#define SEG_DOT 2


#define BIG_1 2
#define BIG_2 3
#define BIG_3 6
#define BIG_4 4
#define BIG_5 1
#define BIG_6 7
#define NUMBER_OF_BIG_BUTTONS 6


#define FN 8
#define PAGE 15

#define UP 9
#define DOWN 12

#define REC 0 
#define HOLD 5
//
*/

const unsigned char bigButton[NUMBER_OF_BIG_BUTTONS]={BIG_1,BIG_2,BIG_3,BIG_4,BIG_5,BIG_6};




#define KNOB_TOLERANCE 20
#define KNOB_FREEZE_DISTANCE 128

#define NUMBER_OF_KNOBS 4

#define NUMBER_OF_BUTTONS 16

#define NUMBER_OF_DIGITS 4



#define XXX 9
#define IND 12
#define INT 15
#define PAR 18
#define DIR 21
#define PCH 24
#define CRS 27
#define STR 30
#define CTT 33
#define SHF 36
#define LOP 39
#define RTE 42
#define AMT 45
#define ONN 48
#define OFF 51
#define FWD 54
#define BCK 57
#define RD1 60
#define RD2 63
#define PRE 66
#define SEL 69

#define ND 72
#define ST 75
#define REP 78
#define DIR 81
#define LFO 84
#define VOL 87
#define COP 90
#define SVE 93
#define SVD 96
#define LPS 99
#define LPE 102
#define CPD 105
#define PST 108
#define CLR 111




#define FACTORY_CLEAR_PIN 2
#define FACTORY_CLEAR_SIGNAL_PIN 13


#define VOID 36
#define MINUS 37
#define LINES 38
#define SLASH 39

#define ZERO 0

const unsigned char knobLed[NUMBER_OF_KNOBS]={KNOB_LED_1_PIN,KNOB_LED_2_PIN,KNOB_LED_3_PIN,KNOB_LED_4_PIN};

#define LED_R 9
#define LED_G 12
#define LED_B 8
#define NUMBER_OF_COLORS 8




#define BLACK 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define MAGENTA 5
#define CIAN 6
#define WHITE 7




/*
Segments
 -  A
 F / / B
 -  G
 E / / C
 -  D
 */


	

class mg2HW
{
  public: 
  
  
  	

    mg2HW(); // constructor
	void initialize();
	void update();
	//void updateButtons();
	void dimForRecord(unsigned char _BUTTON);

    void setLed(unsigned char _LED, boolean _STATE);
    void setColor(unsigned char _COLOR);
    
    boolean buttonState(unsigned char _BUTTON); 
	boolean justPressed(unsigned char _BUTTON);
	boolean justReleased(unsigned char _BUTTON);
	
	boolean knobFreezed(unsigned char _KNOB);
//	boolean knobMoved(unsigned char _KNOB);
	
	void freezeAllKnobs();
	void unfreezeAllKnobs();
	void freezeKnob(unsigned char _KNOB);
	void unfreezeKnob(unsigned char _KNOB);
	int knobValue(unsigned char _KNOB);
	int lastKnobValue(unsigned char _KNOB);
	void setLastKnobValue(unsigned char _KNOB,int _val);
//	void setFreezeType(unsigned char _TYPE);
	
	
	void flipSwitch(unsigned char _SWITCH);
	void setSwitch(unsigned char _SWITCH, boolean _STATE);
	boolean switchState(unsigned char _SWITCH);
	void resetSwitches();
	
	void displayText(char *text);
	void displayChar(char whichChar,unsigned char _digit) ;
	void lightNumber(int numberToDisplay, unsigned char _digit);
	void displayNumber(int _number);
	void setDot(unsigned char _dot, boolean _state);

	unsigned char soundFromSwitches();
	unsigned char soundFromButtons();
	
//	boolean factoryClear();
//	void factoryCleared();
	void updateKnobs();
	void updateButtons();
	void updateDisplay();
	
	int _row;
unsigned char displayBuffer[NUMBER_OF_ROWS];


  private: 
  	
	int buttonStateHash;
	int lastButtonStateHash;
	int switchStateHash;
	int justPressedHash;
	int justReleasedHash;
	int ledStateHash;
	unsigned char knobFreezedHash;
	
	int knobValues[NUMBER_OF_KNOBS];
	int lastKnobValues[NUMBER_OF_KNOBS];
	
	
	
	
	
	
	
	
	boolean mozzi;
	boolean unfreezeExternaly;

	
};

#endif