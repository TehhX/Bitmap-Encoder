# Bitmap-Encoder
This repo is for me to learn how bitmap files work, mainly how to read and write them.

## Basic Bitmap Output
This is the simplest and stupidest way to write a bitmap file. The image itself was taken from the [wiki article for BMP files.](https://en.wikipedia.org/wiki/BMP_file_format) It can be compiled and ran from the single file basicBitmapOutput.cpp.

## Intermediate Bitmap Output
This takes advantage of general hex writing with functions to write the same image, but is still for only one specific image. It can be compiled and ran from the single file intermediateBitmapOutput.cpp.

## Advanced Bitmap Output
This generates patterns, and uses OOP to write their contents automatically. This is my best attempt at writing .bmp. It can be ran using CMake inside the folder for its files.
