#include <Arduino.h>
#include "button.h"

Button button1;

void setup(){

}

void loop(){
    button1.update();
    uint8_t consecutive_clicks = button1.getNumberConsecutiveClicks(1000);

    if(consecutive_clicks > 10){
        Serial.println("The button has been clicked 10 times in a row.");
    } else if (consecutive_clicks > 2){
        Serial.println("The button has been double clicked.");
    }
}
