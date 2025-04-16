#include <iostream>

#include <patternGenerator.hpp>

PatternGen::PatternGen(size_t w, size_t h)
: img { w, h } {
    img.pixels = new Pixel[ w * h ];
}

Image& PatternGen::getImage() {
    return img;
}

Formula::Formula(size_t w, size_t h, size_t (*formula)(size_t), const Pixel& pix) 
: PatternGen { w, h } {
    for (size_t x { 0 }; x < img.w; x++)
        img.getPixel(x, std::max(std::min(formula(x), h - 1), 0ULL)) = { 255, 255, 255 };
}
