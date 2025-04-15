#include <fstream>

int main() {
// File output stream
    std::ofstream out { "out.bmp" };

// BMP Header
    out << u_char(0x42) << u_char(0x4D);                                 // Signature
    out << u_char(0x46) << u_char(0x00) << u_char(0x00) << u_char(0x00); // File size
    out << u_char(0x00) << u_char(0x00) << u_char(0x00) << u_char(0x00); // Reserved space
    out << u_char(0x36) << u_char(0x00) << u_char(0x00) << u_char(0x00); // Pixel array offset
    
// DIB Header
    out << u_char(0x28) << u_char(0x00) << u_char(0x00) << u_char(0x00); // Number of bytes in DIB header
    out << u_char(0x02) << u_char(0x00) << u_char(0x00) << u_char(0x00); // Width of bitmap (pixels)
    out << u_char(0x02) << u_char(0x00) << u_char(0x00) << u_char(0x00); // Height of bitmap (pixels)
    out << u_char(0x01) << u_char(0x00);                                 // Planes
    out << u_char(0x18) << u_char(0x00);                                 // Bits per pixel
    out << u_char(0x00) << u_char(0x00) << u_char(0x00) << u_char(0x00); // Bitmap compression used (0 for none)
    out << u_char(0x10) << u_char(0x00) << u_char(0x00) << u_char(0x00); // Size of raw bitmap data of pixel array (inc. padding)
    out << u_char(0x13) << u_char(0x0B) << u_char(0x00) << u_char(0x00); // Print resolution pix/meter X
    out << u_char(0x13) << u_char(0x0B) << u_char(0x00) << u_char(0x00); // Print resolution pix/meter Y
    out << u_char(0x00) << u_char(0x00) << u_char(0x00) << u_char(0x00); // Num of colors in palette
    out << u_char(0x00) << u_char(0x00) << u_char(0x00) << u_char(0x00); // Num of important colors in palette

// Pixel array
    out << u_char(0x00) << u_char(0x00) << u_char(0xFF); // Red pixel
    out << u_char(0xFF) << u_char(0xFF) << u_char(0xFF); // White pixel
    out << u_char(0x00) << u_char(0x00);                 // Padding until mult of 4 byte

    out << u_char(0xFF) << u_char(0x00) << u_char(0x00); // Blue pixel
    out << u_char(0x00) << u_char(0xFF) << u_char(0x00); // Green pixel
    out << u_char(0x00) << u_char(0x00);                 // Padding until mult of 4 byte

    out.close();
}
