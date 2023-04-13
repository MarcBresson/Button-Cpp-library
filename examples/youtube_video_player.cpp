#include "button.h"

Button touch_button;
uint8_t previous_consecutive_clicks;
uint8_t consecutive_clicks;

void setup(){

}

void loop(){
    touch_button.update();

    if(touch_button.onClick(500, 200)){
        // displays the media controls
    } else if(touch_button.isHeld(500)){
        // opens seek mode
    } else {
        previous_consecutive_clicks = consecutive_clicks;
        consecutive_clicks = touch_button.computeNumberOfConsecutiveClicks(500);

        if (previous_consecutive_clicks >= 2 && consecutive_clicks == 0){
            // fast forward of (previous_consecutive_clicks * 10) seconds
        }
    }
}
