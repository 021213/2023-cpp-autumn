#include<iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;
	Node(int data,
		Node* next = nullptr,
		Node* prev = nullptr)
		: data(data), next(next), prev(prev) {}
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		if (node == nullptr)
		{
			stream << "EMPTY";
		}
		else
		{
			stream << node->data;
		}
		return stream;
	}
};

class CycleList {
public:
	CycleList() : head(nullptr), length(0) {}
	CycleList(const CycleList& list) : head(nullptr), length(0)
	{
		this->head = copy(list.head);
		this->length = list.length;
	}
	CycleList(CycleList&& list) noexcept
	{
		this->length = list.length;
		this->head = list.head;
		list.length = 0;
		list.head = nullptr;
	}

	~CycleList() {
		dispose();
	}
	void PushHead(int data)
	{
		return InsertNode(0, new Node(data));
	}
	void Insert(int index, int data)
	{
		return InsertNode(index, new Node(data));
	}
	void PushTail(int data)
	{
		return InsertNode(Length(), new Node(data));
	}
	int PopHead()
	{
		return PopNode(ExtractNode(0));
	}
	int Extract(int index)
	{
		return PopNode(ExtractNode(index));
	}
	int PopTail()
	{
		return PopNode(ExtractNode(Length() - 1));
	}

	friend std::ostream& operator<<
		(std::ostream& stream, CycleList& list)
	{
		if (list.head == nullptr)
		{
			stream << "EMPTY";
		}
		else
		{
			Node* temp = list.head;
			do
			{
				stream << temp << " ";
				temp = temp->next;
			} while (temp != list.head);
		}
		return stream;
	}

	bool IsEmpty()
	{
		return head == nullptr;
	}

	int Length()
	{
		return length;
	}

	void swap(int ind1, int ind2)
	{
		if (!IndexValid(ind1) || !IndexValid(ind2) || ind1 == ind2)
		{
			return;
		}
		if (ind1 < ind2)
		{
			return swap(ind2, ind1);
		}

		Node* node1 = ExtractNode(ind1);
		Node* node2 = ExtractNode(ind2);

		InsertNode(ind2, node1);
		InsertNode(ind1, node2);
	}
	void sort()
	{
		int i = 0;
		for (Node* inode = this->head;
			i < this->length;
			inode = inode->next, ++i) {
			int j = i + 1;
			for (Node* jnode = inode->next;
				j < this->length;
				jnode = jnode->next, ++j) {
				if (inode->data > jnode->data) {
					swap(i, j);
				}
			}
		}
	}
	void reverse()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}

		CycleList reversedList;

		while (!IsEmpty()) {
			Node* node = ExtractNode(0);
			reversedList.InsertNode(0, node);
		}

		head = reversedList.head;
		reversedList.head = nullptr;
	}
	friend CycleList operator+(int data, CycleList list)
	{
		list.PushHead(data);
		return list;
	}
	friend CycleList operator+(CycleList list, int data)
	{
		list.PushTail(data);
		return list;
	}
	friend CycleList operator+(
		CycleList list,
		CycleList add)
	{
		list.length += add.length;
		if (list.head == nullptr)
		{
			list.head = add.head;
		}
		else if (add.head != nullptr) //todo: проверить если add.length == 1
		{
			Node* head1 = list.head;
			Node* tail1 = list.head->prev;
			Node* head2 = add.head;
			Node* tail2 = add.head->prev;
			head1->prev = tail2;
			tail2->next = head1;
			tail1->next = head2;
			head2->prev = tail1;
		}
		add.head = nullptr;
		add.length = 0;
		return list;
	}
	friend CycleList operator+=(CycleList list, int data)
	{
		list.PushTail(data);
		return list;
	}
	friend CycleList operator+=(CycleList list, CycleList add)  //todo:check and fix
	{
		return list + add;
	}
	friend bool operator==(CycleList& list1, CycleList& list2)
	{
		if (list1.Length() != list2.Length())
		{
			return false;
		}

		Node* temp1 = list1.head;
		Node* temp2 = list2.head;

		while (temp1 != list1.head) {
			if (temp1->data != temp2->data)
			{
				return false;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return true;
	}
	CycleList& operator=(CycleList& src)
	{
		if (this != &src)
		{
			dispose();
			this->head = copy(src.head);
			this->length = src.length;
		}
		return *this;
	}

private:
	Node* head;
	int length;
	bool IndexValid(int index)
	{
		return 0 <= index && index < Length();
	}
	void InsertNode(int index, Node* node)
	{
		if (!IndexValid(index) && index != Length())
		{
			delete node;
			return;
		}
		++length;
		if (head == nullptr)
		{
			head = node;
			node->next = node->prev = node;
			return;
		}
		if (index == 0)
		{
			node->next = head;
			node->prev = head->prev;
			head->prev->next = node;
			head->prev = node;
			head = node;
			return;
		}
		Node* temp = head;
		while (index > 1)
		{
			temp = temp->next;
			--index;
		}
		node->next = temp->next;
		node->prev = temp;
		node->next->prev = node;
		temp->next = node;
	}
	Node* ExtractNode(int index)
	{
		if (IsEmpty() || !IndexValid(index))
		{
			return nullptr;
		}
		--length;
		if (head->next == head)
		{
			Node* res = head;
			head = nullptr;
			return res;
		}
		if (index == 0)
		{
			Node* res = head;
			head = head->next;
			res->prev->next = head;
			head->prev = res->prev;
			return res;
		}
		Node* temp = head;
		while (index > 1)
		{
			temp = temp->next;
			--index;
		}
		Node* res = temp->next;
		temp->next = temp->next->next;
		temp->next->prev = temp;
		return res;
	}
	int PopNode(Node* node)
	{
		int data = 0;
		if (node != nullptr)
		{
			data = node->data;
			delete node;
		}
		return data;
	}
	void dispose()
	{
		while (!IsEmpty())
		{
			PopHead();
		}
	}
	Node* copy(Node* src)
	{
		if (src == nullptr)
		{
			return nullptr;
		}
		Node* dst = new Node(src->data);
		dst->next = dst->prev = dst;
		Node* temp = src->next;
		while (src != temp)
		{
			dst->next = new Node(src->data, dst->next, dst);
			dst = dst->next;
			src = src->next;
		}
		return dst;
	}
};

int main(int argc, char* argv[])
{
	CycleList v;
	v.PushHead(1);
	v.PushHead(2);
	v.PushHead(3);
	v.PushHead(4);
	v.PushHead(5);
	std::cout << v << std::endl;
	while (!v.IsEmpty())
	{
		std::cout << v.PopHead() << " ";
	}
	std::cout << std::endl;

	v.PushTail(1);
	v.PushTail(2);
	v.PushTail(3);
	v.PushTail(4);
	v.PushTail(5);
	std::cout << v << std::endl;
	while (!v.IsEmpty())
	{
		std::cout << v.PopTail() << " ";
	}
	std::cout << std::endl;

	v.PushTail(1);
	v.PushTail(2);
	v.PushTail(3);
	v.PushTail(4);
	v.PushTail(5);
	v.Insert(4, 14);
	v.Insert(5, 15);
	v.Insert(2, 12);
	v.Insert(0, 10);
	v.Insert(9, 17);
	std::cout << v << std::endl;
	std::cout << v.Extract(3) << " -> " << v << std::endl;
	std::cout << v.Extract(0) << " -> " << v << std::endl;
	std::cout << v.Extract(7) << " -> " << v << std::endl;

	return EXIT_SUCCESS;
}