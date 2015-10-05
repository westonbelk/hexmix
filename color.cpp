#include "color.h"
#include <assert.h>
#include <iostream>
#include <iomanip>

color::color() {
    r = 0;
    g = 0;
    b = 0;
}

color::color(unsigned char red, unsigned char green, unsigned char blue) {
    r = red;
    g = green;
    b = blue;
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
 * param: color color2
 *  
 */
color color::mix(color color2) {
    return mix(color2, 0.5);
}

/*
 * Print the hexadecimal representation
 * of the color to the screen.
 */
void color::print() {
    using namespace std;
    cout << "#";
    cout << setfill('0') << setw(2) << hex << static_cast<unsigned>(r);
    cout << setfill('0') << setw(2) << hex << static_cast<unsigned>(g);
    cout << setfill('0') << setw(2) << hex << static_cast<unsigned>(b);
    cout << endl;
}