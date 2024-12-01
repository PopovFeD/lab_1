#ifndef SUBVECTOR_H
#define SUBVECTOR_H

#include <iostream>

class SubVector {
public: //vector_profiler.cpp пытается обратиться к этим переменным
    int *mas;
    unsigned int top;
    unsigned int capacity;

public:
    // Конструкторы
    SubVector();
    SubVector(unsigned int initial_capacity);
    SubVector(const SubVector &other); // Конструктор копирования
    SubVector(SubVector &&other) noexcept; // Конструктор перемещения

    // Деструктор
    ~SubVector();

    // Оператор присваивания
    SubVector& operator=(const SubVector &other); // Оператор присваивания копированием
    SubVector& operator=(SubVector &&other) noexcept; // Оператор присваивания перемещением

    // Методы
    bool init(); // Инициализация пустого недовектора
    bool push_back(int d); // Добавление элемента в конец недовектора
    int pop_back(); // Удаление элемента с конца недовектора
    bool resize(unsigned int new_capacity); // Изменение емкости недовектора
    void shrink_to_fit(); // Очистка неиспользуемой памяти
    void clear(); // Очистка содержимого недовектора
};

#endif // SUBVECTOR_H
