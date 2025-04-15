#pragma once

#include <fstream>

#include <encoderDefs.hpp>
#include <pixel.hpp>

class Encoder {
    // Vars
    std::ofstream out;

    const u_long w;
    const u_long h;
    const size_t pixelCount;

    const Pixel* pixels;

    // Funcs
    void writeHeaderBMP();
    void writeHeaderDIB();
    void writePixels();

    void writeDecimal(short bytes, u_long decimalvoid);
    void writeZeros(short bytesvoid);
    void writePixel(const Pixel& pixel);

public:
    Encoder(std::string fileName, Pixel pixels[], u_long w, u_long h);

    ~Encoder();
};
