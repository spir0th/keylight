# KeyLight for TTY
A shell script for KeyLight designed for TTY sessions.

## Table of Contents
- [Usage](#usage)
- [FAQ](#faq)

## Usage
Just execute:
```shell
$ keylight
```
And it'll automatically find the device and toggles between ON and OFF state.

or If you want to use a specific LED indicator:
```shell
$ keylight -d /sys/class/leds/input15
```

You can also force states:
```shell
$ keylight -t enable -d /sys/class/leds/input4
```

## FAQ
### Will this work with Wayland?
Yes, it's the preferred way to use this in a Wayland session.

### It can't run unless I have root privileges?
This is a common issue and has been since the first release (1.0.0), in order to modify the `brightness` file in `/sys/class/leds`, you must have root privileges.

The system has set the permissions for `/sys` to be read-only for normal users.

### Can't assign it to a bindkey, requires root privileges?
Yes. Unfortunately, I haven't found a solution to fix this, but I'd suggest using an X.Org session and assign [KeyLight for X11](https://github.com/spiroth/keylight/tree/x11) with it until this issue has resolved.
