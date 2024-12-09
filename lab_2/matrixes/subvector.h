#ifndef SUBVECTOR_H
#define SUBVECTOR_H

#include <iostream>

/**
 * @brief Класс, реализующий тип "динамический вектор"
 */
class subvector
{
public:
    int *mas;
    unsigned int top;
    unsigned int capacity;

public:
    subvector();
    /**
     * @brief Конструктор, инициализирующий вектор с указанной емкостью
     * @param initial_capacity начальная емкость вектора
     */
    subvector(unsigned int initial_capacity);
    /**
     * @brief Конструктор копирования
     * @param other вектор, копируемый в создаваемый
     */
    subvector(const subvector &other);
    /**
     * @brief Конструктор перемещения
     * @param other вектор, перемещаемый в создаваемый
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
     * @brief инициализация пустого вектора
     * @return true, если инициализация прошла успешно, false - в противном случае
     */
    bool init();
    /**
     * @brief добавление элемента в конец вектора с выделением дополнительной памяти при необходимости
     * @param d добавляемый элемент
     * @return true, если добавление прошло успешно, false - в противном случае
     */
    bool push_back(int d);
    /**
     * @brief удаление элемента с конца вектора, значение удаленного элемента вернуть (если пустой, вернуть ноль)
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
     * @brief очистить неиспользуемую память, переехав на новое место с уменьшением capacity до top
     */
    void clear();
};

#endif // SUBVECTOR_H
