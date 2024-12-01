// Чтобы сделать list более похожим на класс, давайте инкапсулировать указатель на начальный элемент

template<typename T>
class subforwardlist {

// структура, описывающая узел списка (раньше указатель на неё был самим списком)
struct Node {
     T data;
     Node* next;
     // сюда можете написать что угодно для вашего удобства, нет органичений по списку методов
};

	Node * begin;
//	Node * end; // (опционально !) можете хранить указатель на последний элемент

public:
	// далее описание методов (и только их!)
	void push_back(const T& data); // добавление элемента в конец
	T pop_back();  // удаление элемента с конца (если пустой -- возвращать T{} (default конструирование объекта типа T))
	void push_forward(const T& data); //добавление элемента в начало недосписка
	T pop_forward(); 	//удаление элемента из начала недосписка (если пустой -- возвращать T{} (default конструирование объекта типа T))
	void push_where(unsigned int where, const T& data); //добавление элемента с порядковым номером where
	T erase_where(unsigned int where);	//удаление элемента с порядковым номером where (если пустой -- возвращать T{} (default конструирование объекта типа T))
	unsigned int size(); //определить размер недосписка
	
	// конструктор и операции для правила пяти имею стандатный интерфейс, так что их здесь не описываю.
};
