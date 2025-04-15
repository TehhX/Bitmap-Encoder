#include <encoder.hpp>

#include <iostream>

int main() {
{ // Chroma scope
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

{ // Black scope
    Pixel allBlack[1920 * 1080] { 0 };

    Encoder encBlack { "black.bmp", allBlack, 1920, 1080 };
}

{ // Pink scope
    Pixel allPink[1920 * 1080];
    for (size_t i { 0 }; i < 1920 * 1080; i++)
        allPink[i] = { 255, 0, 128 };

    Encoder encPink { "pink.bmp", allPink, 1920, 1080 };
}
}
