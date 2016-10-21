#include <iwi_debounce.h>
#include <Timers.h> //https://github.com/nettigo/Timers/tree/master/Timers

#define LONGPRESS 2000   //po jakim czasie nastapi wywolanie funkcji 2
#define KEY_PIN2 46     //Ustawienie klawisza
#define KEY_PIN1 45     //Ustawienie klawisza
#define LED_PIN1 42     //Ustawienie LED
#define LED_PIN2 43     //Ustawienie LED
#define LED_PIN3 44     //Ustawienie LED

//Zmienne programu
bool ledState1, ledState2, ledState3;

    
    Timer Timer1;
    IWI_DEBOUNCE::Key_hand_t Key_hand_1;
    IWI_DEBOUNCE::Key_hand_t Key_hand_2;

//Deklaracje funkcji
    void change_led1(void);
    void change_led2(void);
    void change_led3(void);
    void change_led4(void);    

void setup() {
  // put your setup code here, to run once:
          Serial.begin(9600);
          Timer1.begin(1000);
          pinMode(KEY_PIN2, INPUT_PULLUP);
          pinMode(KEY_PIN1, INPUT_PULLUP);
          pinMode(LED_PIN1, OUTPUT);
          pinMode(LED_PIN2, OUTPUT);
          pinMode(LED_PIN3, OUTPUT);
          Key_hand_1.kfun1 = change_led1;
          Key_hand_1.kfun2 = change_led2;
          Key_hand_2.kfun1 = change_led3;
          Key_hand_2.kfun2 = change_led4;

}

void loop() {
  // put your main code here, to run repeatedly:
        iwiDebounce.keyPress(KEY_PIN1, LONGPRESS, &Key_hand_1);
        iwiDebounce.keyPress(KEY_PIN2, LONGPRESS, &Key_hand_2);    
     
     
        if (Timer1.available()) {
        ledState1 = !ledState1;
        Timer1.restart();
        }
        digitalWrite(LED_PIN1, ledState1);
        digitalWrite(LED_PIN2, ledState2);
        digitalWrite(LED_PIN3, ledState3);
}
    // własne funkcje użytkownika
    void change_led1(void) {
     ledState3 =!ledState3;
     digitalWrite (LED_PIN1, ledState3);
     Serial.println("KLAWISZ 1 FUNKCJA SHORT ");
    }
     
    void change_led2(void) {
     ledState2 =!ledState2;
     digitalWrite (LED_PIN2, ledState2);
    Serial.println("KLAWISZ 1 FUNKCJA LONG ");
    }
    void change_led3(void) {
     ledState2 =!ledState2;
     digitalWrite (LED_PIN1, ledState2);
    Serial.println("KLAWISZ 2 FUNKCJA SHORT ");
    }
     
    void change_led4(void) {
     ledState3 =!ledState3;
     digitalWrite (LED_PIN2, ledState3);
     Serial.println("KLAWISZ 2 FUNKCJA LONG ");
    }
