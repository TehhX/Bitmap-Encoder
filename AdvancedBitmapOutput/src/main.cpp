#include <iostream>
#include <cmath>

#include <encoder.hpp>
#include <patternGenerator.hpp>

constexpr size_t w { 1080 };
constexpr size_t h { 1920 };

constexpr size_t w1 { w - 1 };
constexpr size_t h1 { h - 1 };

void chromaManual() {
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

void pinkCopy() {
    Pixel allPink[1920 * 1080];
    for (size_t i { 0 }; i < 1920 * 1080; i++)
        allPink[i] = { 255, 0, 128 };

    Encoder encPink { "pink.bmp", allPink, 1920, 1080 };
}

void redImage() {
    Pixel allRed[1920 * 1080];
    for (size_t i { 0 }; i < 1920 * 1080; i++)
        allRed[i] = { 255, 0, 0 };

    Image redImg { allRed, 1920, 1080 };

    Encoder redEnc { "redImage.bmp", redImg };
}

size_t fFormula(size_t x) {
    return 0;
    //auto y {static_cast<size_t>( h1 / 2 * std::sin( x / 150.0 ) - h1 / 2.0 )};

    //std::cout << y << '\n';
}

void formula() {
    Formula frmla { 1920, 1080, fFormula, { 255, 0, 0 } };

    Encoder enc { "formula.bmp", frmla.getImage() };
}

int main() {
    chromaManual();

    pinkCopy();

    redImage();

    formula();
}
