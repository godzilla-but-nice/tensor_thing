#ifndef H_TENSOR
#define H_TENSOR
#include "tensor.h"
#endif

#ifndef H_DERIVED
#define H_DERIVED
#include "scalar.h"
#include "myVector.h"
#include "matrix.h"
#endif

const int *Tensor::getShapePtr()
{
    return shape;
}
Tensor::~Tensor()
{
    delete[] shape;
}

// ----------------
// |    Scaler    |
// ----------------
Scalar::Scalar()
{
    shape = new int[2];
    shape[0] = 1;
    shape[1] = 1;

    data = 0.0;
}

Scalar::Scalar(double d)
{
    shape = new int[2];
    shape[0] = 1;
    shape[1] = 1;

    data = d;
}

void Scalar::print(std::ostream &os) const
{
    os << std::setprecision(2) << "[ " << data << ", ]" << std::endl;
    os << "Shape: (" << shape[0] << ", " << shape[1] << ')' << std::endl;
    os << "Type: Scalar" << std::endl;
}

// ----------------
// |    Vector    |
// ----------------
Vector::Vector()
{
    shape = new int[2];
    shape[0] = 2;
    shape[1] = 1;

    data = allocate();
    for (int i = 0; i < shape[0]; i++)
    {
        data[i] = 0.0;
    }
}

Vector::Vector(int length)
{
    shape = new int[2];
    shape[0] = length;
    shape[1] = 1;

    data = allocate();
    for (int i = 0; i < shape[0]; i++)
    {
        data[i] = 0.0;
    }
}

Vector::Vector(int length, const double *arr)
{
    shape = new int[2];

    shape[0] = length;
    shape[1] = 1;
    
    data = allocate();
    deep_copy(arr);
}

Vector::Vector(const Vector &V)
{
    shape = new int[2];

    shape[0] = V.shape[0];
    shape[1] = V.shape[1];

    data = allocate();
    deep_copy(V.data);
}

Vector::~Vector()
{
    delete[] data;
}

Vector &Vector::operator=(const Vector &V)
{
    if (this == &V)
    {
        return *this;
    }
    delete[] shape;
    shape = new int[2];

    shape[0] = V.shape[0];
    shape[1] = V.shape[1];

    delete [] data;
    data = allocate();
    deep_copy(V.data);

    return *this;
}

void Vector::print(std::ostream &os) const
{
    os << std::setprecision(2) << "[ ";

    for (int i = 0; i < shape[0]; i++)
    {
        os << data[i] << ", ";
    }
    os << "]" << std::endl;

    os << "Shape: (" << shape[0] << ", " << shape[1] << ')' << std::endl;
    os << "Type: Vector" << std::endl;
}

void Vector::print_addresses()
{
    std::cout << "Addresses" << std::endl;
    std::cout << "Shape: " << shape << std::endl;
    std::cout << "Data: " << data << std::endl;
}

double * Vector::allocate()
{
    double * d_array = new double[shape[0]];
    return d_array;
}

void Vector::deep_copy(const double *arr)
{
    for (int i = 0; i < shape[0]; i++)
    {
        data[i] = arr[i];
    }
}
// ----------------
// |    Matrix    |
// ----------------
Matrix::Matrix()
{
    shape = new int[2];
    shape[0] = 1;
    shape[1] = 1;

    data = allocate();
    for (int i = 0; i < shape[0]; i++)
    {
        for (int j = 0; j < shape[1]; j++)
        {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(int rows, int cols)
{
    shape = new int[2];
    shape[0] = rows;
    shape[1] = cols;

    data = allocate();
    for (int i = 0; i < shape[0]; i++)
    {
        for (int j = 0; j < shape[1]; j++)
        {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(int rows, int cols, double **inMatrix)
{
    shape = new int[2];
    shape[0] = rows;
    shape[1] = cols;

    data = allocate();
    deep_copy(inMatrix);
}

Matrix::Matrix(const Matrix &M)
{
    shape = new int[2];
    shape[0] = M.shape[0];
    shape[1] = M.shape[1];

    data = allocate();
    deep_copy(M.data);
}

Matrix::~Matrix()
{
    for (int i = 0; i < shape[0]; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

Matrix &Matrix::operator=(const Matrix &M)
{
    if (this == &M)
    {
        return *this;
    }
    delete[] shape;
    shape = new int[2];
    shape[0] = M.shape[0];
    shape[1] = M.shape[1];

    delete [] data;
    data = allocate();
    deep_copy(M.data);
    return *this;
}

void Matrix::print(std::ostream &os) const
{
    os << std::setprecision(2);

    for (int i = 0; i < shape[0]; i++)
    {
        os << "[ ";
        for (int j = 0; j < shape[1]; j++)
        {
            os << data[i][j] << ", ";
        }
        os << " ]" << std::endl;
    }

    os << "Shape: (" << shape[0] << ", " << shape[1] << ')' << std::endl;
    os << "Type: Matrix" << std::endl;
}

void Matrix::print_addresses()
{
    std::cout << "Addresses" << std::endl;
    std::cout << "Shape: " << shape << std::endl;
    std::cout << "Data: " << data << std::endl;
}

double ** Matrix::allocate()
{
    double ** d_array = new double*[shape[0]];
    for (int i = 0; i < shape[0]; i++)
    {
        d_array[i] = new double[shape[1]];
    }
    return d_array;
}

void Matrix::deep_copy(double **arr)
{
    for (int i = 0; i < shape[0]; i++)
    {
        for (int j = 0; j < shape[1]; j++)
        {
            data[i][j] = arr[i][j];
        }
    }
}