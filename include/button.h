#ifndef ButtonLibrary
#define ButtonLibrary
#include <stdint.h>

class Button{
    public:
        static const unsigned long DEFAULT_CLICK_TIMEOUT   = 500;   // second
        static const unsigned long DEFAULT_DOUBLECLICK_TIMEOUT   = 500;   // second
        static const unsigned long DEFAULT_HOLD_TIMEOUT          = 700;   // second

        Button();
        Button(uint8_t Pin);
        Button(uint8_t Pin, bool pull_up);

        void setPin(uint8_t Pin);

        void    update();
        void    reset();

        bool    isPressed();
        bool    isReleased();

        bool    onChange();
        bool    onPress();
        bool    onRelease();
        bool    onClick(unsigned long timeout = DEFAULT_CLICK_TIMEOUT, unsigned long delay = 0);
        bool    isHeld( unsigned long timeout = DEFAULT_HOLD_TIMEOUT); // true when the button is pressed for at least the timeout
        unsigned long    getPressDuration(); // measure the duration of the current hold

        bool    onDoublePress(  unsigned long timeout = DEFAULT_DOUBLECLICK_TIMEOUT);
        bool    onDoubleRelease(unsigned long timeout = DEFAULT_DOUBLECLICK_TIMEOUT);
        bool    onDoubleClick(  unsigned long timeout = DEFAULT_DOUBLECLICK_TIMEOUT);

        bool    onNthConsecutivePress(     uint8_t N, unsigned long timeout = DEFAULT_DOUBLECLICK_TIMEOUT);
        bool    onNthConsecutiveClick(     uint8_t N, unsigned long timeout = DEFAULT_DOUBLECLICK_TIMEOUT, unsigned long delay = 0);
        bool    onNthConsecutiveRelease(   uint8_t N, unsigned long timeout = DEFAULT_DOUBLECLICK_TIMEOUT);
        
        uint8_t computeNumberOfConsecutivePresses( unsigned long timeout = DEFAULT_DOUBLECLICK_TIMEOUT);
        uint8_t computeNumberOfConsecutiveReleases(unsigned long timeout = DEFAULT_DOUBLECLICK_TIMEOUT);
        uint8_t computeNumberOfConsecutiveClicks(  unsigned long timeout = DEFAULT_DOUBLECLICK_TIMEOUT);

    private:
        enum STATE {DOWN, UP};
        STATE current_state;
        STATE last_state;
        bool inverted = false;

        uint8_t pin;

        unsigned long current_time_update = 0;  // keep the time the button has been updated
        unsigned long current_time_pressed = 0; // keep the time the button has been clicked
        unsigned long current_time_release = 0; // keep the time the button has been released
        unsigned long last_time_pressed = 0;
        unsigned long last_time_release = 0;

        uint8_t     consecutive_press   = 0; // count the number of consecutive presses
        uint8_t     consecutive_click   = 0; // count the number of consecutive clicks
        uint8_t     consecutive_release = 0; // count the number of consecutive releases
        uint8_t     previous_consecutive_press   = 0; // count the number of consecutive presses
        uint8_t     previous_consecutive_click   = 0; // count the number of consecutive clicks
        uint8_t     previous_consecutive_release = 0; // count the number of consecutive releases

        STATE getCurrentState();
        STATE getDownState();
        STATE getUpState();
};
#endif
