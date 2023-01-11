#include <stdint.h>

class Button{
    public:
        static const uint32_t DEFAULT_CLICK_TIMEOUT   = 500;   // second
        static const uint32_t DEFAULT_DOUBLECLICK_TIMEOUT   = 1000;   // second
        static const uint32_t DEFAULT_HOLD_TIMEOUT          = 1000;   // second

        Button(uint8_t Pin);

        void    update();

        bool    isPressed();
        bool    isReleased();

        bool    onChange();
        bool    onPress();
        bool    onClick(uint32_t timeout = DEFAULT_CLICK_TIMEOUT); // true if the button is clicked (but false if it is held)
        bool    onRelease();

        bool    onDoublePress(  uint32_t timeout = DEFAULT_DOUBLECLICK_TIMEOUT);
        bool    onDoubleClick(  uint32_t timeout = DEFAULT_DOUBLECLICK_TIMEOUT);
        bool    onDoubleRelease(uint32_t timeout = DEFAULT_DOUBLECLICK_TIMEOUT);

        bool        onHold( uint32_t timeout = DEFAULT_HOLD_TIMEOUT); // true when the button is pressed for at least the timeout
        uint32_t    getHoldDuration(); // measure the duration of the current hold

        uint8_t     consecutive_press   = 0; // count the number of consecutive press (number of presses separated by at most the timeout)
        uint8_t     consecutive_click   = 0; // count the number of consecutive click (number of clicks separated by at most the timeout)
        uint8_t     consecutive_release = 0; // count the number of consecutive release (number of releases separated by at most the timeout)
        bool        onNthConsecutivePress(     uint8_t n, uint32_t timeout = DEFAULT_DOUBLECLICK_TIMEOUT);
        bool        onNthConsecutiveClick(     uint8_t n, uint32_t timeout = DEFAULT_DOUBLECLICK_TIMEOUT);
        bool        onNthConsecutiveRelease(   uint8_t n, uint32_t timeout = DEFAULT_DOUBLECLICK_TIMEOUT);

    private:
        enum STATE {DOWN, UP};
        STATE current_state;
        STATE last_state;

        uint8_t pin;

        unsigned long current_time_update = 0;  // keep the time the button has been updated for
        unsigned long current_time_pressed = 0;   // keep the time the button has been clicked for
        unsigned long current_time_release = 0; // keep the time the button has been released for
        unsigned long last_time_pressed = 0;
        unsigned long last_time_release = 0;

        static bool test(uint8_t n, uint32_t timeout, const bool (Button::* func)(), uint32_t current_time,  uint32_t last_time, uint8_t consecutive);

};
