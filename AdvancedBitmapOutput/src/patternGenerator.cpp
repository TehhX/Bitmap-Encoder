#include <patternGenerator.hpp>

#include <iostream>

PatternGen::PatternGen(size_t w, size_t h)
: img { w, h } {
    if (img.pixelCount != img.w * img.h) {
        std::cerr << "Incorrect image size. Pixel count: " << img.pixelCount << ", Excepted: " << img.w * img.h << '\n';
        exit(-1);
    }

    img.pixels = new Pixel[img.pixelCount];
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
        u_long y { -formula(x) + h - 1 };

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

        printf("I: %zu\nX: %zu\nY: %zu\nR: %d\nG: %d\nB: %d\n\n", i, img.getPoint(i).first, img.getPoint(i).second, r, g, b);
    }
}
