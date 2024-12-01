#ifndef SUBFORWARDLIST_H
#define SUBFORWARDLIST_H

class SubForwardList {
public:
    // Конструкторы
    SubForwardList();
    SubForwardList(const SubForwardList& other); // Конструктор копирования
    SubForwardList(SubForwardList&& other) noexcept; // Конструктор перемещения

    // Деструктор
    ~SubForwardList();;

    // Операторы присваивания
    SubForwardList& operator=(const SubForwardList& other); // Оператор присваивания копированием
    SubForwardList& operator=(SubForwardList&& other) noexcept; // Оператор присваивания перемещением

    // Методы
    bool push_back(int d);
    int pop_back();
    bool push_forward(int d);
    int pop_forward();
    bool push_where(unsigned int where, int d);
    int erase_where(unsigned int where);
    unsigned int size() const;
    void clear();

private:
    struct Node {
        int data;
        Node* next;
        Node(int d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* head;
};

#endif // SUBFORWARDLIST_H
