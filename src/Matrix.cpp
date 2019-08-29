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

Matrix Matrix::operator+(const Matrix &M) const
{
    if (this->shape != M.shape)
    {
        std::cout << "Shape mismatch in matrix addition." << std::endl;
        exit(0);
    }

    Matrix ret(shape);
    for (int i = 0; i < shape.second; i++)
    {
        ret.data[i] = data[i] + M.data[i];
    }
    return ret;
}

Matrix Matrix::operator+(double d) const
{
    Matrix ret(shape);
    for (int i = 0; i < shape.second; i++)
    {
        ret.data[i] = data[i] + d;
    }
    return ret;
}

Matrix Matrix::operator-(const Matrix &M) const
{
    if (this->shape != M.shape)
    {
        std::cout << "Shape mismatch in matrix subtraction." << std::endl;
        exit(0);
    }

    Matrix ret(shape);
    for (int i = 0; i < shape.second; i++)
    {
        ret.data[1] = data[i] - M.data[i];
    }
    return ret;
}

Matrix Matrix::operator-(double d) const
{
    Matrix ret(shape);
    for (int i = 0; i < shape.second; i++)
    {
        ret.data[i] = data[i] - d;
    }
    return ret;
}

Matrix Matrix::operator*(const Matrix &M) const
{
    if (this->shape != M.shape)
    {
        std::cout << "Shape mismatch in matrix multiplication." << std::endl;
        exit(0);
    }

    Matrix ret(shape);
    for (int i = 0; i < shape.second; i++)
    {
        ret.data[i] = data[i] * M.data[i];
    }
    return ret;
}

Matrix Matrix::operator*(double d) const
{   Matrix ret(shape);
    for (int i = 0; i < shape.second; i++)
    {
        ret.data[i] = data[i] * d;
    }
    return ret;
}

Matrix Matrix::operator/(const Matrix &M) const
{
    if (this->shape != M.shape)
    {
        std::cout << "Shape mismatch in matrix division." << std::endl;
        exit(0);
    }

    Matrix ret(shape);
    for (int i = 0; i < shape.second; i++)
    {
        ret.data[i] = data[i] / M.data[i];
    }
    return ret;
}

Matrix Matrix::operator/(double d) const
{
    Matrix ret(shape);
    for (int i = 0; i < shape.second; i++)
    {
        ret.data[i] = data[i] / d;
    }
    return ret;
}

/* ------------------
|     FUNCTIONS     |
-------------------*/

void Matrix::print(std::ostream &os) const
{
    os << std::setprecision(2) << "[ ";

    for (int i = 0; i < shape.first; i++) // Loop through rows
    {
        if (i > 0) {os << "  ";}
        for (int j = 0; j < shape.second; j++) // Loop through cols
        {
            std::vector<double> vec = data[j].get_data();
            os << vec[i] << ", ";
        }
        os << std::endl;
    }
    os << "]" << std::endl;

    os << "Shape: (" << shape.first << " , " << shape.first << ")" << std::endl;
    os << "Type: Vector" << std::endl;
}

std::vector<ColumnVector> Matrix::get_columns() const
{
    std::vector<ColumnVector> vec;
    for (int i = 0; i < shape.second; i++)
    {
        vec.push_back(data[i]);
    }
    return vec;
}
ColumnVector Matrix::get_column(int i) const
{
    return data[i];
}

void Matrix::set_columns(std::vector<std::vector<double>>)
{
    // TODO: implement
}

void Matrix::set_columns(std::vector<ColumnVector>)
{
    // TODO: implement
}

void Matrix::push_column_back(std::vector<double>)
{
    // TODO: implement
}

void Matrix::push_column_back(ColumnVector)
{
    // TODO: implement
}

void Matrix::push_column_front(std::vector<double>)
{
    // TODO: implement
}

void Matrix::push_column_front(ColumnVector)
{
    // TODO: implement
}

std::pair<size_t, size_t> Matrix::get_shape() const
{
    // TODO: implement
}

