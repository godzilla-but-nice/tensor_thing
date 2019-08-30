#ifndef H_MATRIX
#define H_MATRIX
#include "../src/Matrix.h"
#endif

#ifndef H_VECTOR
#define H_VECTOR
#include "../src/ColumnVector.h"
#endif

int main()
{
    std::cout << "Making 3 col vecs..." << std::endl;
    ColumnVector col1 = ColumnVector(std::vector<double>{1, 1, 1});
    ColumnVector col2 = ColumnVector(std::vector<double>{2, 2, 2});
    ColumnVector col3 = ColumnVector(std::vector<double>{3, 3, 3});

    std::cout << "Making a std::vector and pushing col vecs..." << std::endl;
    std::vector<ColumnVector> vec;
    vec.push_back(col1);
    vec.push_back(col2);
    vec.push_back(col3);

    std::cout << std::endl << "Making matrix from vec..." << std::endl;
    Matrix mat = Matrix(vec);
    mat.print(std::cout);

    std::cout << std::endl << "copying matrix..." << std::endl;
    Matrix mat2 = Matrix(mat);
    mat2.print(std::cout);

    (mat + mat2).print(std::cout);
    (mat - mat2).print(std::cout);
    (mat * mat2).print(std::cout);

    std::cout << std::endl << "doing dot product..." << std::endl;
    ColumnVector dot_result = mat.dot(col1);
    dot_result.print(std::cout);

    std::cout << std::endl << "matrix.mult..." << std::endl;
    Matrix mult_result = mat.mult(mat2);

    std::cout << std::endl << "printing result..." << std::endl;
    mult_result.print(std::cout);
}