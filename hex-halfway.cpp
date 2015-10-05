#include "color.h"
#include <iostream>

using namespace std;

int main() {
    color color1 = color(0xff, 0xff, 0xff);
    color color2 = color(0x00, 0x88, 0xCE);

    // expected output is #fafafa
    color mixed = color1.mix(color2);
    mixed.print();

    return 0;
}