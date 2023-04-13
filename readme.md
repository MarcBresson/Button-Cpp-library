<div align="center">
    <h1>Button C++ library</h1>
    <h2>Developed by Marc Bresson</h2>
    <p align="center">
        <a href="https://linkedin.com/in/marc--bresson"><img src="https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555"/></a>
    </p>
</div>

This library provides an object to handle physical or emulated buttons for embedded systems.

# Check [the wiki](/wiki) for the full documentation

# Buttons you interact with everyday, and their code example

You may have encounter these following "buttons" in your life, and you can easily recreate their behaviour with this library.

## Windows file explorer
see ([examples/windows_file_explorer.cpp](examples/windows_file_explorer.cpp)) for the code
- left click on windows is a `onPress()` event.
- right click on windows is a `onRelease()` event.
- opening a file or folder on windows is a `onDoubleRelease()` event.

## Android home screen
see ([examples/android_home_screen.cpp](examples/android_home_screen.cpp)) for the code
- opening an app on your smartphone is a `onClick(1000)` event.
- opening the "quick actions" panel for an app on android is a `isHeld(1000)` event.
- moving an app icon on android is a `isHeld(2000)` event.

## Youtube video viewer
see ([examples/youtube_video_player.cpp](examples/youtube_video_player.cpp)) for the code
- bringing the media control is a `click(500, 200)` event.
- seeking in the video is a `isHeld(500)` event.
- fast-forwarding a youtube video is a `onDoubleClick(200)` event (notice that the timeout here has the same value as the onClick delay).

## Reset your router
see ([examples/router_reset.cpp](examples/router_reset.cpp)) for the code
- if you hold the reset button for more than 3s, the LED will blink blue. If you release the button, the passwords are going to get reset.
- if you hold the reset button for more than 5s, the LED will blink yellow. If you release the button, the network parameters are going to get reset.
- if you hold the reset button for more than 5s, the LED will blink red. If you release the button, the router will revert to its factory settings.

See [Arduino's documentation](https://docs.arduino.cc/built-in-examples/digital/Button) on how to wire a button.

![Wire a button](ressources/circuit%20button.png)
