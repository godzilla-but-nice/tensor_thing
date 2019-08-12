#ifndef H_TENSOR
#define H_TENSOR
#include "tensor.h"
#endif

class Vector : public Tensor 
{
public:
    Vector(); // default constructor
    Vector(int); // constructor for set shape
    Vector(int, const double*); // constructor for pointer to array and shape
    void print() const;
    Tensor* dot(const Tensor*) const;
private:
    double * data;
};