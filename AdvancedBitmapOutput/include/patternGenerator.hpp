#pragma once

#include <random>

#include <pixel.hpp>
#include <encoderDefs.hpp>
#include <image.hpp>

class PatternGen {
protected:
    Image img;

    PatternGen(size_t w, size_t h);

public:
    Image& getImage();
};

struct SolidColor : public PatternGen {
    SolidColor(size_t w, size_t h, u_char r, u_char g, u_char b);

    SolidColor(size_t w, size_t h, Color color);
};

// Will draw a formula
struct BasicFormula : public PatternGen {
    BasicFormula(size_t w, size_t h, size_t (*formula)(size_t), u_char r, u_char g, u_char b);

    BasicFormula(size_t w, size_t h, size_t (*formula)(size_t), Color color);
};
