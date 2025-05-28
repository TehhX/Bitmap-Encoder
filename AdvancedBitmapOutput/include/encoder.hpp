#pragma once

#include <encoderDefs.hpp>
#include <image.hpp>
#include <pixel.hpp>

#include <fstream>

class Encoder {
    std::ofstream out;

    const size_t w;
    const size_t h;
    const size_t pixelCount;

    Pixel* pixels;

public:
    Encoder(std::string fileName, Pixel pixels[], size_t w, size_t h);

    Encoder(std::string fileName, Image& image);
};
