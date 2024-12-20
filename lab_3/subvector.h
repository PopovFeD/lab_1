// subvector.h
#ifndef SUBVECTOR_H
#define SUBVECTOR_H

#include "subvector_exception.h"
#include <iostream>

/**
 * @class subvector
 * @brief Класс, реализующий тип "динамический вектор"
 */
class subvector {
public:
    int *mas; ///< Указатель на массив элементов
    unsigned int top; ///< Текущий размер вектора
    unsigned int capacity; ///< Емкость вектора

public:
    /**
     * @brief Конструктор по умолчанию
     */
    subvector();

    /**
     * @brief Конструктор, инициализирующий вектор с заданной емкостью
     * @param initial_capacity начальная емкость вектора
     */
    subvector(unsigned int initial_capacity);

    /**
     * @brief Конструктор копирования
     * @param other вектор, который будет скопирован
     */
    subvector(const subvector &other);

    /**
     * @brief Конструктор перемещения
     * @param other вектор, который будет перемещен
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
    subvector& operator=(const subvector &other);

    /**
     * @brief Оператор присваивания перемещением
     * @param other вектор, присваиваемый текущему
     * @return ссылка на текущий вектор
     */
    subvector& operator=(subvector &&other) noexcept;

    /**
     * @brief Инициализация пустого вектора
     * @return true, если инициализация прошла успешно
     */
    bool init();

    /**
     * @brief Добавление элемента в конец вектора
     * @param d добавляемый элемент
     * @return true, если добавление прошло успешно
     */
    bool push_back(int d);

    /**
     * @brief Удаление элемента с конца вектора
     * @return значение удаленного элемента
     */
    int pop_back();

    /**
     * @brief Изменение емкости вектора
     * @param new_capacity новая емкость
     * @return true, если изменение прошло успешно
     */
    bool resize(unsigned int new_capacity);

    /**
     * @brief Очистка неиспользуемой памяти
     */
    void shrink_to_fit();

    /**
     * @brief Очистка содержимого вектора
     */
    void clear();
};

#endif //SUBVECTOR_H

