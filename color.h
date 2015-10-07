#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <stdint.h>

class color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
public:
    color(); // intializes with #000000 black
    color(unsigned char, unsigned char, unsigned char);
    color(uint32_t number);
    color mix(color, double);
    color mix(color);
    friend std::ostream& operator<<(std::ostream& os, const color& c);
};

#endif
