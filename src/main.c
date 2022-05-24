#include <stdio.h>

#include "bf.h"
#include "error.h"

FILE *load_file(char *filename) {
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL)
        make_error("File does not exist");
}

int main(int argc, char *argv[]) {
    if (argc == 1)
        make_error("No filename provided");
    if (argc > 2)
        make_error("Too many arguments provided");
    
    bf_step(bf_create(load_file(argv[1])));
}

