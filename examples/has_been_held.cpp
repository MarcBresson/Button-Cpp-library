/*
this example shows how to execute different actions in regard of how long
the button has been pressed for.
*/

#include <Arduino.h>
#include "button.h"

Button button1;

void setup(){

}

void loop(){
    button1.update();

    if (button1.onRelease()){
        uint32_t press_duration = button1.getPressDuration();

        if(press_duration > 10000){
            Serial.println("The button has been held for more than 10s.");
        }
        else if(press_duration > 4000){
            Serial.println("The button has been held for more than 4s but less than 10s.");
        }
        else if(press_duration > 1000){
            Serial.println("The button has been held for more than 1s; but less than 4s.");
        }
        else {
            Serial.println("The button has been held for less than 1s.");
        }
    }
}
