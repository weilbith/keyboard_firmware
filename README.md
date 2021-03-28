# Keyboard Firmware

My personal keyboard firmware sources based on the [QMK
framework](https://github.com/qmk/qmk_firmware). I prefer to work on 30%
ergonomic split keyboards.

This repository follows a little different approach then the recommended one.
Rather then maintaining all layouts and user files in a big fork of the origin
QMK repository, this separates the custom sources and combine it with a
submodule. Thereby this repository here remains "independent" with a clean
history focused on my personal configuration only. This does not mean I that I
don't have [my own QMK fork](https://github.com/weilbith/qmk_firmware) to work
on new features or checkout other contributers work.

## Setup

```sh
$ make init # Makes initial setup and installs all dependencies into a virtual environment
$ make link # Links the local sources into the QMK firmware submodule
$ source .env # Sets up the shell (I recommend to use auto-source for .env files on change directory)
```

Once the shell is set up, use the `qmk` tool to compile and flash the firmware
(see `qmk --help`). The default parameters are defined in the `./qmk.ini`
configuration file. Each time a new layout, keyboard or user got added, the
`make link` command must be run again.
