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

int main()
{
    // Scalar Tests
    Scalar sc1;
    Scalar sc2(3.14159);
    
    std::cout << "Printing default scalar, expect uninit data" << std::endl;
    sc1.print();
    std::cout << "Printing scalar constructed with 3.0" << std::endl;
    sc2.print();

    // Vector Tests
    Vector vc1;
    Vector vc2(3);
    double *arr = new double[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
    }
    Vector vc3(5, arr);

    std::cout << "Printing defaul vector, expect uninit data" << std::endl;
    vc1.print();
    std::cout << "Printing length init vector, expect shape (3, 1)" <<std::endl;
    vc2.print();
    std::cout << "Printing fully constructed Vector" << std::endl;
    vc3.print();

    // Matrix tests
    Matrix mt1;
    std::cout << "Printing default Matrix" << std::endl;
    mt1.print();

    Matrix mt2(2, 3);
    std::cout << "Printing size (2,3) init matrix" << std::endl;
    mt2.print();

    double **arr2 = new double*[3];
    for (int i = 0; i < 3; i++)
    {
        arr2[i] = new double[4];
        for (int j = 0; j < 4; j++)
        {
            arr2[i][j] = j;
        }
    }

    std::cout << "Printing populated Matrix" << std::endl;
    Matrix mt3(3, 4, arr2);
    mt3.print();

    // overloaded = and copy constructor
    std::cout << "Testing vector copy constructor" << std::endl;
    double *arr3 = new double[3]();
    Vector v_orig(3, arr3);
    std::cout << "Vector initialized to length 3 with {0, 0, 0}" << std::endl;
    v_orig.print();
    v_orig.print_addresses();

    Vector v_copy(v_orig);
    std::cout << "New Vector using copy constructor" << std::endl;
    v_copy.print();
    v_copy.print_addresses();

    std::cout << "Testing Vector overloaded assignment" << std::endl;
    double *arr4 = new double[4]();
    Vector v_diff(4, arr4);
    std::cout << "Vector initialized to length 4 with {0, 0, 0, 0}" << std::endl;
    v_diff.print();
    v_diff.print_addresses();
    std::cout << "Assigning new vector to original 000 vector" << std::endl;
    v_orig = v_diff;
    v_orig.print();
    v_orig.print_addresses();

    std::cout << "Testing Matrix copy constructor" << std::endl;
    // populate 2d dynamic array for Matrix
    double **arr5 = new double*[3];
    for (int i = 0; i < 3; i++)
    {
        arr5[i] = new double[3];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr5[i][j] = j;
        }
    }
    Matrix m_orig(3, 3, arr5);
    std::cout << "Printing original matrix" << std::endl;
    m_orig.print();
    m_orig.print_addresses();
    std::cout << "Printing copied Matrix" << std::endl;
    Matrix m_copy(m_orig);
    m_copy.print();
    m_copy.print_addresses();

    std::cout << "Testing matrix overloaded assignment" << std::endl;
    Matrix m_diff(3, 4);
    std::cout << "Printing new matrix" << std::endl;
    m_diff.print();
    m_diff.print_addresses();
    m_orig = m_diff;
    std::cout << "Printing original matrix reassigned to new matrix" << std::endl;
    m_orig.print();
    m_orig.print_addresses();

    std::cout << "Tests complete" << std::endl;

    return 0;
}