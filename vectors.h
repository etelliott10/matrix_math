// matrix.h
#ifndef VECTORS_H
#define VECTORS_H

#include <stdbool.h>


typedef struct {
    double *data;      // A 1D array of integers
    int size;       // Number of elements currently inside & acts as the number of columns (width)
    int capacity;   // Max elements it can hold before resizing
} Vector;


#endif
