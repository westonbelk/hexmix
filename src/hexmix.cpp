#include "color.h"
#include <stdlib.h>
#include <getopt.h>
using namespace std;



#define hexmix_VERSION_MAJOR '0'
#define hexmix_VERSION_MINOR '1'

const char version[] = {hexmix_VERSION_MAJOR, '.', hexmix_VERSION_MINOR};



void display_help_text() {
    cout << "Help text: show this screen" << endl;
}

void display_version_text() {
    cout << "hexmix " << version << endl;
    cout << "Copyright (C) 2015 Weston Belk" << endl;
    cout << "License GPLv3+; GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>." << endl;
    cout << "This is free software: you are free to change and redistribute it." << endl;
    cout << "There is NO WARRANTY, to the extent permitted by law." << endl << endl;
    cout << "Written by Weston Belk <contact@westonbelk.com>" << endl;
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
                display_version_text();
                exit(EXIT_SUCCESS);
            case 'a':
                amount = atof(optarg);
                break;
            default:
                break;
        }
    }

    // Make sure the two required arguments are present.
    if (argv[optind] == NULL || argv[optind + 1] == NULL) {
        cout << "Mandatory argument(s) missing." << endl
            << "'hexmix -h' for help text and 'man hexmix' for docs." << endl;
        exit(1);
    }

    // Assign the two required arguments.
    color color1 = color(strtoul(argv[optind], NULL, 16));
    optind++;
    color color2 = color(strtoul(argv[optind], NULL, 16));

    // Produce output.
    cout << color1 << " and " << color2 << " mix to make "
                << color1.mix(color2, amount) << endl;

    return 0;
}
