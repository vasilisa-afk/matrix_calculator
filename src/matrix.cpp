#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>


Matrix create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive");
   
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        mat.data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) mat.data[i][j] = 0.0;
    }
    return mat;
}

void free_matrix(Matrix m) {
    if (m.data == nullptr) return;
    for (int i = 0; i < m.rows; ++i) {
        delete[] m.data[i];
    }
    delete[] m.data;
}

void print_matrix(Matrix m) {
    if (m.data == nullptr) return;
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            std::cout << std::setw(6) << m.data[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Ваша реализация (Вариант 2)
double matrix_max(Matrix m) {
    if (m.data == nullptr || m.rows <= 0 || m.cols <= 0) return 0.0;
    double max_val = m.data[0][0];
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            if (m.data[i][j] > max_val) max_val = m.data[i][j];
        }
    }
    return max_val;
}

} // namespace matrix_calc
