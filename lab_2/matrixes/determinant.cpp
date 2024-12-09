#include "matrix.h"
#include <stdexcept>
#include <cmath>
#include <vector>

/**
 * @brief Вычисление детерминанта матрицы с помощью LU-разложения
 * @param A матрица
 * @return детерминант матрицы
 * @throw std::runtime_error если матрица не квадратная
 */
int determinant(const matrix &A)
{
    size_t n = A.rows();
    if (A.rows() != A.cols())
        throw std::runtime_error("Determinant is defined only for square matrix.");
    if (n == 0)
        return 1;

    std::vector<std::vector<double>> M(n, std::vector<double>(n, 0.0));
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            M[i][j] = static_cast<double>(A(i, j));

    double sign = 1.0;
    for (size_t k = 0; k < n; ++k)
    {
        double pivot = std::abs(M[k][k]);
        size_t pivot_row = k;
        for (size_t i = k + 1; i < n; ++i)
        {
            if (std::abs(M[i][k]) > pivot)
            {
                pivot = std::abs(M[i][k]);
                pivot_row = i;
            }
        }

        if (pivot < 1e-12)
            return 0;

        if (pivot_row != k)
        {
            std::swap(M[k], M[pivot_row]);
            sign = -sign;
        }

        for (size_t i = k + 1; i < n; ++i)
        {
            double factor = M[i][k] / M[k][k];
            M[i][k] = 0.0;
            for (size_t j = k + 1; j < n; ++j)
                M[i][j] -= factor * M[k][j];
        }
    }

    double det = sign;
    for (size_t i = 0; i < n; ++i)
        det *= M[i][i];

    return static_cast<int>(std::round(det));
}
