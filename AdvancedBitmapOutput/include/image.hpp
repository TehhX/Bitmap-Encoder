#pragma once

#include <pixel.hpp>

struct Image {
    Pixel* pixels;

    const size_t pixelCount;
    const size_t w;
    const size_t h;

    inline Image(Pixel pixels[], size_t w, size_t h)
    : pixels { pixels }, w { w }, h { h }, pixelCount { w * h } {}

    inline Image(size_t w, size_t h)
    : Image { nullptr, w, h } {}

    inline size_t getIndex(int row, int col) const { return row * w + col; }
};

inline size_t getIndex(size_t w, int row, int col) { return row * w + col; }
