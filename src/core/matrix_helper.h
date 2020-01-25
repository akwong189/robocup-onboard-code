#ifndef MATRIX_HELPER_H
    #define MATRIX_HELPER_H
    
    float* cpy_matrix(float* matrix);
    void multiply_matrix_scalar(float* matrix, float val);
    void add_matrices(float* destMat, float* oMat);
    void divide_matrix_scalar(float* matrix, int val);
    void sub_matrices(float* dest, float* mat1, float* mat2);
    // float norm(float* vector);
    float norm(float dx, float dy);
    float* convert_local(float vec[], float dx, float dy ,float rot);
    
#endif