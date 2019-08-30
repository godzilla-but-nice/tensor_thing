#ifndef H_VECTOR
#define H_VECTOR
#include "../src/ColumnVector.h"
#endif

/* ------------------
|   CONSTRUCTORS    |
-------------------*/

ColumnVector::ColumnVector()
{
    shape = 2;

    for (int i = 0; i < shape; i++)
    {
        data.push_back(0.0);
    }
}

ColumnVector::ColumnVector(size_t length)
{
    shape = length;

    for (int i = 0; i < shape; i++)
    {
        data.push_back(0.0);
    }
}

ColumnVector::ColumnVector(std::vector<double> vec)
{
    shape = vec.size();

    for (int i = 0; i < shape; i++)
    {
        data.push_back(vec[i]);
    }
}

ColumnVector::ColumnVector(const ColumnVector &V)
{
    shape = V.shape;
    data = V.data;
}

/* ------------------
|     OPERATORS     |
-------------------*/

ColumnVector &ColumnVector::operator=(const ColumnVector &V)
{
    if (this == &V)
    {
        return *this;
    }

    shape = V.shape;
    data = V.data;

    return *this;
}

bool ColumnVector::operator==(const ColumnVector &V) const
{
    if (shape != V.shape)
    {
        return false;
    }

    for (int i = 0; i < shape; i++)
    {
        if (data[i] != V.data[i])
        {
            return false;
        }
    }
    return true;
}

bool ColumnVector::operator!=(const ColumnVector &V) const
{
    if (*this == V)
    {
        return false;
    }
    else
    {
        return true;
    }
}

ColumnVector ColumnVector::operator+(const ColumnVector &V) const
{
    if (V.shape != shape)
    {
        std::cout << "Shape mismatch in vector addition" << std::endl;
        exit(0);
    }

    ColumnVector ret_vec(shape);
    std::vector<double> new_v;

    for (int i = 0; i < shape; i++)
    {
        new_v.push_back(data[i] + V.data[i]);
    }
    ret_vec.data = new_v;
    return ret_vec;
}

ColumnVector ColumnVector::operator+(double d) const
{
    ColumnVector ret_vec(shape);
    std::vector<double> new_v;

    for (int i = 0; i < shape; i++)
    {
        new_v.push_back(data[i] + d);
    }
    ret_vec.data = new_v;
    return ret_vec;
}

ColumnVector ColumnVector::operator*(const ColumnVector &V) const
{
    if (V.shape != shape)
    {
        std::cout << "Shape mismatch in vector multiplication" << std::endl;
        exit(0);
    }

    ColumnVector ret_vec(shape);
    std::vector<double> new_v;

    for (int i = 0; i < shape; i++)
    {
        new_v.push_back(data[i] * V.data[i]);
    }
    ret_vec.data = new_v;
    return ret_vec;
}

ColumnVector ColumnVector::operator*(double d) const
{
    ColumnVector ret_vec(shape);
    std::vector<double> new_v;

    for (int i = 0; i < shape; i++)
    {
        new_v.push_back(data[i] * d);
    }
    ret_vec.data = new_v;
    return ret_vec;
}

ColumnVector ColumnVector::operator-(const ColumnVector &V) const
{
    if (V.shape != shape)
    {
        std::cout << "Shape mismatch in vector subtraction" << std::endl;
        exit(0);
    }

    ColumnVector ret_vec(shape);
    std::vector<double> new_v;

    for (int i = 0; i < shape; i++)
    {
        new_v.push_back(data[i] - V.data[i]);
    }
    ret_vec.data = new_v;
    return ret_vec;
}

ColumnVector ColumnVector::operator-(double d) const
{
    ColumnVector ret_vec(shape);
    std::vector<double> new_v;

    for (int i = 0; i < shape; i++)
    {
        new_v.push_back(data[i] - d);
    }
    ret_vec.data = new_v;
    return ret_vec;
}

ColumnVector ColumnVector::operator/(const ColumnVector &V) const
{
    if (V.shape != shape)
    {
        std::cout << "Shape mismatch in vector division" << std::endl;
        exit(0);
    }

    ColumnVector ret_vec(shape);
    std::vector<double> new_v;

    for (int i = 0; i < shape; i++)
    {
        new_v.push_back(data[i] / V.data[i]);
    }
    ret_vec.data = new_v;
    return ret_vec;
}

ColumnVector ColumnVector::operator/(double d) const
{
    ColumnVector ret_vec(shape);
    std::vector<double> new_v;

    for (int i = 0; i < shape; i++)
    {
        new_v.push_back(data[i] / d);
    }
    ret_vec.data = new_v;
    return ret_vec;
}

/* ------------------
|      DISPLAY      |
-------------------*/

void ColumnVector::push_back(double D)
{
    shape++;
    data.push_back(D);
}

void ColumnVector::print(std::ostream &os) const
{
    os << std::setprecision(2) << "[ ";

    for (int i = 0; i < shape; i++)
    {
        os << data[i];
        if (i < shape - 1)
        {
            os << ",";
        }
    }
    os << " ]" << std::endl;

    os << "Shape: (" << shape << ')' << std::endl;
    os << "Type: Vector" << std::endl;
}

void ColumnVector::print_addresses()
{
    std::cout << "Addresses" << std::endl;
    std::cout << "Shape: " << shape << std::endl;
    std::cout << "Data: " << &data << std::endl;
}

/* ------------------
|        MATH       |
-------------------*/

double ColumnVector::dot(const ColumnVector &V)
{
    if (V.shape != shape)
    {
        std::cout << "Shape mismatch in dot product" << std::endl;
        exit(0);
    }

    double product, sum = 0;

    for (int i = 0; i < shape; i++)
    {
        product = data[i] * V.data[i];
        sum += product;
    }
    return sum;
}

double ColumnVector::get_magnitude() const
{
    double sum;
    for (int i = 0; i < shape; i++)
    {
        sum += std::pow(data[i], 2);
    }
    return std::sqrt(sum);
}

/* ------------------
|    DATA ACCESS    |
-------------------*/

std::vector<double> ColumnVector::get_data() const
{
    return data; // is this going to let us fuck up our data?
}

void ColumnVector::set_data(std::vector<double> vec)
{
    data = vec;
}

int ColumnVector::get_shape() const
{
    return shape;
}