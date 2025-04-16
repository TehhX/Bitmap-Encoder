#pragma once

#include <image.hpp>

class PatternGen {
protected:
    Image img;

    PatternGen(size_t w, size_t h);

public:
    Image& getImage();
};

class Formula : public PatternGen {
public:
    Formula(size_t w, size_t h, size_t (*formula)(size_t), const Pixel& pix);
};
