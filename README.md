# gsimavr-example

Example use for the [gsimavr](https://github.com/WayneBooth/gsimavr) project

## How to use

* Clone this repository.
* Check your dependencies (see the gsimavr project).
* run ```make```, to build the avr firmware.
* enter the 'gui' directory and run ```make```. This will compile and start the gui app.
  * The app will load the firmware from the parent directory as defined in the makefile *PROJECTNAME* variable.
  * The app will automatically configure input/output pins as defined by the firmware.
* How to use the gui:
  * Left click on an input to turn it on,
  * Right click on an input to turn it off,
  * Middle click on an input to connect it to a clock signal

![ScreenShot](https://github.com/WayneBooth/gsimav/screenshot.png)
