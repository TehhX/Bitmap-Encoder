#include <iostream>

#include <encoder.hpp>

Encoder::Encoder(std::string fileName, Pixel pixels[], u_long w, u_long h)
: out { fileName }, pixels { pixels }, w { w }, h { h }, pixelCount { w * h } {
    if (!out.is_open()) {
        std::cerr << "Could not open encoder file.\n";
        exit(-1);
    }

    static constexpr short byteFacReq { 4 };
    static constexpr int headerSize { 54 };
    static constexpr int dpi { 2835 };

    const u_long padsPerRow { w % 4 == 0 ? 0 : -( (sizeof(Pixel) * w) % byteFacReq ) + byteFacReq };
    const u_long pixelDataSize { sizeof(Pixel) * pixelCount + h * padsPerRow };

// Write BMP header
    out << 'B' << 'M';
    writeDecimal(4, headerSize + pixelDataSize);
    writeZeros(4);
    writeDecimal(4, 54);

// Write DIB header
    writeDecimal(4, 40);
    writeDecimal(4, w);
    writeDecimal(4, h);
    writeDecimal(2, 1);
    writeDecimal(2, 24);
    writeDecimal(4, 0);
    writeDecimal(4, pixelDataSize);
    writeDecimal(4, dpi);
    writeDecimal(4, dpi);
    writeZeros(4);
    writeZeros(4);

// Write pixel array
    for (size_t row { h - 1 }; row > 0; row--) {
        for (size_t col { 0 }; col < w; col++)
            out << pixels[getIndex(row, col)];

        writeZeros(padsPerRow);
    }

    for (size_t col { 0 }; col < w; col++)
        out << pixels[getIndex(0, col)];
    
    writeZeros(padsPerRow);

    out.close();

    if (out.fail()) {
        std::cerr << "Could not close file.\n";
        exit(-1);
    }
}

size_t Encoder::getIndex(int row, int col) const {
    return row * w + col;
}

void Encoder::writeDecimal(short bytes, u_llong decimal) {
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
