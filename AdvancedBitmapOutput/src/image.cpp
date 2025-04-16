#include <iostream>

#include <image.hpp>

Image::Image(Pixel pixels[], size_t w, size_t h) 
: pixels { pixels }, w { w }, h { h }, pixelCount { w * h } {}

Image::Image(size_t w, size_t h)
: Image { nullptr, w, h } {}

size_t Image::getIndex(size_t w, int x, int y) {
    return x + w * y;
}

size_t Image::getIndex(int x, int y) {
    return getIndex(w, x, y);
}

Pixel& Image::getPixel(int x, int y) {
    return pixels[getIndex(w, x, y)];
}
