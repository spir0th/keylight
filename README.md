# KeyLight
A set of subprojects to lit up your unsupported keyboard on Linux!

## Table of Contents
- [Introduction](#introduction)
	- [History](#history)
	- [How it works](#how-it-works)
	- [Subprojects](#subprojects)
		- [KeyLight for X11](#keylight-for-x11)
		- [KeyLight for TTY](#keylight-for-tty)
		- [KeyLight Packages](#keylight-packages)
- [Installation](#installation)
	- [Distro-specific packages](#distro-specific-packages)
	- [AppImage binaries](#appimage-binaries)
	- [From sources](#from-sources)
- [Contributing](#contributing)
- [License](#license)

## Introduction
### History
The story of KeyLight started when I bought a seemingly Chinese keyboard from E-commerce,
plugging it on my computer, then realizing that pressing it's designated backlight key doesn't even function properly.

And when I booted up to Windows, I can clearly see that the keyboard lits up using it's designated key but it does not in Linux.

And so, this project was made to provide a better support!

### How it works
Instead of providing keyboard drivers, or screw up your system, KeyLight uses the exposed hierarchy hardware made by the Linux kernel in the filesystem.

But for `keylight-x11`, however, it doesn't even use the filesystem! Instead, it relies on Xlib APIs (that's why it's written in C) to interact with the X server.

As for `keylight-wayland`, I haven't found a solution that can interact with Wayland protocols or compositors, but you can use the [tty script](https://github.com/spiroth/keylight/tree/tty) as an alternative instead.

### Subprojects
KeyLight has nothing. But sub-projects! They were divided because it could cause some errors that will conflict other parts of the project.

#### [KeyLight for X11](https://github.com/spiroth/keylight/tree/x11)
The common way to use KeyLight, it is written in C language with the Xlib libraries.

#### [KeyLight for TTY](https://github.com/spiroth/keylight/tree/tty)
Alternative way to use KeyLight, it is written in Bash script with some shenanigan stuff.

#### KeyLight Packages
The source of Distro-specific packages are put in this branch.

## Installation
### Distro-specific packages
I haven't put any packages to the internet, so basically building the package would be the most preferred way for now:

- Arch Linux
```shell
$ git clone https://github.com/spiroth/keylight.git
$ cd keylight/pacman
$ makepkg -si # or makepkg -si --repackage if not built correctly
```

*if you have time, please contribute packaging scripts for other distributions, i only use arch ;)*

### AppImage binaries
As of now, KeyLight doesn't have support for AppImage, but will be added soon.

### From sources
If you don't care about package management, you can clone the repository:
```shell
$ git clone https://github.com/spiroth/keylight.git
$ cd keylight
```

Then refer to [X11 branch README file](https://github.com/spiroth/keylight/tree/x11) or [TTY branch README file](https://github.com/spiroth/keylight/tree/tty).

## Contributing
Join us by forking off the repository, and make changes to the branches, and then submit a pull request.

Issues are welcomed.

## License
This project is licensed under The Unlicense license.
