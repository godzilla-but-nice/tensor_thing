#ifndef H_VECTOR
#define H_VECTOR
#include "../src/ColumnVector.h"
#endif

int main()
{
    // initialize two vectors
    std::vector<double> arr;
    for (int i = 0; i < 3; i++)
    {
        arr.push_back(1);
    }
    ColumnVector v_ones(arr);
    for (int i = 0; i < 3; i++)
    {
        arr[i] = i + 1;
    }
    ColumnVector v1(arr);
    ColumnVector v2(arr);

    std::cout << "Printing v1:" << std::endl;
    v1.print(std::cout);
    std::cout << "Printing v2:" << std::endl;
    v2.print(std::cout);

    std::cout << "Building test vectors" << std::endl;
    // more vectors for testing
    ColumnVector v_zeros(3);
    for (int i = 0; i < 3; i++) {arr[i] = 2.0;}
    ColumnVector v_twos(arr);
    ColumnVector v_res;
    
    std::cout << "All vectors initialized!" << std::endl;
    std::cout << "test results: " << std::endl;
    std::cout << "--------------------------------" << std::endl;

    bool eq_operator = v1 == v2;
    std::cout << "equality operator: " << eq_operator << std::endl;
    v_res = v_zeros + 1;
    bool sc_add = v_res == v_ones;
    std::cout << "Scalar Add:        " << sc_add << std::endl;
    v_res = v_ones + v_ones;
    bool vc_add = v_res == v_twos;
    std::cout << "Vector add:        " << vc_add << std::endl;
    v_res = v_ones * 2;
    bool sc_mult = v_res == v_twos;
    std::cout << "Scalar Multiply:   " << sc_mult << std::endl;
    v_res = v_ones * v_twos;
    bool vc_mult = v_res == v_twos;
    std::cout << "Vector Multiply:   " << vc_mult << std::endl;
    v_res = v_twos - 1;
    bool sc_sub = v_res == v_ones;
    std::cout << "Scalar Subtract:   " << sc_sub << std::endl;
    v_res = v1 - v2;
    bool vc_sub = v_res == v_zeros;
    std::cout << "Vector Subtract:   " << vc_sub << std::endl;
    v_res = v_twos / 2;
    bool sc_div = v_res == v_ones;
    std::cout << "Scalar Divide:     " << sc_div << std::endl;
    v_res = v_twos / v_twos;
    bool vc_div = v_res == v_ones;
    std::cout << "Vector Divide:     " << vc_div << std::endl;

    double mag = v1.get_magnitude();
    bool mag_test = mag == std::sqrt(14);
    std::cout << "Magnitude:         " << mag_test << std::endl;
    double dot = v_ones.dot(v_twos);
    bool dot_test = dot == 6;
    std::cout << "Dot Product:       " << dot_test << std::endl;

    
    std::cout << "Tests Complete!" << std::endl;
}