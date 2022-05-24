#include "error.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR_CODE 1

void make_error(const char *message) {
    printf("Error: %s\n", message);
    exit(ERROR_CODE);
}