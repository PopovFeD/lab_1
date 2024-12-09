#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include "subvector.h"

/**
 * @class matrix
 * @brief Класс, реализующий матрицу
 */
class matrix
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    matrix();

    /**
     * @brief Конструктор для создания матрицы заданного размера
     * @param rows количество строк
     * @param cols количество столбцов
     */
    matrix(size_t rows, size_t cols);

    /**
     * @brief Конструктор для создания подматрицы из другой матрицы
     * @param other исходная матрица
     * @param skip_row индекс строки, которую нужно пропустить
     * @param skip_col индекс столбца, который нужно пропустить
     */
    matrix(const matrix &other, size_t skip_row, size_t skip_col);

    /**
     * @brief Получить количество строк в матрице
     * @return количество строк
     */
    size_t rows() const { return m_rows; }

    /**
     * @brief Получить количество столбцов в матрице
     * @return количество столбцов
     */
    size_t cols() const { return m_cols; }

    /**
     * @brief Оператор доступа к элементу матрицы
     * @param i индекс строки
     * @param j индекс столбца
     * @return ссылка на элемент
     */
    int &operator()(size_t i, size_t j);

    /**
     * @brief Оператор доступа к элементу матрицы (константный)
     * @param i индекс строки
     * @param j индекс столбца
     * @return ссылка на элемент
     */
    const int &operator()(size_t i, size_t j) const;

private:
    size_t m_rows; ///< количество строк
    size_t m_cols; ///< количество столбцов
    subvector data; ///< данные матрицы

    friend int Determinant(const matrix &M); ///< функция для вычисления детерминанта
};

#endif // MATRIX_H
