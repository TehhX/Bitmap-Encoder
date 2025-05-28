#pragma once

#include <ostream>
#include <iostream>

#include <encoderDefs.hpp>

enum class Color : u_char {
    black,
    white,
    red,
    green,
    blue,
    grey,
    orange,
    purple,
    pink
};

struct Pixel {
    u_char r, g, b;
};

inline Pixel pixelFromColor(Color color) {
    switch (color) {
    default:
        std::cerr << "Bad pixelFromColor(Color) input.\n";
        exit(1);

    case Color::black:  return {   0,   0,   0 };
    case Color::white:  return { 255, 255, 255 };
    case Color::red:    return { 255,   0,   0 };
    case Color::green:  return {   0, 255,   0 };
    case Color::blue:   return {   0,   0, 255 };
    case Color::grey:   return { 128, 128, 128 };
    case Color::orange: return { 255, 127,   0 };
    case Color::purple: return { 148,  87, 235 };
    case Color::pink:   return { 255,  16, 240 };
    }
}

inline u_char colorR(Color color) {
    return pixelFromColor(color).r;
}

inline u_char colorG(Color color) {
    return pixelFromColor(color).g;
}

inline u_char colorB(Color color) {
    return pixelFromColor(color).b;
}
