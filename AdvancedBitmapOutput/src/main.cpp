#include <iostream>
#include <cmath>

#include <encoderDefs.hpp>
#include <pixel.hpp>
#include <encoder.hpp>
#include <patternGenerator.hpp>

int main() {
{
    static Pixel manualPixels[] {
        { 0, 0, 255 }, { 0, 255, 0 },
        { 255, 0, 0 }, { 255, 255, 255 }
    };
    Encoder manualEncoder { "manual.bmp", manualPixels, 2, 2 };
}

{
    static Pixel imagePixels[] {
        { 0, 0, 255 }, { 0, 255, 0 },
        { 255, 0, 0 }, { 255, 255, 255 }
    };

    Image imageImage { imagePixels, 2, 2 };
    Encoder imageEncoder { "image.bmp", imageImage };
}

{
    SolidColor solidColor { 1920, 1080, Color::orange };
    Encoder solidEncoder { "colorOrange.bmp", solidColor.getImage() };
}

{
    const auto sineFormulaExample { [](size_t x) -> size_t { return 1080 / 2 * std::sin(x / 50.0) + 1080 / 2; } };
    BasicFormula basicFormulaFormula { 1920, 1080, sineFormulaExample, Color::orange };
    Encoder basicFormulaEncoder { "sinusoidalFormula.bmp", basicFormulaFormula.getImage() };
}

{
    const auto quadraticFormulaExample { [](size_t x) -> size_t { return std::pow((static_cast<long long>(x) - 960) / 29.5, 2); } };
    BasicFormula basicFormulaFormula { 1920, 1080, quadraticFormulaExample, Color::blue };
    Encoder basicFormulaEncoder { "quadraticFormula.bmp", basicFormulaFormula.getImage() };
}

{
    AllRGB allRGBExample {};
    Encoder allRGBEndocer { "allRGB.bmp", allRGBExample.getImage() };
}
}
