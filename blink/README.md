## **DEPENDENCIES**
* Arduino-IDE
* stm32_arduino(roger clark)-installed in arduino ide
* vscode
* arduino plugin for vscode
* may need ATMEL SAMD (NOT SAM) platform installed in arduino ide
* Install(copy) ARM-GDB to */usr/bin/arm-none-eabi-gdb*
from */home/nilay/.arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gdb*
using 
`sudo cp /home/nilay/.arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gdb /usr/bin/`
* Install OpenOCD in /usr/bin/openocd using
`sudo apt-get install openocd`
* preserve the `/.vsode/launch.json file`.. IT CONTAINS THE GDB DEBUGGING CONFIG
**SNIPPET :**
`
"version": "0.2.0",
    "configurations": [
        {
            "name": "Arduino",
            "type": "arduino",
            "request": "launch",
            "program": "${file}",
            "cwd": "${workspaceRoot}",
            "MIMode": "gdb",
            "targetArchitecture": "arm",
            "miDebuggerPath": "/usr/bin/arm-none-eabi-gdb",
            "debugServerPath": "/usr/bin/openocd",
            "debugServerArgs": "-f interface/stlink-v2.cfg -f target/stm32f1x.cfg",
            "customLaunchSetupCommands": [
                {
                    "text": "target remote localhost:3333"
                },
                {
                    "text": "file ${file}"
                },
                {
                    "text": "load"
                },
                {
                    "text": "monitor reset halt"
                },
                {
                    "text": "monitor reset init"
                }
            ],
            "stopAtEntry": true,
            "serverStarted": "Info\\ :\\ [\\w\\d\\.]*:\\ hardware",
            "launchCompleteCommand": "exec-continue",
            "filterStderr": true,
            "args": []
        }
    ]
}
`
* ### PRESS `F5` TO DEBUG :D enjoy!