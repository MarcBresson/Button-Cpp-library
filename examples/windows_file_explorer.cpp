#include "button.h"

Button button_left;
Button button_right;

void setup(){

}

void loop(){
    button_left.update();
    button_right.update();

    if (button_left.onDoubleRelease()){
        // open file or folder
    } else if(button_left.onPress()){
        // select file
    }

    if(button_right.isReleased()){
        // open context menu
    }
}
