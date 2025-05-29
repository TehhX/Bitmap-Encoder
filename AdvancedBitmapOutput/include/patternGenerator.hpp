#pragma once

#include <pixel.hpp>
#include <encoderDefs.hpp>
#include <image.hpp>

// Base class for all pattern generators. May not be constructed without a deriving class.
class PatternGen {
protected:
    Image img;

    PatternGen(size_t w, size_t h);

    virtual ~PatternGen();

public:
    Image& getImage();
};

// Draws the passed solid color.
struct SolidColor : public PatternGen {
    SolidColor(size_t w, size_t h, u_char r, u_char g, u_char b);

    SolidColor(size_t w, size_t h, Color color);
};

// Draws a passed formula.
struct BasicFormula : public PatternGen {
    BasicFormula(size_t w, size_t h, size_t (*formula)(size_t), u_char r, u_char g, u_char b);

    BasicFormula(size_t w, size_t h, size_t (*formula)(size_t), Color color);
};

// Draws all 256^3 RGB colors to a 4096 px^2 square image.
struct AllRGB : public PatternGen {
    AllRGB();
};

// Draws neapolitan ice cream to specified width and height.
struct Neapolitan : public PatternGen {
    Neapolitan(size_t w, size_t h);
};
