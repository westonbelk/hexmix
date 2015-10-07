#include "color.h"
#include <iostream>
#include <stdint.h>

using namespace std;

int splitt(uint32_t number) {
    for (uint32_t i = 0x1000000; i > 0; i/=0x100) {
        cout << (number % i) << endl;
    }
    cout << "#" << number << endl;
    return 0;
}

int main() {
    color color1 = color(0xff, 0xff, 0xff);
    color color2 = color(0x00, 0x88, 0xCE);

    // expected output is #fafafa
    color mixed = color1.mix(color2);

    cout << "============================" << endl;
    cout << "The first color is " << color1 << endl;
    cout << "The second color is " << color2 << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "The mixed color is " << mixed << endl << endl;

    cout << "Time to split." << endl;

    splitt(0xABCDEF);
    return 0;
}