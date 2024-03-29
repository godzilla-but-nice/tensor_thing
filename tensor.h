#include <iostream>
#include <iomanip>
#include <cstring>

class Tensor
{
public:
    virtual void print(std::ostream &os) const = 0;
    // print the tensor in human-readable format
    virtual const int *getShapePtr();
    // return the shape of the tensor as a pointer to an array
    //virtual Tensor* dot(const Tensor*) const = 0;
    // return the "dot product" between two tensors
    virtual ~Tensor(); // handle leaky memory
protected:
    int *shape;
    // pointer to two-element array containing shape information
};