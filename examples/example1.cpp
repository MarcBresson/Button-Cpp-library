#include "button.h"

Button button1;

void setup(){

}

void loop(){
    button1.update();

    if(button1.onClick()){
        // action on click
    } else if (button1.onRelease()){
        uint32_t a = button1.getPressDuration();

    }
    
    
    else if (button1.onHold(2000)){
        // action on hold (pressed for at least 2000ms)
    }
    
}
