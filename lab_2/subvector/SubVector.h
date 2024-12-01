#ifndef SUBVECTOR_H
#define SUBVECTOR_H

#include <iostream>

/**
 * @class subvector
 * @brief Релизация динамического вектора
 *
 * @details
 *  реализует динамический вектор, который может изменять
 *  свой размер в зависимости от количества добавленных элементов
 */

class subvector
{
public:
    int *mas;
    unsigned int top;
    unsigned int capacity;

public:
    /**
     * @brief Конструктор, инициализирующий пустой вектор
     */
    subvector();

    /**
     * @brief Конструктор, инициализирующий вектор с указанной емкостью
     * @param initial_capacity начальная емкость
     */
    subvector(unsigned int initial_capacity);

    /**
     * @brief Конструктор копирования
     * @param other копируемый вектор
     */
    subvector(const subvector &other);

    /**
     * @brief Конструктор перемещения
     * @param other вектор, перемещаемый в данный
     */
    subvector(subvector &&other) noexcept;

    /**
     * @brief Деструктор
     */
    ~subvector();

    /**
     * @brief Оператор присваивания копированием
     * @param other вектор, присваиваемый текущему
     * @return ссылка на текущий вектор
     */
    subvector &operator=(const subvector &other);

    /**
     * @brief Оператор присваивания перемещением
     * @param other вектор, присваиваемый текущему
     * @return ссылка на текущий вектор
     */
    subvector &operator=(subvector &&other) noexcept;

    /**
     * @brief Инициализация вектора
     * @return true, если инициализация прошла успешно, false - в противном случае
     */
    bool init();

    /**
     * @brief добавление элемента в конец вектора
     * @param d добавляемый элемент
     * @return true, если добавление прошло успешно, false - в противном случае
     */
    bool push_back(int d);

    /**
     * @brief удаление элемента с конца вектора, значение удаленного элемента вернуть (если вектор пустой, вернуть 0)
     * @return значение удаленного элемента
     */
    int pop_back();

    /**
     * @brief изменение емкости вектора
     * @param new_capacity новая емкость
     * @return true, если изменение прошло успешно, false - в противном случае
     */
    bool resize(unsigned int new_capacity);

    /**
     * @brief изменение емкости вектора до минимального значения
     */
    void shrink_to_fit();

    /**
     * @brief очистить содержимое вектора, занимаемое место при этом не меняется
     */
    void clear();
};

#endif
