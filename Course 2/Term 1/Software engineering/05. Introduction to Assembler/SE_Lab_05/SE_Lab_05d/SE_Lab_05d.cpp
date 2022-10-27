#include "pch.h"
#include "framework.h"
#include <iostream>

extern "C"
int getminC(int* x, int size) {
    int min = *x;
    for (int i = 0; i < size; i++)
    {
        if (*x < min)
            min = *x;
        x++;
    }
    return min;
}

extern "C"
int getmaxC(int* x, int size) {
    int max = *x;

    for (int i = 0; i < size; i++)
    {
        if (*x > max)
            max = *x;
        x++;
    }
    return max;
}
