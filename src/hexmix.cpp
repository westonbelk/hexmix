#include "color.h"
#include <stdlib.h>
#include <getopt.h>

void display_help_text() {
    using namespace std;
    cout << "Help text: show this screen" << endl;
}

void display_version() {
    using namespace std;
    cout << "Version 0.0.0" << endl;
}

int main(int argc, char* argv[]) {

    // Default value of amount
    // If the -a, --amount flag is given, this is
    // overridden by that value.
    double amount = 0.5;
    int opt;

    // Process commandline options
    while ((opt = getopt(argc, argv, "a:vh")) != -1) {
        switch (opt) {
            case 'h':
                display_help_text();
                exit(EXIT_SUCCESS);
            case 'v':
                display_version();
                exit(EXIT_SUCCESS);
            case 'a':
                amount = atof(optarg);
                break;
            case '?':
                std::cout << "unknown option given: -" << optopt << std::endl;
                break;
            default:
                break;
        }
    }

    // Make sure the two required arguments are present.
    if (argv[optind] == NULL || argv[optind + 1] == NULL) {
        std::cout << "Mandatory argument(s) missing\n" << std::endl;
        exit(1);
    }

    // Assign the two required arguments.
    color color1 = color(strtoul(argv[optind], NULL, 16));
    optind++;
    color color2 = color(strtoul(argv[optind], NULL, 16));

    // Produce output.
    std::cout << color1 << " and " << color2 << " mix to make "
                << color1.mix(color2, amount) << std::endl;

    return 0;
}
