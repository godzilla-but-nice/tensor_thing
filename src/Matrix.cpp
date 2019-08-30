#ifndef H_Matrix
#define H_Matrix
#include "../src/Matrix.h"
#endif

/* ------------------
|   CONSTRUCTORS    |
-------------------*/

Matrix::Matrix()
{
    shape = std::pair<size_t, size_t>(2, 2);
    for (int i = 0; i < shape.second; i++)
    {
        data.push_back(ColumnVector());
    }
}

Matrix::Matrix(size_t row, size_t col)
{
    shape = std::pair<size_t, size_t>(row, col);
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

Matrix::Matrix(std::vector<std::vector<double> > vec)
{
    size_t rows = vec[0].size();
    size_t cols = vec.size();
    shape = std::pair<size_t, size_t>(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        data.push_back(ColumnVector(vec[i]));
    }
}

Matrix::Matrix(std::vector<ColumnVector> vec)
{
    shape.first = vec[0].get_shape();
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
            os << vec[i];
            if (j < shape.second - 1) { os << ", "; }
        }
        if (i < shape.first - 1) { os << std::endl; }
        else { os << " ]" << std::endl; }
    }

    os << "Shape: (" << shape.first << " , " << shape.first << ")" << std::endl;
    os << "Type: Matrix" << std::endl;
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

void Matrix::set_columns(std::vector<std::vector<double> > vec)
{
    *this = Matrix();
    shape.first = vec[0].size();
    shape.second = vec.size();
    for (int i = 0; i < shape.second; i++)
    {
        data.push_back(ColumnVector(vec[i]));
    }
}

void Matrix::set_columns(std::vector<ColumnVector> dat)
{
    *this = Matrix();
    shape.first = dat[0].get_shape();
    shape.second = dat.size();
    data = dat;
}

void Matrix::push_column_back(std::vector<double> vec)
{
    shape.second++;
    data.push_back(ColumnVector(vec));
}

void Matrix::push_column_back(ColumnVector vec)
{
    shape.second++;
    data.push_back(vec);
}

std::pair<size_t, size_t> Matrix::get_shape() const
{
    return shape;
}

/* ------------------
|       MATH        |
-------------------*/

ColumnVector Matrix::dot(const ColumnVector vec) const
{
    if (shape.second != vec.get_shape())
    {
        std::cout << "Shape mismatch in matrix-vector dot product" << std::endl;
        exit(0);
    }

    ColumnVector ret_vec = ColumnVector();
    for (int i = 0; i < shape.first; i++) // loop through shape of ret vec
    {
        double val = 0;
        for (int j = 0; j < shape.second; j++) // loop through cols of matrix
        {
            val += data[j].data[i] *  vec.data[i];
        }
        ret_vec.data.push_back(val);
    }

    return ret_vec;
}

Matrix Matrix::mult(const Matrix mat) const
{
    if (shape.second != mat.shape.first)
    {
        std::cout << "Shape mismatch in matrix-matrix product" << std::endl;
        exit(0);
    }

    Matrix ret_mat = Matrix();
    ret_mat.shape.first = shape.first;
    ret_mat.shape.second = mat.shape.second;

    for (int i = 0; i < ret_mat.shape.second; i++) // loop through cols
    {
        for (int j = 0; j < ret_mat.shape.first; j++)
        { 
            ColumnVector row = ColumnVector();
            for (int z = 0; z < shape.first; z++)
            {
                row.data.push_back(data[z].data[i]);
            }
            ret_mat.data[i].data[j] = row.dot(mat.data[i]);
        }
    }

}