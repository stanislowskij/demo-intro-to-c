// A program in C to reverse the elements of an array {1, 2, 3, ..., n}.

// "#include" tells C which header files to borrow
// code from. The pre-processor will basically "paste" the 
// header file code into the linked code.

// #include followed by <> tells the pre-processor to look for system files.
// These ones are the standard library and standard input/output for C.
#include <stdlib.h>
#include <stdio.h>
// #include followed by "" looks for the file in this directory.
#include "stuff.h"
#define LENGTH 10
// main() function must return an int (exit code)
int main() {
    int *numbers = make_array(LENGTH); // borrowed from stuff.h

    printf("Original array: ");
    print_array(numbers, LENGTH); // borrowed from stuff.h

    for(int i = 0; i < LENGTH / 2; i++) {
        swap(numbers, LENGTH, i, LENGTH - 1 - i); // borrowed from stuff.h
    }

    printf("Reversed array: ");
    print_array(numbers, LENGTH);

    free(numbers);
    return EXIT_SUCCESS;
}
