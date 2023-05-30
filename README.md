# Keylight for X11
A minimal C program for KeyLight made with X11 libraries.

## Table of Contents
- [Usage](#usage)
- [Building](#building)
- [FAQ](#faq)

## Usage
Just execute:
```shell
$ keylight-x11
```
Then it'll lit up the keyboard for you.

If you're curious how the program does, just execute it with the `--verbose` option:
```shell
$ keylight-x11 --verbose
```

Or, if your keyboard does not lit after executing, see [FAQ no.1](#my-keyboard-does-not-lit)

## Building
Prerequisites:
- X11 development headers and libs
- GNU Autotools
- Any C-compliant compiler (GCC is recommended)

Configure the build:
```shell
$ autoreconf --install
$ ./configure
```

Build the program:
```shell
$ make
```

Clean the output:
```shell
$ make clean
$ make distclean
$ make maintainer-clean
```

## FAQ
### My keyboard does not lit
This is a common issue with the Xlib API, they don't provide the current state of the LED indicator.

So in this case, you need to know how the LED mask is handled by your keyboard:
```
$ keylight-x11 --verbose --no-toggle
keylight-x11: Display opened: "(null)"
keylight-x11: LED mask value for ON state is 0
keylight-x11: LED mask value for OFF state is 2
keylight-x11: LED indicator index: -1
keylight-x11: LED indicator mask: 11954
```

Look at the value `11954`, and check that your keyboard is not lit up, we can use this value for the environment variable `KEYLIGHT_LED_MASK_OFF`.

Eventually when you got it right, you can also set `KEYLIGHT_LED_MASK_ON` by re-running the command again and when your keyboard is already lit up.

### Could this replace the script?
No. I made this as a replacement for `xset`, since it does not have the ability to toggle LED indicators in just one command.
