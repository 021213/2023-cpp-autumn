#include<iostream>

struct Node
{
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(nullptr) {}
	~Node() { data = 0; next = nullptr; }
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data << " ";
		return stream;
	}
};

class LinkedList
{
public:
	LinkedList() : head(nullptr) {}
	~LinkedList() { dispose(); }
	void PushHead(int data); //добавляет элемент в начало списка
	void Insert(int index, int data);
	void PushTail(int data); 
	int PopHead(); // достает элемент из начала списка
	int Extract(int index);
	int PopTail();
	bool IsEmpty() { return head == nullptr; }
	int Length();
	void swap(int a, int b);
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list);
private:
	Node* head;
	void dispose();
	bool indexValid(int index);
	void swapWithHead(int index);
};

int main(int argc, char* argv[])
{
	LinkedList list;
	std::cout << list.PopHead() << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		list.PushHead(i);
	}
	std::cout << list << std::endl;
	while (!list.IsEmpty())
	{
		std::cout << "POPPED : " << list.PopHead() << std::endl;
	}



	int n = 10; // O(1)
	int* a = new int[n] {0};
	for(int i = 0; i < n; ++i) // 1 + (1 + 1 + (1 + (1 + 1 + 3 + 3)*n)) * n = O(n^2)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[i] < a[j])
			{
				std::swap(a[i], a[j]);
			}
		}
	}



	return EXIT_SUCCESS;
}

void LinkedList::PushHead(int data)
{
	head = new Node(data, head);
	//Node* newHead = new Node(data, head);
	//head = newHead;
}

void LinkedList::Insert(int index, int data)
{
	if (index == 0)
	{
		return PushHead(data);
	}
	if (index == Length())
	{
		return PushTail(data);
	}
	if (indexValid(index))
	{
		// 1 2 3 4
		// insert(2, 5)
		// 1 2 5 3 4
		Node* tmp = head;
		for (int i = 0; i < index - 1; ++i)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(data, tmp->next);
	}
}

void LinkedList::PushTail(int data)
{
	if (IsEmpty())
	{
		return PushHead(data);
	}
	Node* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = new Node(data);
}

int LinkedList::PopHead()
{
	if (head == nullptr)
	{
		return -1;
	}
	Node* tmp = head;
	head = head->next;
	int res = tmp->data;
	delete tmp;
	return res;
}

int LinkedList::Extract(int index)
{
	if (index == 0)
	{
		return PopHead();
	}
	if (index == Length() - 1)
	{
		return PopTail();
	}
	if (!indexValid(index))
	{
		return -1;
	}
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i) //нашли элемент, стоящий перед удаляемым
	{
		tmp = tmp->next;
	}
	Node* nres = tmp->next; //нода, которую нужно удалить
	tmp->next = tmp->next->next; // исключили nres из списка
	int res = nres->data; // сохранили данные в отдельной переменной
	delete nres;          // удалили исключенную ноду
	return res;
}

int LinkedList::PopTail()
{
	if (IsEmpty())
	{
		return -1;
	}
	if (head->next == nullptr)
	{
		return PopHead();
	}
	Node* tmp = head;
	while (tmp->next->next != nullptr) // находим предпоследний элемент
	{
		tmp = tmp->next;
	}
	int res = tmp->next->data; // запоминаем значение последнего элемента
	delete tmp->next; //удаляем последний элемент
	tmp->next = nullptr; // обнуляем 
	return res;

	//Node* nres = tmp->next; //нода, которую нужно удалить          nres = tail
	//tmp->next = tmp->next->next; // исключили nres из списка       tmp->next = nullptr
	//int res = nres->data; // сохранили данные в отдельной переменной  res = tail->data
	//delete nres;          // удалили исключенную ноду              delete tail
	//return res;
}

int LinkedList::Length()
{
	int len = 0;
	Node* tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		++len;
	}
	return len;
}

void LinkedList::swap(int a, int b)
{
	if (a == b)
	{
		return;
	}
	if (a > b)
	{
		return swap(b, a);
	}
	if (a == 0)
	{
		return swapWithHead(b);
	}
	//...
}

void LinkedList::dispose()
{
	while (!IsEmpty())
	{
		PopHead();
	}
}

bool LinkedList::indexValid(int index)
{
	return (0 <= index && index < Length());
}

void LinkedList::swapWithHead(int index)
{
	// swapWithHead(3)
	// 1 2 3 4 5
	// 2 3 4 5                      1
	// 2 3 4 1 5
	// 4 2 3 1 5
	Node* tmpHead = head;
	head = head->next;
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		tmp = tmp->next;
	}
	tmpHead->next = tmp->next;
	tmp->next = tmpHead;
	if (index != 1)
	{
		tmp = head;
		for (int i = 0; i < index - 2; ++i)
		{
			tmp = tmp->next;
		}
		Node* newHead = tmp->next;
		tmp->next = tmp->next->next;
		newHead->next = head;
		head = newHead;
	}
}

std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
{
	Node* tmp = list.head;
	while (tmp != nullptr)
	{
		stream << tmp << " ";
		tmp = tmp->next; //tmp = (*tmp).next;
	}
	return stream;
}
