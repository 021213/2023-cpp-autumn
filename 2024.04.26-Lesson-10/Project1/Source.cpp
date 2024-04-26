#include<iostream>

struct BiNode {
	int data;
	BiNode* next;
	BiNode* prev;
	BiNode(int data,
		BiNode* next = nullptr,
		BiNode* prev = nullptr)
		: data(data), next(next), prev(prev) {}
	friend std::ostream& operator<<(std::ostream& stream, BiNode*& node)
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

class BiLinkedList {
public:
	BiLinkedList() : head(nullptr), tail(nullptr), length(0) {}
	BiLinkedList(const BiLinkedList& list) : head(nullptr), tail(nullptr), length(0)
	{
		this->head = copy(list.head);
		this->tail = head;
		if (this->tail != nullptr)
		{
			while (this->tail->next != nullptr)
			{
				this->tail = this->tail->next;
			}
		}
		this->length = list.length;
	}
	BiLinkedList(BiLinkedList&& list) noexcept
	{
		this->length = list.length;
		this->head = list.head;
		this->tail = list.tail;
		list.length = 0;
		list.head = nullptr;
		list.tail = nullptr;
	}

	~BiLinkedList() {
		dispose();
	}
	void PushHead(int data)
	{
		return InsertBiNode(0, new BiNode(data));
	}
	void Insert(int index, int data)
	{
		return InsertBiNode(index, new BiNode(data));
	}
	void PushTail(int data)
	{
		return InsertBiNode(Length(), new BiNode(data));
	}
	int PopHead()
	{
		return PopBiNode(ExtractBiNode(0));
	}
	int Extract(int index)
	{
		return PopBiNode(ExtractBiNode(index));
	}
	int PopTail()
	{
		return PopBiNode(ExtractBiNode(Length() - 1));
	}

	friend std::ostream& operator<<
		(std::ostream& stream, BiLinkedList& list)
	{
		BiNode* temp = list.head;
		while (temp != nullptr)
		{
			stream << temp << " ";
			temp = temp->next;
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

		BiNode* BiNode1 = ExtractBiNode(ind1);
		BiNode* BiNode2 = ExtractBiNode(ind2);

		InsertBiNode(ind2, BiNode1);
		InsertBiNode(ind1, BiNode2);
	}
	void sort()
	{
		int i = 0;
		for (BiNode* iBiNode = head;
			iBiNode != nullptr;
			iBiNode = iBiNode->next, ++i) {
			int j = i + 1;
			for (BiNode* jBiNode = iBiNode->next;
				jBiNode != nullptr;
				jBiNode = jBiNode->next, ++j) {
				if (iBiNode->data > jBiNode->data) {
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

		tail = head;
		BiLinkedList reversedList;

		while (!IsEmpty()) {
			BiNode* node = ExtractBiNode(0);
			reversedList.InsertBiNode(0, node);
		}

		head = reversedList.head;
		reversedList.head = nullptr;
	}
	friend BiLinkedList operator+(int data, BiLinkedList list)
	{
		list.PushHead(data);
		return list;
	}
	friend BiLinkedList operator+(BiLinkedList list, int data)
	{
		list.PushTail(data);
		return list;
	}
	friend BiLinkedList operator+(
		BiLinkedList list,
		BiLinkedList add)
	{
		list.length += add.length;
		if (list.head == nullptr)
		{
			list.head = add.head;
			list.tail = add.tail;
		}
		else if (add.head != nullptr)
		{
			list.tail->next = add.head;
			add.head->prev = list.tail;
			list.tail = add.tail;
		}
		add.tail = add.head = nullptr;
		add.length = 0;
		return list;
	}
	friend BiLinkedList operator+=(BiLinkedList list, int data)
	{
		list.PushTail(data);
		return list;
	}
	friend BiLinkedList operator+=(BiLinkedList list, BiLinkedList add)  //todo:check and fix
	{
		return list + add;
	}
	friend bool operator==(BiLinkedList& list1, BiLinkedList& list2)
	{
		if (list1.Length() != list2.Length())
		{
			return false;
		}

		BiNode* temp1 = list1.head;
		BiNode* temp2 = list2.head;

		while (temp1 != nullptr) {
			if (temp1->data != temp2->data)
			{
				return false;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return true;
	}
	BiLinkedList& operator=(BiLinkedList& src)
	{
		if (this != &src)
		{
			dispose();
			this->head = copy(src.head);
			this->tail = this->head;
			if (this->tail != nullptr)
			{
				while (this->tail->next != nullptr)
				{
					this->tail = this->tail->next;
				}
			}
			this->length = src.length;
		}
		return *this;
	}

private:
	BiNode* head;
	BiNode* tail;
	int length;
	bool IndexValid(int index)
	{
		return 0 <= index && index < Length();
	}
	void InsertBiNode(int index, BiNode* node)
	{
		if (!IndexValid(index) && index != Length())
		{
			delete node;
			return;
		}
		++length;
		if (head == nullptr)
		{
			node->next = node->prev = nullptr;
			tail = head = node;
			return;
		}
		if (index == 0)
		{
			node->next = head;
			node->prev = nullptr;
			head->prev = node;
			head = node;
			tail = head;
			return;
		}
		BiNode* temp = head;
		while (index > 1)
		{
			temp = temp->next;
			--index;
		}
		node->next = temp->next;
		node->prev = temp;
		temp->next = node;
		if (node->next != nullptr)
		{
			node->next->prev = node;
		}
		else
		{
			tail = node;
		}
	}
	BiNode* ExtractBiNode(int index)
	{
		if (IsEmpty() || !IndexValid(index))
		{
			return nullptr;
		}
		--length;
		if (head->next == nullptr)
		{
			BiNode* res = head;
			head = tail = nullptr;
			return res;
		}
		if (index == 0)
		{
			BiNode* res = head;
			head = head->next;
			head->prev = nullptr;
			return res;
		}
		if (index == length)
		{
			BiNode* res = tail;
			tail = tail->prev;
			tail->next = nullptr;
			return res;
		}
		BiNode* temp = head;
		while (index > 1)
		{
			temp = temp->next;
			--index;
		}
		BiNode* res = temp->next;
		temp->next = temp->next->next;
		temp->next->prev = temp;
		return res;
	}
	int PopBiNode(BiNode* node)
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
	BiNode* copy(BiNode* src)
	{
		if (src == nullptr)
		{
			return nullptr;
		}
		BiNode* dst = new BiNode(src->data);
		src = src->next;
		while (src != nullptr)
		{
			dst->next = new BiNode(src->data, nullptr, dst);
			dst = dst->next;
			src = src->next;
		}
		return dst;
	}
};

int main(int argc, char* argv[])
{
	BiLinkedList v;
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

	BiLinkedList list1;

	return EXIT_SUCCESS;
}