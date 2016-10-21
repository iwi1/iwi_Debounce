#include "iwi_debounce.h"

void IWI_DEBOUNCE::keyPress(uint8_t keypin, uint16_t time_longPress, Key_hand_t *Key_hand) {
          Key_hand->presskey = digitalRead(keypin);
            if (Key_hand->presskey == 0) {
                if (Key_hand->keyState ==0) {
                        Key_hand->t_start = millis();
                        Key_hand->keyState = 1;
                }
                else  Key_hand->t_pressDelay = millis() - Key_hand->t_start;
            } else {
                   if (( Key_hand->t_pressDelay > VIBRATIONS ) && (Key_hand->keyState == 1) && (Key_hand->t_pressDelay < time_longPress)) {
                  Key_hand->keyState=0;
                  Key_hand->t_pressDelay=0;
                  Key_hand->kfun1();
                 
              }
              else if (( Key_hand->t_pressDelay > VIBRATIONS ) && (Key_hand->keyState == 1) && (Key_hand->t_pressDelay >= time_longPress)) {
                  Key_hand->keyState=0;
                  Key_hand->t_pressDelay=0;
                  Key_hand->kfun2();
              }
              else {
                Key_hand->keyState=0;
              }
             
            }
}
    
IWI_DEBOUNCE iwiDebounce;
