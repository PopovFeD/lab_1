/**
 * @class SubVector
 * @brief Класс, реализующий тип "динамический вектор"
 */

#include "SubVector.h"

/**
 * @brief Конструктор, инициализирующий пустой вектор
 */
SubVector::SubVector() : mas(nullptr), top(0), capacity(0) {}

/**
 * @brief Конструктор, инициализирующий вектор с заданной емкостью
 * @param initial_capacity начальная емкость вектора
 */
SubVector::SubVector(unsigned int initial_capacity) : mas(new int[initial_capacity]), top(0), capacity(initial_capacity) {}

/**
 * @brief Копирующий конструктор
 * @param other вектор, копируемый в текущий
 */
SubVector::SubVector(const SubVector &other) : mas(new int[other.capacity]), top(other.top), capacity(other.capacity)
{
    for (unsigned int i = 0; i < top; ++i)
    {
        mas[i] = other.mas[i];
    }
}

/**
 * @brief Перемещающий конструктор
 * @param other вектор, перемещаемый в текущий
 */
SubVector::SubVector(SubVector &&other) noexcept : mas(other.mas), top(other.top), capacity(other.capacity)
{
    other.mas = nullptr;
    other.top = 0;
    other.capacity = 0;
}

/**
 * @brief Деструктор
 */
SubVector::~SubVector()
{
    delete[] mas;
}

/**
 * @brief Оператор присваивания копированием
 * @param other вектор, присваиваемый текущему
 * @return ссылка на текущий вектор
 */
SubVector &SubVector::operator=(const SubVector &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] mas;

    mas = new int[other.capacity];
    top = other.top;
    capacity = other.capacity;

    for (unsigned int i = 0; i < top; ++i)
    {
        mas[i] = other.mas[i];
    }

    return *this;
}

/**
 * @brief Оператор присваивания перемещением
 * @param other вектор, присваиваемый текущему
 * @return ссылка на текущий вектор
 */
SubVector &SubVector::operator=(SubVector &&other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    delete[] mas;

    mas = other.mas;
    top = other.top;
    capacity = other.capacity;

    other.mas = nullptr;
    other.top = 0;
    other.capacity = 0;

    return *this;
}

/**
 * @brief инициализация пустого вектора
 * @return true, если инициализация прошла успешно, false - в противном случае
 */
bool SubVector::init()
{
    mas = nullptr;
    capacity = 0;
    top = 0;
    return true;
}

/**
 * @brief добавление элемента в конец вектора
 * @param d добавляемый элемент
 * @return true, если добавление прошло успешно, false - в противном случае
 */
bool SubVector::push_back(int d)
{
    if (top == capacity)
    {
        unsigned int new_capacity = capacity == 0 ? 1 : capacity * 2;
        if (!resize(new_capacity))
        {
            return false;
        }
    }

    mas[top] = d;
    top++;
    return true;
}

/**
 * @brief удаление элемента с конца вектора
 * @return удаленный элемент
 */
int SubVector::pop_back()
{
    if (top == 0)
    {
        std::cout << "Error: empty vector\n";
        return 0;
    }
    top--;
    return mas[top];
}

/**
 * @brief изменение емкости вектора
 * @param new_capacity новая емкость
 * @return true, если изменение прошло успешно, false - в противном случае
 */
bool SubVector::resize(unsigned int new_capacity)
{
    int *new_mas = new int[new_capacity];

    for (unsigned int i = 0; i < top; ++i)
    {
        new_mas[i] = mas[i];
    }

    delete[] mas;

    mas = new_mas;
    capacity = new_capacity;

    return true;
}

/**
 * @brief изменение емкости вектора до минимального значения
 */
void SubVector::shrink_to_fit()
{
    resize(top);
}

/**
 * @brief очистка содержимого вектора
 */
void SubVector::clear()
{
    top = 0;
}
