#include "matrix.h"
#include <iostream>

int main() {
    using namespace matrix_calc;

    Matrix A = create_matrix(2, 2);
    A.data[0][0] = 1.5; A.data[0][1] = 9.2;
    A.data[1][0] = 3.0; A.data[1][1] = -4.5;

    std::cout << "Matrix A:\n";
    print_matrix(A);
    
    std::cout << "Max element: " << matrix_max(A) << "\n";

    free_matrix(A);
    return 0;
}