#include <fstream>
#include <cassert>
#include <iostream>

using u_llong = unsigned long long;

// File output stream
std::ofstream out { "out.bmp" };

// Print the bitmap signature
void printSig() { out << 'B' << 'M'; }

// Print a decimal number to out in little-endian
void printDecimal(int byteSize, u_llong value) {
    if (value == 0) {
        for (size_t i { 0 }; i < byteSize; i++)
            out << u_char(0);

        return;
    }

    assert(value >= 0);

    switch (byteSize) {
    case 1:
        assert(value < 256);

        u_char byte1 { value };

        out << byte1;

        break;
    case 2:
        assert(value < 65'536);

        u_char byte1 {  };
        u_char byte2 {  };

        out << byte1 << byte2;

        break;
    case 3:
        assert(value < 16'777'216);

        u_char byte1 {  };
        u_char byte2 {  };
        u_char byte3 {  };
        
        break;
    case 4:
        assert(value < 4'294'967'296);

        u_char byte1 {  };
        u_char byte2 {  };
        u_char byte3 {  };
        u_char byte4 {  };
        
        break;
    default:
        std::cerr << "Bad value passed to printDecimal.\n";
        exit(-1);
    }
}

// Prints byteSize zeros
void printPadding(int byteSize) { printDecimal(byteSize, 0); }

// Print an RGB color
void printColor(u_char r, u_char g, u_char b) { out << b << g << r; }

int main() {
// BMP Header
    printSig();
    printDecimal(4, 70);
    printPadding(4);
    printDecimal(4, 54);

// DIB header
    printDecimal(4, 40);
    printDecimal(4, 2);
    printDecimal(4, 2);
    printDecimal(2, 1);
    printDecimal(2, 24);
    printPadding(4);
    printDecimal(4, 16);
    printDecimal(4, 2835);
    printDecimal(4, 2835);
    printPadding(4);
    printPadding(4);

// Pixel array
    printColor(0, 0, 255);
    printColor(255, 255, 255);
    printPadding(2);

    printColor(255, 0, 0);
    printColor(0, 255, 0);
    printPadding(2);

    out.close();
}
