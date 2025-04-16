#include <iostream>

#include <patternGenerator.hpp>

PatternGen::PatternGen(size_t w, size_t h)
: img { w, h } {
    img.pixels = new Pixel[ w * h ];
}

const Image& PatternGen::getImage() const {
    return img;
}

Formula::Formula(size_t w, size_t h, size_t (*formula)(size_t), const Pixel& pix) 
: PatternGen { w, h } {
    for (size_t x { 0 }; x < img.w; x++) {
        std::cout << "X: " << x << ", Y: " << formula(x) << '\n';
        img.pixels[img.getIndex(x, formula(x))] = pix;
    }
}
