#include <iostream>

#include <patternGenerator.hpp>

PatternGen::PatternGen(size_t w, size_t h)
: img { w, h } {
    if (img.pixelCount != img.w * img.h) {
        std::cerr << "Incorrect image size. Pixel count: " << img.pixelCount << ", Excepted: " << img.w * img.h << '\n';
        exit(-1);
    }

    img.pixels = new Pixel[ img.pixelCount ];
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

BasicFormula::BasicFormula(size_t w, size_t h, size_t (*formula)(size_t), const Pixel& pix) 
: PatternGen { w, h } {
    for (size_t x { 0 }; x < img.w; x++)
        img.getPixel(x, -std::max(std::min(formula(x), h - 1), static_cast<size_t>(0)) + h - 1) = pix;
}
