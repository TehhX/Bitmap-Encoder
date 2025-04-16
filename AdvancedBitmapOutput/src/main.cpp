#include <iostream>
#include <cmath>

#include <encoder.hpp>
#include <patternGenerator.hpp>

constexpr size_t w { 1920 };
constexpr size_t h { 1080 };

constexpr size_t w1 { w - 1 };
constexpr size_t h1 { h - 1 };

void chromaManual() {
    static Pixel chroma[ 3 * 3 ] {
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
    static Pixel allPink[ w * h ];
    for (size_t i { 0 }; i < 1920 * 1080; i++)
        allPink[i] = { 255, 0, 128 };

    Encoder encPink { "pink.bmp", allPink, 1920, 1080 };
}

void redImage() {
    static Pixel allRed[ w * h ];
    for (size_t i { 0 }; i < 1920 * 1080; i++)
        allRed[i] = { 255, 0, 0 };

    Image redImg { allRed, 1920, 1080 };

    Encoder redEnc { "redImage.bmp", redImg };
}

size_t bigSine(size_t x) {
    return h1 / 2.0 * std::sin( x / 100.0 ) + h1 / 2.0;
}

void formula() {
    Formula inFormula { 1920, 1080, bigSine, { 255, 0, 0 } };

    Encoder enc { "formula.bmp", inFormula.getImage() };
}

int main() {
    chromaManual();

    pinkCopy();

    redImage();

    formula();
}
