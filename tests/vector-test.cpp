#ifndef H_VECTOR
#define H_VECTOR
#include "../src/ColumnVector.h"
#endif

int main() 
{
    ColumnVector v1;
    ColumnVector v2(3);
    double arr[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
    }
    ColumnVector v3(5, arr);

    std::cout << "Printing v1:" << std::endl;
    v1.print(std::cout);
    std::cout << "Printing v2:" << std::endl;
    v2.print(std::cout);
    std::cout << "Printing v3:" << std::endl;
    v3.print(std::cout);

    std::cout << "Tests Complete!" << std::endl;
}