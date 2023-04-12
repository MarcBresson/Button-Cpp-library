#include <Arduino.h>
#include "button.h"

Button button1;

void setup(){

}

void loop(){
    button1.update();

    if(button1.onClick()){
        Serial.println("Button clicked !");
    } else if (button1.isHeld(2000)){
        Serial.println("Button held for more than 2s.");
    }
}
