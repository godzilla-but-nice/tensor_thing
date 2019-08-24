#ifndef H_TENSOR
#define H_TENSOR
#include "tensor.h"
#endif

class Scalar : public Tensor
{
public:
    Scalar();       // default constructer
    Scalar(double); // set scalar to specific number
    void print(std::ostream &os) const;
    double ** get_data() const; // return pointer to data array
    void set_data();
    // print value of scaler, overloaded from Tensor
    // OPERATORS
    Tensor& operator+(const Tensor&); // element-wise addition
private:
    double data;
};