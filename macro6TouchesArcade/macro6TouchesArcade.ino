#define BUTTON_KEY1 KEY_F13
#define BUTTON_KEY2 KEY_F14
#define BUTTON_KEY3 KEY_F15
#define BUTTON_KEY4 KEY_LEFT_ALT
#define BUTTON_KEY5 KEY_F17
#define BUTTON_KEY6 KEY_F18

#define BUTTON_1_PIN 16
#define BUTTON_2_PIN 14
#define BUTTON_3_PIN 15
#define BUTTON_4_PIN 8
#define BUTTON_5_PIN 7
#define BUTTON_6_PIN 4

#include "Keyboard.h"


class button {
  public:
  const char key;
  const uint8_t pin;
 
  button(uint8_t k, uint8_t p) : key(k), pin(p){}
 
  void press(boolean state){
    if(state == pressed || (millis() - lastPressed  <= debounceTime)){
      return; // Nothing to see here, folks
    }
 
    lastPressed = millis();
 
    //state ? Keyboard.press(key) : Keyboard.release(key);
    if (state) {
      if (pin == BUTTON_1_PIN) {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('S');
        delay(100);
        Keyboard.releaseAll();
      }
      if (pin == BUTTON_2_PIN) {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('B');
        delay(100);
        Keyboard.releaseAll();
      }
      if (pin == BUTTON_3_PIN) {
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(' ');
        delay(100);
        Keyboard.releaseAll();
      }
      if (pin == BUTTON_4_PIN) {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('c');
        delay(100);
        Keyboard.releaseAll();
      }
      if (pin == BUTTON_5_PIN) {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('v');
        delay(100);
        Keyboard.releaseAll();
      }
      if (pin == BUTTON_6_PIN) {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('1');
        delay(100);
        Keyboard.releaseAll();
      }
      
    } else {
      Keyboard.releaseAll();
    }
        
    pressed = state;
  }
 
  void update(){
    press(!digitalRead(pin));
  }
 
  private:
  const unsigned long debounceTime = 30;
  unsigned long lastPressed = 0;
  boolean pressed = 0;
} ;
 
// Button objects, organized in array
button buttons[] = {
  {BUTTON_KEY1, BUTTON_1_PIN},
  {BUTTON_KEY2, BUTTON_2_PIN},
  {BUTTON_KEY3, BUTTON_3_PIN},
  {BUTTON_KEY4, BUTTON_4_PIN},
  {BUTTON_KEY5, BUTTON_5_PIN},
  {BUTTON_KEY6, BUTTON_6_PIN},
};

const uint8_t NumButtons = sizeof(buttons) / sizeof(button);

void setup() { 
  // Safety check. Ground pin #1 (RX) to cancel keyboard inputs.
  pinMode(1, INPUT_PULLUP);
  if(!digitalRead(1)){
    failsafe();
  }
 
  for(int i = 0; i < 6; i++){
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }
}
 
void loop() {
  for(int i = 0; i < NumButtons; i++){
    buttons[i].update();
  }
}
 
void failsafe(){
  for(;;){} // Just going to hang out here for awhile :D
}
