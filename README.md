# STM32-Blue Pill Arduino Debugging

### The follwing steps show how to install STM32 Blue Pill for Arduino with debugging all in `Visual Studio CODE`

*   First Make it Programmable using Arduino IDE: * Open Arduino IDE (Arduino 1.8.x) * Installing the Boards by adding a repository for the Additional Boards Manager:
	1. In Arduino IDE, **click File -> Preferences**. 
	2. Then click on the edit button next to **'Additional Boards Manager URLs'**. 
	3. There, add the URL of the STM32duino boards manager package json file: 
	    >`http://dan.drown.org/stm32duino/package_STM32duino_index.json`
* Run Arduino IDE, and **open the menu Tools -> Boards -> Boards Manager. Install the "STM32F1xx/GD32F1xx boards by stm32duino" package**. This will install the necessary compilers for the platform
* Run install.sh below to install udev rules to enable stlinkv2 to work (and without root) in the Arduino IDE :
    >`/home/$USER/.arduino15/packages/stm32duino/tools/stm32tools/2018.9.24/linux/install.sh`
* Now Again Open Additional Boards Manager of the Arduino IDE :
	Install `Arduino SAMD Boards (32-bits ARM Cortex-M0+)`. This will give us the OpenOCD debugger tool.
	To Check if its present : Run
    > `/home/$USER/.arduino15/packages/arduino/tools/openocd/0.9.0-arduino6-static/bin/openocd`
* Its neccessary to install OpenOCD systemwide on my system(otherwise this does'nt work):
	>`sudo apt-get install openocd`
* Install Visual Studio Code and Arduino Extension for VSCODE. Then :
	1. Press `F1` and slect **Arduino:Initialise** 
        
        OR 
       
       **Open File > Preferences > Settings**. Search for "Arduino". Scrool down to `Arduino:Path`. Then enter the path of your Arduino IDE install location :
	`/home/$USER/Downloads/arduino-1.8.5` (IMPORTANT: REPLACE $USER with the USERNAME! IT DOES'NT WORK OTHERWISE!)
	2. Restart VSCODE.
* Upload any Code :
	1. Open Any Blinky Sketch folder with Blinky.ino in it.
	2. Specify the Board Settings accordingly, USB Port (any I think, it does'nt work without specifying)
	3. Include `#include "Arduino.h"` in the start of the code for no error marks in the code
	4. Upload the code
* Debug the Code :
	1. In the same sketch, Press `F5` and select Arduino. This creates the default launch.json file.
    2. Replace it with launch.json located in this dir.

        OR

	    Replace it with this accordingly:(REPLACE "\<USER\>" WITH USERNAME!!!)
    
    >"miDebuggerPath": "/home/\<USER\>/.arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gdb", // REPLACE "\<USER\>" with username!

    >"debugServerPath": "/usr/bin/openocd",

    >"debugServerArgs": "-f interface/stlink-v2.cfg -f target/stm32f1x.cfg"