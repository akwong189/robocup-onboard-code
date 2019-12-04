#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "helper.h"

void check(int errNum) {
    if(errNum < 0) {
        perror("Error: ");
        exit(EXIT_FAILURE);
    }
    return;
}

void checkPointer(void* ptr) {
    if(ptr == NULL){
        perror("Pointer init error: ");
        exit(EXIT_FAILURE);
    }
    return;
}

int getValuesFromInt(int removeFront, int removeEnd, int value) {
    value = value << removeFront;
    return value >> (sizeof(value) - removeEnd) * 8;
}

int getAbs(int num) {
    return abs(num);
}
