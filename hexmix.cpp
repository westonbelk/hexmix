#include "color.h"
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]) {
    // Replace this assert with the proper implementation
    assert(argc == 3 && "Need two colors.");

    color color1 = color(strtoul(argv[1], NULL, 16));
    color color2 = color(strtoul(argv[2], NULL, 16));

    std::cout << color1 << " and " << color2 << " mix evenly to make "
                << color1.mix(color2) << std::endl;

    // Mixing with unequal proportions does NOT work.

    return 0;
}
