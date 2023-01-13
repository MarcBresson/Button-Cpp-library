#include <Arduino.h>
#include "button.h"

Button button1;
uint8_t previous_consecutive_clicks;
uint8_t consecutive_clicks;

void setup(){

}

void loop(){
    button1.update();
    previous_consecutive_clicks = consecutive_clicks;
    consecutive_clicks = button1.computeNumberOfConsecutiveClicks(700);

    if(previous_consecutive_clicks > 10 && consecutive_clicks == 0){
        Serial.println("The button has been clicked 10 times in a row.");
    } else
    if (previous_consecutive_clicks > 2 && consecutive_clicks == 0){
        Serial.println("The button has been double clicked.");
    }
}
