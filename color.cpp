#include "color.h"
#include <assert.h>
#include <iostream>
#include <iomanip>

/*
 * || Constructor ||
 * Intializes a color object with all zeros.
 * This creates a color of black and a hex
 * code of #000000.
 */
color::color() {
    r = 0x00;
    g = 0x00;
    b = 0x00;
}

/*
 * || Constructor ||
 * Initializes a color object with the given
 * rgb color values. 
 * param: unsigned char red
    Amount of red [0-255]
 * param: unsigned char green
    Amount of green [0-255]
 * param: unsigned char blue
    Amount of blue [0-255]
 */
color::color(unsigned char red, unsigned char green, unsigned char blue) {
    r = red;
    g = green;
    b = blue;
}

/*
 * || Constructor ||
 * Initializes a color object given a six digit hex code.
 * If an 8 digit hex code is given, the alpha channel is ignored.
 * param: uint32_t hex_color_code
 *  0xRRGGBB
 */
color::color(uint32_t number) {
    r = (number % 0x1000000)/0x10000;
    g = (number % 0x10000)/0x100;
    b = (number % 0x100);
}

/* param: color color2
 *  This is the other color or the color that is being
 *  added to the original color
 * param: amount
 *  Amount is a percentage from 0 to 1 inclusive
 *  of the amount of other color to be added.
 * return: mixed
 *  The mixed color.
 */
color color::mix(color color2, double amount) {
    assert(amount >= 0 && amount <= 1);

    unsigned char mixed_red = (color2.r + r)*amount;
    unsigned char mixed_green = (color2.g + g)*amount;
    unsigned char mixed_blue = (color2.b + b)*amount;

    return color(mixed_red, mixed_green, mixed_blue);
}

/*
 * Mixes two colors in equal proportions.
 * param: color color2
    The color to be mixed with
 * returns: the mixed color
 */
color color::mix(color color2) {
    return mix(color2, 0.5);
}

/*
 * Sends current hex code of color to the outpout stream
 */
std::ostream& operator<<(std::ostream& os, const color& c) {
    using namespace std;
    os << "#";
    os << setfill('0') << setw(2) << hex << static_cast<unsigned>(c.r);
    os << setfill('0') << setw(2) << hex << static_cast<unsigned>(c.g);
    os << setfill('0') << setw(2) << hex << static_cast<unsigned>(c.b);
    return os;
}