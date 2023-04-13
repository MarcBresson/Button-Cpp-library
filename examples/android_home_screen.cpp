#include "button.h"

Button touch_button;

void setup(){

}

void loop(){
    touch_button.update();

    if (touch_button.onClick(1000)){
        // opens the app
    } else if(touch_button.isHeld(2000)){
        // allows to move the app
    } else if(touch_button.isHeld(1000)){
        // opens the "quick actions" menu
    }

    if (touch_button.onRelease()){
        uint32_t press_duration = touch_button.getPressDuration();

        if(press_duration >= 1000){
            // Hide menu
        }
    }
}
