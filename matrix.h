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
    Matrix &operator=(const Matrix &);
    void print(std::ostream &os) const;

private:
    double **data;
};