#include <iostream>
#include <iomanip>
#include <cstring>

class Tensor
{
public:
    virtual void print(std::ostream &os) const = 0;
    // print the tensor in human-readable format
    virtual double** get_data() const = 0;
    virtual void set_data(const double**) = 0;
    virtual int* get_shape() const;
    // return the "dot product" between two tensors
    virtual ~Tensor(); // handle leaky memory
protected:
    int *shape;
    // pointer to two-element array containing shape information
};