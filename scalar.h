#ifndef H_TENSOR
#define H_TENSOR
#include "tensor.h"
#endif

class Scalar : public Tensor
{
public:
    Scalar(); // default constructer
    Scalar(double); // set scalar to specific number
    void print() const;
    // print value of scaler, overloaded from Tensor
    const int* getShapePtr();
    // returns the values of the shape
private:
    double data;
};