#include <iostream>

#include <encoder.hpp>

Encoder::Encoder(std::string fileName, Pixel pixels[], u_long w, u_long h)
: out { fileName }, pixels { pixels }, w { w }, h { h }, pixelCount { w * h }
{
    if (!out.is_open()) {
        std::cerr << "Could not open encoder file.\n";
        exit(-1);
    }

    writeHeaderBMP();

    writeHeaderDIB();

    writePixels();
}

void Encoder::writeHeaderBMP() {

}

void Encoder::writeHeaderDIB() {

}

void Encoder::writePixels() {

}

void Encoder::writeDecimal(short bytes, u_long decimal) {
    bitMask mask1 { 0x00'00'00'FF };
    bitMask mask2 { 0x00'00'FF'00 };
    bitMask mask3 { 0x00'FF'00'00 };
    bitMask mask4 { 0xFF'00'00'00 };

    if (bytes > 0)
        out << static_cast<u_char> (decimal & mask1);
    if (bytes > 1)
        out << static_cast<u_char>((decimal & mask2) >> 8);
    if (bytes > 2)
        out << static_cast<u_char>((decimal & mask3) >> 16);
    if (bytes > 3)
        out << static_cast<u_char>((decimal & mask4) >> 24);
}

void Encoder::writeZeros(short bytes) {
    for (size_t i { 0 }; i < bytes; i++)
        out << static_cast<u_char>(0);
}

void Encoder::writePixel(const Pixel& pixel) {
    out << pixel;
}

Encoder::~Encoder() {
    out.close();

    if (out.fail()) {
        std::cerr << "Could not close Encoder file.\n";
        exit(-1);
    }
}
