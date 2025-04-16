#include <iostream>
#include <cmath>

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
    BasicFormula basicFormulaFormula { 1920, 1080, [](size_t x) -> size_t { return std::pow(x / 40.0, 2); }, { 255, 255, 255 } };
    Encoder basicFormulaEncoder { "basicFormula.bmp", basicFormulaFormula.getImage() };
}
}
