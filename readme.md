<div align="center">
    <h1>Button C++ library</h1>
    <h2>Developed by Marc Bresson</h2>
    <p align="center">
        <a href="https://linkedin.com/in/marc--bresson"><img src="https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555"/></a>
    </p>
</div>

This library provide an object to handle physical buttons for embedded systems.

See [Arduino's documentation](https://docs.arduino.cc/built-in-examples/digital/Button) on how to wire a button.

![Alt text](ressources/circuit%20button.png)

# Simple example

```cpp
#include <Arduino.h>
#include "button.h"

Button button1;

void setup(){

}

void loop(){
    button1.update(); // updates the button's state

    if(button1.onClick()){
        Serial.println("Button clicked !");
    } else if (button1.onHold(2000)){
        Serial.println("Button held for more than 2s.");
    }
}
```

# Documentation

## update

```cpp
void update();
```
Compute the current state of the button.

![Single events detailed schema](ressources/single%20events.png)

## isPressed

```cpp
bool isPressed();
```
Returns true if the button is being pressed.

## isReleased

```cpp
bool isReleased();
```
Returns true if the button is not being pressed.

## onChange

```cpp
bool onChange();
```
Returns true if the button's state just changed.

## onPress

```cpp
bool onPress();
```
Returns true if the button has just been pressed.

## onRelease

```cpp
bool onRelease();
```
Returns true if the button has just been released.

## onClick

```cpp
bool onClick(unsigned long timeout);
```
Returns true if a click has just been registered. A click is a combination of a press then a release in a certain amount of time.

default timeout: 1s.

## onHold

```cpp
bool onHold(unsigned long timeout);
```
Returns true if the button has been held for at least `timeout`. You can't chain different onHold if;elif with different timeout because it would only register the hold event with the lowest timeout. If you want to have different actions associated with different timeouts, see `hold_actions` example in the `examples` folder.

default timeout: 1s.

## getPressDuration

```cpp
unsigned long getPressDuration();
```
Returns how long the button was pressed, in ms.

![Double events detailed schema](ressources/Double%20events.png)

## onDoublePress

```cpp
bool onDoublePress(unsigned long timeout);
```
Returns true if the button has just been double pressed. See [Consecutive actions computation](#consecutive-actions-computation).

## onDoubleRelease

```cpp
bool onDoubleRelease(unsigned long timeout);
```
Returns true if the button has just been double released. See [Consecutive actions computation](#consecutive-actions-computation).

## onDoubleClick

```cpp
bool onDoubleClick(unsigned long timeout);
```
Returns true if the button has just been double clicked. See [Consecutive actions computation](#consecutive-actions-computation).

![Nth consecutive events detailed schema](ressources/Nth%20consecutive%20actions%20event.png)

## onNthConsecutivePress

```cpp
bool onNthConsecutivePress(uint8_t N, unsigned long timeout);
```
Returns true if the button has just been pressed N time in a row. Each press must be separated by at most `timeout`. See [Consecutive actions computation](#consecutive-actions-computation).

## onNthConsecutiveRelease

```cpp
bool onNthConsecutiveRelease(uint8_t N, unsigned long timeout);
```
Returns true if the button has just been released N time in a row. Each release must be separated by at most `timeout`. See [Consecutive actions computation](#consecutive-actions-computation).

## onNthConsecutiveClick

```cpp
bool onNthConsecutiveClick(uint8_t N, unsigned long timeout);
```
Returns true if the button has just been clicked N time in a row. Each click must be separated by at most `timeout`. See [Consecutive actions computation](#consecutive-actions-computation).

## getNumberConsecutivePresses

```cpp
uint8_t getNumberConsecutivePresses(unsigned long timeout);
```
Returns the consecutive number of times the button has been pressed. See [Consecutive actions computation](#consecutive-actions-computation).

## getNumberConsecutiveReleases

```cpp
uint8_t getNumberConsecutiveReleases(unsigned long timeout);
```
Returns the consecutive number of times the button has been released. See [Consecutive actions computation](#consecutive-actions-computation).

## getNumberConsecutiveClicks

```cpp
uint8_t getNumberConsecutiveClicks(unsigned long timeout);
```
Returns the consecutive number of times the button has been clicked. See [Consecutive actions computation](#consecutive-actions-computation).

# Note

## Consecutive actions computation

To avoid stress during the button state update, the consecutive actions are computed separetly whether its fore presses, clicks or releases. If you want to use consecutive actions, you must make the call in your loop.
