# KeyLight
A shell script that turns on/off the keyboard's backlight.

## Running on Wayland / TTY
This script mostly relies on *X.Org* utilities (which is `xorg-xset` or just `xset`). But you can use the *echo redirection* method, which directly modifies the brightness file of the device:
```shell
$ keylight -s tty # Using echo redirection method, with the tty session option.
```

##### This method requires root privileges, the cause of this is explained in the FAQs.

## Install
Simply put the script into your desired destination (e.g `/usr/bin`, `/bin`)

## Usage
```shell
Usage: keylight [OPTIONS...]

Options:
  -t <STATE>: Specify toggle state of device. Default is "auto"
  -s <TYPE>: Specify session type. Default is "x11"
  -d <PATH>: Specify device path. The default value will be looked up recursively.
  -i: Test if the script runs without errors, useful for debugging purposes
  -v: Enable verbose logging, useful for debugging purposes
  -h: View help information
```

## Examples
```shell
$ keylight # Automatically finds the device and toggles state.
$ keylight -t disable -d /sys/class/leds/input15 # Forcefully disables the backlights of a device.
$ keylight -t enable -s tty # Forcefully enables the backlights using the echo redirection method.
```

## FAQs
### Why does the echo redirection method require root privileges?
The path where the devices live is `read-only` for normal users, which is `/sys/class/leds`.

There might be a different way to achieve this for non-X11 sessions, but for now, this is the only available method.

### How to contribute?
By forking off the repository, and make changes to the script, and then submit a pull request.

## License
This project is licensed under The Unlicense license.
