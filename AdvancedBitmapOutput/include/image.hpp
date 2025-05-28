#pragma once

#include <utility>

#include <encoderDefs.hpp>
#include <pixel.hpp>

class Image {
public:
    Pixel* pixels;
    const size_t pixelCount;
    const size_t w;
    const size_t h;

    Image(Pixel pixels[], size_t w, size_t h);

    Image(size_t w, size_t h);

    static size_t getIndex(size_t w, int x, int y);

    size_t getIndex(int x, int y);

    static std::pair<size_t, size_t> getPoint(size_t w, size_t index);

    std::pair<size_t, size_t> getPoint(size_t index);

    Pixel& getPixel(int x, int y);
};
