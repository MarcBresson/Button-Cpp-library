#include "button.h"

Button reset_button;

void setup(){

}

void loop(){
    reset_button.update();

    if (reset_button.isHeld(10000)){
        // LED starts blinking red
    } else if(reset_button.isHeld(5000)){
        // LED starts blinking yellow
    } else if(reset_button.isHeld(3000)){
        // LED starts blinking blue
    }

    if (reset_button.onRelease()){
        uint32_t press_duration = reset_button.getPressDuration();

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
