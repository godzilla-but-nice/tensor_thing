#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>

class ColumnVector
{
public:
    // CONSTRUCTORS
    ColumnVector();                    // default constructor
    ColumnVector(size_t);                 // constructor for set shape
    ColumnVector(size_t, std::vector<double>); // constructor for pointer to array and shape
    ColumnVector(const ColumnVector &);// copy
    
    // OPERATORS
    ColumnVector &operator=(const ColumnVector &);
    bool operator==(const ColumnVector&);
    ColumnVector operator+(const ColumnVector &); // element-wise addition
    ColumnVector operator+(double);               // e-w scalar addition
    ColumnVector operator*(const ColumnVector &); // element-wise multiplication
    ColumnVector operator*(double);               // e-w scalar multiplication
    ColumnVector operator-(const ColumnVector &); // element-wise subtraction
    ColumnVector operator-(double);               // e-w scalar subtraction
    ColumnVector operator/(const ColumnVector &); // element-wise division
    ColumnVector operator/(double);               // e-w scalar division
    
    // FUNCTIONS
    void print(std::ostream &os) const;
    std::vector<double> get_data() const;
    void set_data(std::vector<double>);
    int get_shape() const;

    // MATH
    double dot(const ColumnVector&);
    double get_magnitude() const;
    // double euc_dist(const ColumnVector&) const; // NOT IMPLEMENTED YET

    // testing
    void print_addresses();         // print pointer addresses
private:
    std::vector<double> data;
    size_t shape;
};