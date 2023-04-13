/*
this example shows how to execute different actions in regard of how long
the button is being pressed.

If you have a single status LED and multiple actions associated with
a button, you could use this example to notify the user what action
will be executed if he releases the button.
*/

#include "button.h"

Button button1;

void setup(){

}

void loop(){
    button1.update();

    if (button1.isHeld(10000)){
        // LED starts blinking red
    } else if(button1.isHeld(5000)){
        // LED starts blinking yellow
    } else if(button1.isHeld(3000)){
        // LED starts blinking blue
    }

    if (button1.onRelease()){
        uint32_t press_duration = button1.getPressDuration();

        if(press_duration > 10000){
            // Action red executed
        }
        else if(press_duration > 5000){
            // Action yellow executed
        }
        else if(press_duration > 3000){
            // Action blue executed
        }
    }
}
