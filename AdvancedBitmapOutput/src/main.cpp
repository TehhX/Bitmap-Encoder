#include <encoderDefs.hpp>
#include <pixel.hpp>
#include <encoder.hpp>
#include <patternGenerator.hpp>

#include <iostream>
#include <cmath>
#include <filesystem>

// Removes the previous images from disk.
void removePreviousImages() {
    static constexpr const char* names[] {
        "manual.bmp",
        "image.bmp",
        "colorOrange.bmp",
        "sinusoidalFormula.bmp",
        "quadraticFormula.bmp",
        "allRGB.bmp",
        "neapolitan.bmp"
    };

    for (const char* name : names)
        if (std::filesystem::exists(name)) {
            std::filesystem::remove(name);
            std::cout << "Removed " << name << " from disk.\n";
        }
}

void pixelArray() {
    static Pixel pixelArr[] {
        {   0, 0, 255 }, {   0, 255,   0 },
        { 255, 0,   0 }, { 255, 255, 255 }
    };

    Encoder enc { "manual.bmp", pixelArr, 2, 2 };
}

void image() {
    static Pixel pixelArr[] {
        {   0, 0, 255 }, {   0, 255,   0 },
        { 255, 0,   0 }, { 255, 255, 255 }
    };

    Image img { pixelArr, 2, 2 };

    Encoder enc { "image.bmp", img };
}

void solidColor() {
    SolidColor patternGen { 1920, 1080, Color::orange };
    Encoder enc { "colorOrange.bmp", patternGen.getImage() };
}

void formulaSin() {
    const auto formula { [](size_t x) -> size_t { return 960 * std::sin(x / 50.0) + 960; } };
    BasicFormula patternGen { 1920, 1080, formula, Color::orange };
    Encoder enc { "sinusoidalFormula.bmp", patternGen.getImage() };
}

void formulaQuad() {
    const auto formula { [](size_t x) -> size_t { return std::pow((static_cast<llong>(x) - 960) / 29.5, 2); } };
    BasicFormula patternGen { 1920, 1080, formula, Color::blue };
    Encoder enc { "quadraticFormula.bmp", patternGen.getImage() };
}

void allRGB() {
    AllRGB patternGen {};
    Encoder enc { "allRGB.bmp", patternGen.getImage() };
}

void neapolitan() {
    Neapolitan patternGen { 600, 500 };
    Encoder enc { "neapolitan.bmp", patternGen.getImage() };
}

int main() {
    removePreviousImages();

    pixelArray();

    image();

    solidColor();

    formulaSin();

    formulaQuad();

    allRGB();

    neapolitan();
}
