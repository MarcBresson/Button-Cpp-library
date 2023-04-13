/*
This is a simple sketch that creates two different actions with
either a click or a double click.
*/

#include "button.h"

Button button1;

void setup(){

}

void loop(){
    button1.update();

    if(button1.onClick()){
        // Button clicked
    } else if (button1.onDoubleClick()){
        // Button double clicked
    }
}
