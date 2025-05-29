#include <patternGenerator.hpp>

#include <iostream>

PatternGen::PatternGen(size_t w, size_t h)
: img { w, h } {
    // Zero initialize or else new images may have previous images or garbage imprinted. Remove the '()' for cool effects
    img.pixels = new Pixel[img.pixelCount]();
}

PatternGen::~PatternGen() {
    delete img.pixels;
}

Image& PatternGen::getImage() {
    return img;
}

SolidColor::SolidColor(size_t w, size_t h, u_char r, u_char g, u_char b)
: PatternGen { w, h } {
    for (size_t i { 0 }; i < img.pixelCount; i++) {
        img.pixels[i] = { r, g, b };
    }
}

SolidColor::SolidColor(size_t w, size_t h, Color color)
: SolidColor { w, h, colorR(color), colorG(color), colorB(color) } {}

BasicFormula::BasicFormula(size_t w, size_t h, size_t (*formula)(size_t), u_char r, u_char g, u_char b) 
: PatternGen { w, h } {
    for (size_t x { 0 }; x < img.w; x++) {
        size_t y { -formula(x) + h - 1 };

        if (y < img.h)
            img.getPixel(x, y) = { r, g, b };
    }
}

BasicFormula::BasicFormula(size_t w, size_t h, size_t (*formula)(size_t), Color color)
: BasicFormula { w, h, formula, colorR(color), colorG(color), colorB(color) } {}

AllRGB::AllRGB()
: PatternGen { 4096, 4096 } { // 4096^2 for 256^3 colors.
    for (int b { 0 }; b < 256; b++)
    for (int g { 0 }; g < 256; g++)
    for (int r { 0 }; r < 256; r++) {
        static size_t i { 0 };

        img.pixels[i++] = {
            static_cast<u_char>(r),
            static_cast<u_char>(g),
            static_cast<u_char>(b)
        };
    }
}

Neapolitan::Neapolitan(size_t w, size_t h)
: PatternGen { w, h } {
    static constexpr Pixel strawberry { 251, 177, 178 };
    static constexpr Pixel    vanilla { 243, 229, 171 };
    static constexpr Pixel  chocolate {  98,  52,  18 };

    const size_t leftMargin  { w / 3 };
    const size_t rightMargin { w - leftMargin };

    for (size_t i { 0 }; i < img.pixelCount; i++) {
        size_t x { i % w };

        if (x < leftMargin)
            img.pixels[i] = strawberry;
        else if (x < rightMargin)
            img.pixels[i] = vanilla;
        else
            img.pixels[i] = chocolate;
    }
}
