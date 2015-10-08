#include "../src/color.h"
#include <iostream>
#include <stdint.h>

using namespace std;

int main() {
    color color1 = color(0xff, 0xff, 0xff);
    color color2 = color(0xf5f5f5);

    color mixed = color1.mix(color2);

    cout << "============================" << endl;
    cout << "The first color is " << color1 << endl;
    cout << "The second color is " << color2 << endl;
    cout << "============================" << endl;
    cout << endl;

    // expected output is #fafafa
    cout << "The mixed color is " << mixed << endl << endl;
    return 0;
}