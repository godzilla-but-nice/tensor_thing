#include <iostream>
#include <iomanip>
#include <cstring>

class ColumnVector
{
public:
    // CONSTRUCTORS
    ColumnVector();                    // default constructor
    ColumnVector(int);                 // constructor for set shape
    ColumnVector(int, const double *); // constructor for pointer to array and shape
    ColumnVector(const ColumnVector &);      // copy
    // DESTRUCTOR
    ~ColumnVector(); // handle leaky memory
    // OPERATORS
    ColumnVector &operator=(const ColumnVector &);
    ColumnVector &operator+(const ColumnVector &); // element-wise addition
    // FUNCTIONS
    void print(std::ostream &os) const;
    double *get_data() const;
    void set_data(const double *);

    // testing
    void print_addresses(); // print pointer addresses
private:
    double *allocate();            // allocate memory for ColumnVector
    void deep_copy(const double *); // fill values from pointer to 1d array
    double *data;
    int shape;
};