#include <Arduino.h>
#include "button.h"

Button::Button(){
    reset();
}

Button::Button(uint8_t Pin){
    setPin(Pin);
    reset();
}

Button::Button(uint8_t Pin, bool pull_up){
    setPin(Pin);
    inverted = pull_up;
    reset();
}

void Button::setPin(uint8_t Pin){
    pin = Pin;
}

Button::STATE Button::getDownState(){
    return inverted ? UP : DOWN;
}

Button::STATE Button::getUpState(){
    return inverted ? DOWN : UP;
}

void Button::update(){
    last_state = current_state;
    current_state = getCurrentState();

    current_time_update = millis();

    if(onPress()){
        last_time_pressed = current_time_pressed;
        current_time_pressed = current_time_update;
    }
    else
    if(onRelease()){
        last_time_release = current_time_release;
        current_time_release = current_time_update;
    }
}

void Button::reset(){
    current_state = getDownState();
    last_state = getDownState();

    current_time_update = 0;
    current_time_pressed = 0;
    current_time_release = 0;
    last_time_pressed = 0;
    last_time_release = 0;

    consecutive_press   = 0;
    consecutive_click   = 0;
    consecutive_release = 0;
    previous_consecutive_press   = 0;
    previous_consecutive_click   = 0;
    previous_consecutive_release = 0;
}

Button::STATE Button::getCurrentState(){
    if(digitalRead(pin)){
        return getUpState();
    } else {
        return getDownState();
    }
}

bool Button::isPressed(){
    return current_state == DOWN;
}
bool Button::isReleased(){
    return current_state == UP;
}


bool Button::onChange(){
    return current_state != last_state;
}
bool Button::onPress(){
    return last_state == UP && current_state == DOWN;
}
bool Button::onRelease(){
    return last_state == DOWN && current_state == UP;
}
bool Button::onClick(unsigned long timeout, unsigned long delay){
    return (
        isReleased()
        && (current_time_release - current_time_pressed) < timeout
        && (current_time_update - current_time_release) >= delay
    );
}


bool Button::isHeld(unsigned long timeout){
    return getPressDuration() > timeout;
}

unsigned long Button::getPressDuration(){
    return current_time_update - current_time_pressed;
}


bool Button::onDoublePress(unsigned long timeout){
    return onNthConsecutivePress(2, timeout);
}
bool Button::onDoubleClick(unsigned long timeout){
    return onNthConsecutiveClick(2, timeout);
}
bool Button::onDoubleRelease(unsigned long timeout){
    return onNthConsecutiveRelease(2, timeout);
}


bool Button::onNthConsecutivePress(uint8_t N, unsigned long timeout){
    previous_consecutive_press = consecutive_press;
    computeNumberOfConsecutivePresses(timeout);

    return previous_consecutive_press == N && consecutive_press == 0;
}
bool Button::onNthConsecutiveRelease(uint8_t N, unsigned long timeout){
    previous_consecutive_release = consecutive_release;
    computeNumberOfConsecutiveReleases(timeout);

    return previous_consecutive_release >= N && consecutive_press == 0;
}
bool Button::onNthConsecutiveClick(uint8_t N, unsigned long timeout, unsigned long delay){
    previous_consecutive_click = consecutive_click;
    computeNumberOfConsecutiveClicks(timeout);

    return (
        previous_consecutive_click >= N && consecutive_press == 0
        && (current_time_update - current_time_release) >= delay
    );
}

uint8_t Button::computeNumberOfConsecutivePresses(unsigned long timeout){
    bool is_consecutive_press = (onPress() && (current_time_pressed - last_time_pressed) <= timeout);

    if(is_consecutive_press){
        consecutive_press++;
    }
    if(current_time_pressed - last_time_pressed <= timeout){
        consecutive_press = 0;
    }

    return consecutive_press;
}
uint8_t Button::computeNumberOfConsecutiveReleases(unsigned long timeout){
    bool is_consecutive_release = (onRelease() && (current_time_release - last_time_release) <= timeout);

    if(is_consecutive_release){
        consecutive_release++;
    }
    if(current_time_release - last_time_release <= timeout){
        consecutive_release = 0;
    }

    return consecutive_release;
}
uint8_t Button::computeNumberOfConsecutiveClicks(unsigned long timeout){
    bool is_consecutive_click = (onRelease() && (current_time_pressed - last_time_release) <= timeout);

    if(is_consecutive_click){
        consecutive_click++;
    }
    if(current_time_pressed - last_time_release <= timeout){
        consecutive_click = 0;
    }
    
    return consecutive_click;
}
