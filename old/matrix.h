#ifndef H_TENSOR
#define H_TENSOR
#include "tensor.h"
#endif

class Matrix : public Tensor
{
public:
    // CONSTRUCTORS
    Matrix();                    // default
    Matrix(int, int);            // shape only
    Matrix(int, int, double **); // shape plus data
    Matrix(const Matrix &);      // copy
    // DESTRUCTOR
    ~Matrix(); // handle leaky memory
    // OPERATOR
    Matrix& operator=(const Matrix&);
    Tensor& operator+(const Tensor&); // element-wise addition
    void print(std::ostream &os) const;
    double** get_data() const;
    // testing
    void print_addresses(); // print pointer adresses
private:
    double ** allocate(); // allocate memory for the 2d array
    void deep_copy(double**); // copy data from pointer to 2d array
    double ** data;
};