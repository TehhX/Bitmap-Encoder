#include <fstream>
#include <iostream>

using u_char  = unsigned char;
using u_llong = unsigned long long;

// File output stream
std::ofstream out { "out.bmp" };

// Print the bitmap signature
void printSig() {
    out << 'B' << 'M';
}

// Print an RGB color
void printRGB(u_char r, u_char g, u_char b) {
    out << b << g << r;
}

// Prints byteSize zeros
void printZeros(int byteSize) {
    for (size_t i { 0 }; i < byteSize; i++)
        out << u_char(0x00);

    return;    
}
#define printPadding printZeros

// Print a decimal number to out in little-endian
void printDecimal_LE(int byteSize, u_llong value) {
    if (byteSize > 0)
        out << static_cast<u_char>(value & 0xFF);
    if (byteSize > 1)
        out << static_cast<u_char>((value & 0xFF'00) >> 8);
    if (byteSize > 2)
        out << static_cast<u_char>((value & 0xFF'00'00) >> 16);
    if (byteSize > 3)
        out << static_cast<u_char>((value & 0xFF'00'00'00) >> 24);
}

int main() {
// BMP Header
    printSig();
    printDecimal_LE(4, 0x46);
    printZeros(4);
    printDecimal_LE(4, 0x36);

// DIB Header
    printDecimal_LE(4, 0x28);
    printDecimal_LE(4, 0x02);
    printDecimal_LE(4, 0x02);
    printDecimal_LE(2, 0x01);
    printDecimal_LE(2, 0x18);
    printZeros(4);
    printDecimal_LE(4, 0x10);
    printDecimal_LE(4, 0x0B'13);
    printDecimal_LE(4, 0x0B'13);
    printZeros(4);
    printZeros(4);

// Pixel array
    printRGB(255, 0, 0);
    printRGB(255, 255, 255);
    printPadding(2);

    printRGB(0, 0, 255);
    printRGB(0, 255, 0);
    printPadding(2);

    out.close();
}
