#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>
#include "../src/ColumnVector.h"

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
    // FRIENDS - necessary for performance...
    friend class ColumnVector;

    // CONSTRUCTORS
    Matrix();                                   // default constructor
    Matrix(size_t, size_t);                     // constructor for set shape
    Matrix(std::pair<size_t, size_t>);          // constructor for set shape (with pair object)
    Matrix(std::vector<std::vector<double>>);   // constructor for 2d std::vector
    Matrix(std::vector<ColumnVector>);          // constructor for std::vector of ColumnVectors
    Matrix(const Matrix &);                     // copy

    // OPERATORS
    Matrix &operator=(const Matrix &);
    bool operator==(const Matrix &) const;
    bool operator!=(const Matrix &) const;
    Matrix operator+(const Matrix &) const;       // element-wise addition (same shape)
    Matrix operator+(double) const;               // element-wise scalar addition
    Matrix operator-(const Matrix &) const;       // element-wise subtraction (same shape)
    Matrix operator-(double) const;               // element-wise scalar subtraction
    Matrix operator*(const Matrix &) const;       // element-wise multiplaction (same shape)
    Matrix operator*(double) const;               // element-wise scalar multiplication
    Matrix operator/(const Matrix &) const;       // element-wise division (same size)
    Matrix operator/(double) const;               // element-wise scalar division
    
    // FUNCTIONS
    void print(std::ostream &os) const;
    std::vector<ColumnVector> get_columns() const;
    ColumnVector get_column(int) const;
    void set_columns(std::vector<std::vector<double>>);
    void set_columns(std::vector<ColumnVector>);
    void push_column_back(std::vector<double>);
    void push_column_back(ColumnVector);
    std::pair<size_t, size_t> get_shape() const;

    // MATH
    ColumnVector dot(const ColumnVector) const;
    Matrix mult(const Matrix) const;
    // double determinant() const;  // I imagine this will be hard to do efficiently...

private:
    std::vector<ColumnVector> data;
    std::pair<size_t, size_t> shape;
};