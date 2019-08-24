#ifndef H_TENSOR
#define H_TENSOR
#include "tensor.h"
#endif

class Vector : public Tensor
{
public:
    // CONSTRUCTORS
    Vector();                    // default constructor
    Vector(int);                 // constructor for set shape
    Vector(int, const double *); // constructor for pointer to array and shape
    Vector(const Vector &);      // copy
    // DESTRUCTOR
    ~Vector(); // handle leaky memory
    // OPERATORS
    Vector& operator=(const Vector&);
    Tensor& operator+(const Tensor&); // element-wise addition
    // FUNCTIONS
    void print(std::ostream &os) const;
    double ** get_data() const;
    void set_data(const double**);

    Tensor* dot(const Tensor*) const;
    // testing
    void print_addresses(); // print pointer addresses
private:
    double ** allocate(); // allocate memory for vector
    void deep_copy(const double*); // fill values from pointer to 1d array
    double ** data;
};