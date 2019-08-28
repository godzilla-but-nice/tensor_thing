#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>
#include "ColumnVector.h"

/*
    Class for manipulating and doing math with matrices
    in a way that makes sense coming from a linear algebra
    background. For all uses and function calls, an MxN matrix
    will have M rows and N columns, and data structures will consist
    of a std::vector (row) of ColumnVectors.
*/

class Matrix
{
public:
    // CONSTRUCTORS
    Matrix();                                   // default constructor
    Matrix(size_t, size_t);                     // constructor for set shape
    Matrix(std::pair<size_t, size_t>);          // constructor for set shape (with pair object)
    Matrix(std::vector<std::vector<double>>);   // constructor for 2d std::vector
    Matrix(std::vector<ColumnVector>);          // constructor for std::vector of ColumnVectors
    Matrix(const Matrix &);                     // copy

    // OPERATORS
    Matrix &operator=(const Matrix &);
    bool operator==(const Matrix &);
    Matrix operator+(const Matrix &);           // element-wise addition (same shape)
    Matrix operator+(double);                   // element-wise scalar addition
    Matrix operator-(const Matrix &);           // element-wise subtraction (same shape)
    Matrix operator-(double);                   // element-wise scalar subtraction
    Matrix operator*(double);                   // element-wise scalar multiplication
    Matrix operator*(const Matrix &);           // element-wise multiplaction (same shape)
    Matrix operator/(double);                   // element-wise scalar division
    Matrix operator/(const Matrix &);           // element-wise division (same size)
    
    // FUNCTIONS
    void print(std::ostream &os) const;
    std::vector<ColumnVector> get_columns() const;
    void set_columns(std::vector<std::vector<double>>);
    void set_columns(std::vector<ColumnVector>);
    std::pair<size_t, size_t> get_shape() const;

    // MATH
    ColumnVector dot(const ColumnVector) const;
    Matrix dot(const Matrix) const;
    // double determinant() const;  // I imagine this will be hard to do efficiently...

private:
    std::vector<ColumnVector> data;
    std::pair<size_t, size_t> shape;
};