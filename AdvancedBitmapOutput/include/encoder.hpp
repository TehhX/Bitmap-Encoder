#pragma once

#include <fstream>

#include <encoderDefs.hpp>
#include <image.hpp>
#include <pixel.hpp>

class Encoder {
    // Vars
    std::ofstream out;

    const u_long w;
    const u_long h;
    const size_t pixelCount;

    const Pixel* pixels;

    void writeDecimal(short bytes, u_llong decimalvoid);
    void writeZeros(short bytesvoid);
    void writePixel(const Pixel& pixel);

public:
    Encoder(std::string fileName, const Pixel pixels[], u_long w, u_long h);

    Encoder(std::string fileName, const Image& image);
};
