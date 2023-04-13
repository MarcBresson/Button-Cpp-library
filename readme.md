<div align="center">
    <h1>Button C++ library</h1>
    <h2>Developed by Marc Bresson</h2>
    <p align="center">
        <a href="https://linkedin.com/in/marc--bresson"><img src="https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555"/></a>
    </p>
</div>

This library provides an object to handle physical buttons for embedded systems.

See [Arduino's documentation](https://docs.arduino.cc/built-in-examples/digital/Button) on how to wire a button.

![Alt text](ressources/circuit%20button.png)

# Click you interact with and their code example

## Windows file explorer ([examples/windows_file_explorer.cpp](examples/windows_file_explorer.cpp))
- left click on windows is a `onPress()` event.
- right click on windows is a `onRelease()` event.
- opening a file or folder on windows is a `onDoubleRelease()` event.

## Android home screen ([examples/android_home_screen.cpp](examples/android_home_screen.cpp))
- opening an app on your smartphone is a `onClick(1000)` event.
- opening the "quick actions" panel for an app on android is a `isHeld(1000)` event.
- moving an app icon on android is a `isHeld(2000)` event.

## Youtube video viewer ([examples/youtube_video_player.cpp](examples/youtube_video_player.cpp))
- bringing the media control is a `click(500, 200)` event.
- seeking in the video is a `isHeld(500)` event.
- fast-forwarding a youtube video is a `onDoubleClick(200)` event (notice that the timeout here has the same value as the onClick delay).

## Reset your router ([examples/router_reset.cpp](examples/router_reset.cpp))
- if you hold the reset button for more than 3s, the LED will blink blue. If you release the button, the passwords are going to get reset.
- if you hold the reset button for more than 5s, the LED will blink yellow. If you release the button, the network parameters are going to get reset.
- if you hold the reset button for more than 5s, the LED will blink red. If you release the button, the router will revert to its factory settings.

# Documentation

## update

```cpp
void update();
```
Compute the current state of the button. It is required to update a button state before any other function for them to work properly.

## reset

```cpp
void reset();
```
Reset the timers, the counters and the states of a button.

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

## isHeld

```cpp
bool isHeld(unsigned long timeout);
```
Returns true while the button is held for at least `timeout`.

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
uint8_t computeNumberOfConsecutivePresses(unsigned long timeout);
```
Returns the consecutive number of times the button has been pressed. See [Consecutive actions computation](#consecutive-actions-computation).

## getNumberConsecutiveReleases

```cpp
uint8_t computeNumberOfConsecutiveReleases(unsigned long timeout);
```
Returns the consecutive number of times the button has been released. See [Consecutive actions computation](#consecutive-actions-computation).

## getNumberConsecutiveClicks

```cpp
uint8_t computeNumberOfConsecutiveClicks(unsigned long timeout);
```
Returns the consecutive number of times the button has been clicked. See [Consecutive actions computation](#consecutive-actions-computation).

# Note

## Consecutive actions computation

To avoid stress during the button state update, the consecutive actions are computed separetly whether its fore presses, clicks or releases. If you want to use consecutive actions, you must make the call in your loop.
