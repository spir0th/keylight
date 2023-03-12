# KeyLight
A shell script that turns on/off the keyboard's backlight.

*This mostly relies on `xset`, which is part of X.Org*
*To use this in a TTY/Wayland session, use `--redir` instead*

## Install
Simply put the script into your desired destination (e.g `/usr/bin`, `/bin`)

## Usage
```shell
Usage: keylight [OPTIONS...]

Options:
  --redir: Use echo redirection to toggle backlight
  --testing: Verify script integrity, used for checking errors
  --help: Print help information then exit
  --verbose: Show detailed information for debugging purposes
```

## License
This project is licensed under The Unlicense license.
