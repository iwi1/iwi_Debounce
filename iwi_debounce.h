#ifndef IWI_DEBOUNCE_H
#define IWI_DEBOUNCE_H
#define VIBRATIONS 100   //Ustawiamy czas drgan stykow

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif    
	
// Zmienne

//Struktura

class IWI_DEBOUNCE {
public:
	typedef struct  {
            uint16_t t_pressDelay;
            uint16_t t_start;
            bool presskey;
            bool keyState;
            void (*kfun1)(void);
            void (*kfun2)(void);
	}Key_hand_t;

	//DEKLARACJA FUNKCJI    
	void keyPress(uint8_t keypin, uint16_t time_longPress, Key_hand_t *Key_hand);  

};
extern IWI_DEBOUNCE iwiDebounce;
#endif
