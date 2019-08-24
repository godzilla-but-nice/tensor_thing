#ifndef H_VECTOR
#define H_VECTOR
#include "../src/ColumnVector.h"
#endif

ColumnVector::ColumnVector()
{
    shape = 2;

    data = allocate();
    for (int i = 0; i < shape; i++)
    {
        data[i] = 0.0;
    }
}

ColumnVector::ColumnVector(int length)
{
    shape = length;

    data = allocate();
    for (int i = 0; i < shape; i++)
    {
        data[i] = 0.0;
    }
}

ColumnVector::ColumnVector(int length, const double *arr)
{
    shape = length;

    data = allocate();
    deep_copy(arr);
}

ColumnVector::ColumnVector(const ColumnVector &V)
{
    shape = V.shape;

    data = allocate();
    deep_copy(V.data);
}

ColumnVector::~ColumnVector()
{
    delete[] data;
}

ColumnVector &ColumnVector::operator=(const ColumnVector &V)
{
    if (this == &V)
    {
        return *this;
    }

    shape = V.shape;

    delete[] data;
    data = allocate();
    deep_copy(V.data);

    return *this;
}

void ColumnVector::print(std::ostream &os) const
{
    os << std::setprecision(2) << "[ ";

    for (int i = 0; i < shape; i++)
    {
        os << data[i] << ", ";
    }
    os << "]" << std::endl;

    os << "Shape: (" << shape << ')' << std::endl;
    os << "Type: Vector" << std::endl;
}

void ColumnVector::print_addresses()
{
    std::cout << "Addresses" << std::endl;
    std::cout << "Shape: " << shape << std::endl;
    std::cout << "Data: " << *data << std::endl;
}

double *ColumnVector::allocate()
{
    double *d_array = new double[shape];
    return d_array;
}

void ColumnVector::deep_copy(const double *arr)
{
    for (int i = 0; i < shape; i++)
    {
        data[i] = arr[i];
    }
}

double *ColumnVector::get_data() const
{
    return data; // is this going to let us fuck up our data?
}

void ColumnVector::set_data(const double *D)
{
    deep_copy(D);
}