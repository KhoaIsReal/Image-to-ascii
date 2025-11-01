# Image to ASCII

A simple C project that converts images into ASCII art using `stb_image`.

## Features

* Load and decode images using `stb_image`
* Convert pixel brightness to ASCII characters
* Output ASCII art to terminal or file

## Requirements

* C compiler (GCC/Clang)
* `stb_image.h` header
* Any standard terminal that supports ASCII output

## Build

```bash
gcc main.c -o imagetoascii -lm
```

> `-lm` is required to link the math library used by stb_image

## Run

```bash
./imagetoascii
```

