#ifndef COLOR_H
#define COLOR_H

class color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
public:
    color(); // #000000 black
    color(unsigned char, unsigned char, unsigned char);
    color mix(color, double);
    color mix(color);
    void print();
};

#endif