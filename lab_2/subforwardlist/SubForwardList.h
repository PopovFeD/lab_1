#ifndef SUBFORWARDLIST_H
#define SUBFORWARDLIST_H

class SubForwardList
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    SubForwardList();

    /**
     * @brief Копирующий конструктор
     * @param other вектор, копируемый в текущий
     */
    SubForwardList(const SubForwardList &other);

    /**
     * @brief Перемещающий конструктор
     * @param other вектор, перемещаемый в текущий
     */
    SubForwardList(SubForwardList &&other) noexcept;

    /**
     * @brief Деструктор
     */
    ~SubForwardList();
    ;

    /**
     * @brief Оператор присваивания копированием
     * @param other вектор, присваиваемый текущему
     * @return ссылка на текущий вектор
     */
    SubForwardList &operator=(const SubForwardList &other);

    /**
     * @brief Оператор присваивания перемещением
     * @param other вектор, присваиваемый текущему
     * @return ссылка на текущий вектор
     */
    SubForwardList &operator=(SubForwardList &&other) noexcept;

    /**
     * @brief Добавление элемента в конец
     * @param d добавляемый элемент
     * @return true, если операция прошла успешно
     */
    bool push_back(int d);

    /**
     * @brief Удаление элемента с конца
     * @return удаленный элемент, если операция прошла успешно
     */
    int pop_back();

    /**
     * @brief Добавление элемента в начало
     * @param d добавляемый элемент
     * @return true, если операция прошла успешно
     */
    bool push_forward(int d);

    /**
     * @brief Удаление элемента из начала
     * @return удаленный элемент, если операция прошла успешно
     */
    int pop_forward();

    /**
     * @brief Добавление элемента с порядковым номером where
     * @param where порядковый номер добавляемого элемента
     * @param d добавляемый элемент
     * @return true, если операция прошла успешно
     */
    bool push_where(unsigned int where, int d);

    /**
     * @brief Удаление элемента с порядковым номером where
     * @param where порядковый номер удаляемого элемента
     * @return удаленный элемент, если операция прошла успешно
     */
    int erase_where(unsigned int where);

    /**
     * @brief Определение размера
     * @return размер
     */
    unsigned int size() const;

    /**
     * @brief Очистка
     */
    void clear();

private:
    /**
     * @brief Структура, описывающая узел списка
     */
    struct Node
    {
        int data;
        Node *next;
        Node(int d, Node *n = nullptr) : data(d), next(n) {}
    };

    Node *head;
};

#endif // SUBFORWARDLIST_H
