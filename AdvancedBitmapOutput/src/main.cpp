#include <encoder.hpp>

#include <iostream>

int main() {
    Pixel chroma[] {
    // Row 1
        { 255,   0,   0 },
        {   0, 255,   0 },
        {   0,   0, 255 },
    // Row 2
        { 128, 128, 128 },
        {   0,   0,   0 },
        { 255, 255, 255 },
    // Row 3
        { 255, 165,   0 },
        { 128,   0, 128 },
        { 127, 255, 212 }
    };

    Encoder encChroma { "chroma.bmp", chroma, 3, 3};
}
