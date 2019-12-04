#include <string.h>

#include "matrix_helper.h"
#include "helper.h"

float* cpy_matrix(float* matrix) {
    float* tempMatrix = calloc(1, sizeof(matrix));
    int i;

    memcpy(tempMatrix, matrix, sizeof(matrix));
    return tempMatrix;
}

void multiply_matrix_scalar(float* matrix, int val) {
    int i;
    for(i = 0; i < sizeof(matrix) / sizeof(float); ++i) 
        matrix[i] *= val;
}

void add_matrices(float* destMat, float* oMat) {
    int i;
    for(i = 0; i < sizeof(destMat) / sizeof(float); ++i) 
        destMat[i] += oMat[i];
    free(oMat);
}

void divide_matrix_scalar(float* matrix, int val) {
    int i;
    for(i = 0; i < sizeof(matrix) / sizeof(float); ++i) 
        matrix[i] /= val;
}