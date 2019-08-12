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

const int* Tensor::getShapePtr()
{
    return shape;
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

void Scalar::print() const
{
    std::cout << std::setprecision(2) << "[ " << *data << ", ]" << std::endl;
    std::cout << "Shape: (" << shape[0] << ", " << shape[1] << ')' << std::endl;
    std::cout << "Type: Scalar" << std::endl;
}

// ----------------
// |    Vector    |
// ----------------
Vector::Vector()
{
    shape = new int[2];
    shape[1] = 1;
    data = NULL;
}

Vector::Vector(int length) 
{
    shape = new int[2];
    shape[0] = length;
    shape[1] = 1;
    data = new double[shape[0]];
}

Vector::Vector(int length, const double *arr)
{
    shape = new int[2];
    
    shape[0] = length;
    shape[1] = 1;
    
    data = new double[shape[0]];
    for (int i = 0; i < shape[0]; i++)
    {
        data[i] = arr[i];
    }
}
void Vector::print() const
{
    std::cout << std::setprecision(2) << "[ ";

    for(int i = 0; i < shape[0]; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << " ]" << std::endl;
    
    std::cout << "Shape: (" << shape[0] << ", " << shape[1] << ')' << std::endl; 
    std::cout << "Type: Vector" << std::endl;
}
// ----------------
// |    Matrix    |
// ----------------
Matrix::Matrix()
{
    shape = new int[2];
    shape[0] = 1;
    shape[1] = 1;

    data = NULL;
}

Matrix::Matrix(int rows, int cols)
{
    shape = new int[2];
    shape[0] = rows;
    shape[1] = cols;

    data = new double*[rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new double[cols];
    }
}

Matrix::Matrix(int rows, int cols, const double **inMatrix)
{
    shape = new int[2];
    shape[0] = rows;
    shape[1] = cols;

    data = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new double[cols];
    }

    std::memcpy(data, inMatrix, sizeof(data));
}

void Matrix::print() const
{
    std::cout << std::setprecision(2);

    for (int i = 0; i < shape[0]; i++)
    {
        std::cout << "[ ";
        for (int j = 0; j < shape[1]; j++)
        {
            std::cout << data[i][j] << ", ";
        }
        std::cout << " ]" << std::endl;
    }

    std::cout << "Shape: (" << shape[0] << ", " << shape[1] << ')' << std::endl;
    std::cout << "Type: Matrix" << std::endl;
}