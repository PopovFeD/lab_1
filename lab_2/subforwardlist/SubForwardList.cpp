#include "subforwardlist.h"
#include <iostream>

/**
 * @brief Конструктор по умолчанию
 *
 * Создает пустой список
 */
subforwardlist::subforwardlist() : head(nullptr) {}

/**
 * @brief Конструктор копирования
 * @param other список, который будет копироваться
 *
 * Создает глубокую копию списка @param other
 */
subforwardlist::subforwardlist(const subforwardlist &other) : head(nullptr)
{
    if (other.head != nullptr)
    {
        head = new Node(other.head->data);
        Node *current = other.head->next;
        Node *last = head;
        while (current != nullptr)
        {
            last->next = new Node(current->data);
            last = last->next;
            current = current->next;
        }
    }
}

/**
 * @brief Конструктор перемещения
 * @param other список, который будет перемещен
 *
 * Создает список, забирая все ресурсы у @param other
 */
subforwardlist::subforwardlist(subforwardlist &&other) noexcept : head(other.head)
{
    other.head = nullptr;
}

/**
 * @brief Деструктор
 *
 * Очищает список
 */
subforwardlist::~subforwardlist()
{
    clear();
}

/**
 * @brief Оператор присваивания копированием
 * @param other список, который будет копироваться
 *
 * Создает глубокую копию списка @param other
 */
subforwardlist &subforwardlist::operator=(const subforwardlist &other)
{
    if (this != &other)
    {
        clear();
        if (other.head != nullptr)
        {
            head = new Node(other.head->data);
            Node *current = other.head->next;
            Node *last = head;
            while (current != nullptr)
            {
                last->next = new Node(current->data);
                last = last->next;
                current = current->next;
            }
        }
    }
    return *this;
}

/**
 * @brief Оператор присваивания перемещением
 * @param other список, который будет перемещен
 *
 * Забирает все ресурсы у @param other
 */
subforwardlist &subforwardlist::operator=(subforwardlist &&other) noexcept
{
    if (this != &other)
    {
        clear();
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

/**
 * @brief добавление элемента в конец списка
 * @param d добавляемый элемент
 *
 * @return true, если добавление прошло успешно, false - в противном случае
 */
bool subforwardlist::push_back(int d)
{
    Node *new_node = new Node(d, nullptr);
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    return true;
}

/**
 * @brief удаление элемента с конца списка
 *
 * @return удаленный элемент, если список не пуст, 0 - в противном случае
 */
int subforwardlist::pop_back()
{
    if (head == nullptr)
    {
        std::cout << "Error: Empty list\n";
        return 0;
    }

    int data;
    if (head->next == nullptr)
    {
        data = head->data;
        delete head;
        head = nullptr;
    }
    else
    {
        Node *current = head;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }
        data = current->next->data;
        delete current->next;
        current->next = nullptr;
    }
    return data;
}

/**
 * @brief добавление элемента в начало списка
 * @param d добавляемый элемент
 *
 * @return true, если добавление прошло успешно, false - в противном случае
 */
bool subforwardlist::push_forward(int d)
{
    Node *new_node = new Node(d, head);
    head = new_node;
    return true;
}

/**
 * @brief удаление элемента из начала списка
 *
 * @return удаленный элемент, если список не пуст, 0 - в противном случае
 */
int subforwardlist::pop_forward()
{
    if (head == nullptr)
    {
        std::cout << "Error: Empty list\n";
        return 0;
    }

    int data = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;
    return data;
}

/**
 * @brief добавление элемента в список по индексу
 * @param where индекс, по которому будет добавлен элемент
 * @param d добавляемый элемент
 *
 * @return true, если добавление прошло успешно, false - в противном случае
 */
bool subforwardlist::push_where(unsigned int where, int d)
{
    if (where == 0)
    {
        return push_forward(d);
    }

    Node *current = head;
    for (unsigned int i = 0; (i < where - 1) && current != nullptr; ++i)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        std::cout << "Error: Out of range\n";
        return false;
    }

    Node *new_node = new Node(d, current->next);
    current->next = new_node;
    return true;
}

/**
 * @brief удаление элемента из списка по индексу
 * @param where индекс, по которому будет удален элемент
 *
 * @return удаленный элемент, если список не пуст, 0 - в противном случае
 */
int subforwardlist::erase_where(unsigned int where)
{
    if (head == nullptr)
    {
        std::cout << "Error: Empty list\n";
        return 0;
    }

    if (where == 0)
    {
        return pop_forward();
    }
    Node *current = head;
    for (unsigned int i = 0; (i < where - 1) && current != nullptr; ++i)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        std::cout << "Error: Out of range\n";
        return 0;
    }

    int data = current->next->data;
    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
    return data;
}

/**
 * @brief возвращает размер списка
 *
 * @return размер списка
 */
unsigned int subforwardlist::size() const
{
    Node *current = head;
    unsigned int count = 0;
    while (current != nullptr)
    {
        ++count;
        current = current->next;
    }
    return count;
}

/**
 * @brief очищает список
 *
 * удаляет все элементы из списка
 */
void subforwardlist::clear()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
