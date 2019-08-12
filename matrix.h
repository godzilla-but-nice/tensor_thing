#ifndef H_TENSOR
#define H_TENSOR
#include "tensor.h"
#endif

class Matrix : public Tensor
{
public:
    Matrix();
    Matrix(int, int);
    Matrix(int, int, double**);
    void print() const;
private:
    double ** data;
};