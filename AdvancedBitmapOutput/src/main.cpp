#include <encoder.hpp>

#include <iostream>

int main() {
    Pixel px[] {
        {   0,   0,   0 },
        { 255, 255, 255 },
        {   0, 255,   0 },
        { 255,   0,   0 }
    };

    Encoder enc { "image.bmp", px, 2, 2 };
}
