#ifndef H_Matrix
#define H_Matrix
#include "../src/Matrix.h"
#endif

/* ------------------
|   CONSTRUCTORS    |
-------------------*/

Matrix::Matrix()
{
    shape = std::pair(2, 2);
    for (int i = 0; i < shape.second; i++)
    {
        data.push_back(ColumnVector());
    }
}

Matrix::Matrix(size_t row, size_t col)
{
    shape = std::pair(row, col);
    for (int i = 0; i < col; i++)
    {
        data.push_back(ColumnVector());
    }
}

Matrix::Matrix(std::pair<size_t, size_t> shape)
{
    this->shape = shape;
    for (int i = 0; i < shape.second; i ++)
    {
        data.push_back(ColumnVector());
    }
}

Matrix::Matrix(std::vector<std::vector<double>> vec)
{
    size_t rows = vec[0].size();
    size_t cols = vec.size();
    shape = std::pair(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        data.push_back(ColumnVector(vec[i]));
    }
}

Matrix::Matrix(std::vector<ColumnVector> vec)
{
    shape.first = vec[0].get_shape;
    shape.second = vec.size();
    data = vec;
}

Matrix::Matrix(const Matrix &mat)
{
    shape = mat.shape;
    data = mat.data;
}

/* ------------------
|     OPERATORS     |
-------------------*/

Matrix &Matrix::operator=(const Matrix &M)
{
    if (this == &M) {return *this;}

    shape = M.shape;
    data = M.data;
    return *this;
}

bool Matrix::operator==(const Matrix &M) const
{
    if (shape != M.shape) {return false;}
    
    for (int i = 0; i < shape.second; i++)
    {
        if (data[i] != M.data[i]) {return false;}
    }
    return true;
}

bool Matrix::operator!=(const Matrix&M) const
{
    if (*this == M) {return false;}
    else {return true;}
}

Matrix Matrix::operator+(const Matrix &M)
{
    if (this->shape != M.shape)
    {
        std::cout << "Shape mismatch in matrix addition." << std::endl;
        exit(0);
    }

    for (int i = 0; i < shape.second; i++)
    {
        data[i] = data[i] + M.data[i];
    }
}

Matrix Matrix::operator+(double d)
{
    for (int i = 0; i < shape.second; i++)
    {
        data[i] = data[i] + d;
    }
}

Matrix Matrix::operator-(const Matrix &M)
{
    if (this->shape != M.shape)
    {
        std::cout << "Shape mismatch in matrix subtraction." << std::endl;
        exit(0);
    }

    for (int i = 0; i < shape.second; i++)
    {
        data[i] = data[i] - M.data[i];
    }
}

Matrix Matrix::operator-(double d)
{
    for (int i = 0; i < shape.second; i++)
    {
        data[i] = data[i] - d;
    }
}

Matrix Matrix::operator*(const Matrix &M)
{
    if (this->shape != M.shape)
    {
        std::cout << "Shape mismatch in matrix multiplication." << std::endl;
        exit(0);
    }

    for (int i = 0; i < shape.second; i++)
    {
        data[i] = data[i] * M.data[i];
    }
}

Matrix Matrix::operator*(double d)
{
    for (int i = 0; i < shape.second; i++)
    {
        data[i] = data[i] * d;
    }
}

Matrix Matrix::operator/(const Matrix &M)
{
    if (this->shape != M.shape)
    {
        std::cout << "Shape mismatch in matrix division." << std::endl;
        exit(0);
    }

    for (int i = 0; i < shape.second; i++)
    {
        data[i] = data[i] / M.data[i];
    }
}

Matrix Matrix::operator/(double d)
{
    for (int i = 0; i < shape.second; i++)
    {
        data[i] = data[i] / d;
    }
}

