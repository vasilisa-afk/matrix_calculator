#include <gtest/gtest.h>
#include "matrix.h"

using namespace matrix_calc;

TEST(MatrixTest, MaxElement_NormalCase) {
    Matrix A = create_matrix(2, 2);
    A.data[0][0] = 1.0; A.data[0][1] = 5.0;
    A.data[1][0] = 3.0; A.data[1][1] = 2.0;
    EXPECT_DOUBLE_EQ(matrix_max(A), 5.0);
    free_matrix(A);
}

TEST(MatrixTest, MaxElement_EmptyMatrix) {
    Matrix empty;
    empty.data = nullptr;
    empty.rows = 0;
    empty.cols = 0;
    EXPECT_DOUBLE_EQ(matrix_max(empty), 0.0);
}