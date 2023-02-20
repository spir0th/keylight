# KeyLight
A simple shell script that turns on/off the keyboard's backlight.

## Install
Simply put the script into your desired destination (e.g `/usr/bin`, `/bin`)

## Command-line arguments
|              | **Description**                                                                                                               |
|--------------|-------------------------------------------------------------------------------------------------------------------------------|
| `--shortcut` | The program will use `xset` instead of echo redirects. Pass this flag, if you don't want KeyLight to ask for root privileges. |
| `--no-root`  | Do not request root privileges, even when the program does not have those privileges.                                         |
| `--verbose`  | Prints out detailed information that is useless.                                                                              |

## License
This project doesn't have any license yet. I'm still thinking which license to use for. :P
