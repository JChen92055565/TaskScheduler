#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/*
**  Parses command-line arguments to configure the task iterations or other settings
*/
void parse_args(int argc, char *argv[]) {
    if (argc > 1) {
        printf("Debug: Received %d argument(s)\n", argc - 1);
    } else {
        printf("No command-line arguments provided. Running default settings.\n");
    }
}
