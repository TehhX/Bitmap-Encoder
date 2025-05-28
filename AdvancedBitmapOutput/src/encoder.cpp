#include <encoder.hpp>

#include <image.hpp>

#include <iostream>

// Write <VAL> to file within <SIZE> bytes.
#define writeBinaryValue(VAL, SIZE) out.write(reinterpret_cast<const char*>(&VAL), SIZE)

static constexpr int zero { 0 };
// Write <SIZE> zeros to file
#define writeBinaryZeros(SIZE) writeBinaryValue(zero, SIZE)

Encoder::Encoder(std::string fileName, Pixel pixels[], size_t w, size_t h)
: out { fileName, std::ios::out | std::ios::binary }, pixels { pixels }, w { w }, h { h }, pixelCount { w * h } {
    if (out.fail()) {
        std::cerr << "Could not open encoder file.\n";
        exit(1);
    }

    static constexpr int bytesPerPixel      {    3 };
    static constexpr int byteFactorRequired {    4 };
    static constexpr int headerSize         {   54 };
    static constexpr int dibHeaderSize      {   40 };
    static constexpr int planes             {    1 };
    static constexpr int bitsPerPixel       {   24 };
    static constexpr int compression        {    0 };
    static constexpr int dpi                { 2835 };

    const auto padsPerRow    { w % 4 == 0 ? 0 : -(static_cast<u_long>(bytesPerPixel * w) % byteFactorRequired) + byteFactorRequired };
    const auto pixelDataSize { static_cast<u_long>(bytesPerPixel * pixelCount + h * padsPerRow) };
    const auto fileSize      { headerSize + pixelDataSize };

// Write BMP header
    out << 'B' << 'M';
    writeBinaryValue(fileSize, 4);
    writeBinaryZeros(4);
    writeBinaryValue(headerSize, 4);

// Write DIB header
    writeBinaryValue(dibHeaderSize, 4);
    writeBinaryValue(w, 4);
    writeBinaryValue(h, 4);
    writeBinaryValue(planes, 2);
    writeBinaryValue(bitsPerPixel, 2);
    writeBinaryValue(compression, 4);
    writeBinaryValue(pixelDataSize, 4);
    writeBinaryValue(dpi, 4);
    writeBinaryValue(dpi, 4);
    writeBinaryZeros(4);
    writeBinaryZeros(4);

// Write pixel array
    for (auto row { static_cast<llong>(h) - 1 }; row >= 0; row--) {
        for (size_t col { 0 }; col < w; col++) {
            const Pixel& pix { pixels[Image::getIndex(w, col, row)] };

            writeBinaryValue(pix.b, 1);
            writeBinaryValue(pix.g, 1);
            writeBinaryValue(pix.r, 1);
        }

        writeBinaryZeros(padsPerRow);
    }

    out.close();

    if (out.fail()) {
        std::cerr << "Could not close file.\n";
        exit(1);
    }
}

Encoder::Encoder(std::string fileName, Image& image)
: Encoder { fileName, image.pixels, image.w, image.h } {}
