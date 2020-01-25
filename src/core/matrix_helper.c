#include <string.h>
#include <math.h>

#include "matrix_helper.h"
#include "helper.h"

float* cpy_matrix(float* matrix) {
    float* tempMatrix = calloc(1, sizeof(matrix));
    int i;

    memcpy(tempMatrix, matrix, sizeof(matrix));
    return tempMatrix;
}

void multiply_matrix_scalar(float* matrix, float val) {
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

void sub_matrices(float* dest, float* mat1, float* mat2) {
    int i;
    for(i = 0; i < sizeof(dest) / sizeof(float); ++i) 
        dest[i] = mat1[i] + mat2[i];
    free(mat1);
    free(mat2);
}

void divide_matrix_scalar(float* matrix, int val) {
    int i;
    for(i = 0; i < sizeof(matrix) / sizeof(float); ++i) 
        matrix[i] /= val;
}

// float norm(float* vector) {
//     return sqrt(vector[0] + vector[1]);
// }

float norm(float dx, float dy) {
    return sqrt(dx*dx + dy*dy);
}

float* convert_local (float vec[], float dx, float dy, float rot) {
    vec[0] = dx * cos(-rot) - dy * sin(-rot);
    vec[1] = dx * cos(-rot) + dy * sin(-rot);
}