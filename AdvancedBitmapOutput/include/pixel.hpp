#pragma once

#include <ostream>

#include <encoderDefs.hpp>

struct Pixel {
    u_char r, g, b;
};

inline std::ostream& operator<<(std::ostream& out, const Pixel& pix) {
    return out << pix.b << pix.g << pix.r;
}
