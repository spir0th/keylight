# KeyLight
A shell script that turns on/off the keyboard's backlight.

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

## Troubleshooting
### KeyLight fails to work on non-X11 sessions
This is because the default session type is `x11`, which easily relies on `xset` (a part of `xorg-utils`).

And note that programs that are part of `xorg-utils` only work on an X11 session!

For a workaround, use the *echo redirection* method, which directly modifies the brightness file of the device:
```shell
$ keylight -s tty # Using the tty session option, which will do the echo redirection method
$ sudo keylight # Alternative, running as root, which doesn't have any GUI environment running.
```

### xset is an invalid command
Assuming you're using the `x11` session option by default, X.Org utilities might not be installed in your system.

You can refer to your distribution's manual for installing it.

##### This method requires root privileges, the cause of this is explained above.

## FAQs
### Why does the echo redirection method require root privileges?
The echo redirection method directly modifies the `brightness` file of the device (which is `/sys/class/leds`)

The file is read-only for normal users, so root privileges is required.

There might be workarounds to achieve this for non-X11 sessions, but for now, this is the only workaround.

### How to contribute?
By forking off the repository, and make changes to the script, and then submit a pull request.

## License
This project is licensed under The Unlicense license.
