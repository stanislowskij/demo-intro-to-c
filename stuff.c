#include <stdlib.h>
#include <stdio.h>
// Here is where we define the helper functions.
#include "stuff.h"

// This will swap the elements array[idx1] and array[idx2].
void swap(int *array, int array_length, int idx1, int idx2) {
    // Make sure the arguments behave
    if(idx1 < 0 || idx2 >= array_length) {
        printf("Swap index out of bounds for length %d\n(idx1: %d, idx2: %d)\n", 
                array_length, idx1, idx2);
    } else {
        int temp = array[idx1];
        array[idx1] = array[idx2];
        array[idx2] = temp;
    }
}

// This will allocate an array of ints {1, 2, 3, ..., array_length-1}.
int *make_array(int array_length) {
    // malloc will reserve LENGTH ints of space to this pointer
    int *array = malloc(array_length * sizeof(int));
    for(int i = 0; i < array_length; i++) {
        array[i] = i + 1;
    }
    return array;
}

// This will print the contents of an array, followed by a newline character.
void print_array(int *array, int array_length) {
    for(int i = 0; i < array_length; i++) {
        printf("%d ", array[i]); // prints "array[i]" + " "
    }
    printf("\n");
}