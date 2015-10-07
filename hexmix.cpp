#include "color.h"
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]) {
    // Replace this assert with the proper implementation
    assert(argc >= 3 && "Need two colors.");

    color color1 = color(strtoul(argv[1], NULL, 16));
    color color2 = color(strtoul(argv[2], NULL, 16));
    double amount = atof(argv[3]);

    std::cout << color1 << " and " << color2 << " mix to make "
                << color1.mix(color2, amount) << std::endl;

    return 0;
}
