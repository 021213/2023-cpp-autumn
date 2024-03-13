#include<iostream>

struct ArrayList {
	int size;
	int capacity;
	int* data;

	ArrayList(int capacity = 10) :
		size(0),
		capacity(capacity),
		data(new int[capacity] { 0 })
	{}/*
	ArrayList(int capacity = 10)
	{
		this->size = 0;
		this->capacity = capacity;
		this->data = new int[capacity] { 0 };
	}*/
	//todo: конструктор копирования
	~ArrayList()
	{
		delete[] data;
	}

	void push_back(int el)
	{
		insert(el, size);
	}
	void push_start(int el)
	{
		insert(el, 0);
	}
	int pop_back()
	{
		return extract(size - 1);
	}
	int pop_start()
	{
		return extract(0);
	}

	void insert(int el, int index)
	{
		if (index > size || index < 0)
		{
			return;
		}
		if (size == capacity)
		{
			expand();
		}
		for (int i = size; i > index; --i)
		{
			data[i] = data[i - 1];
		}
		data[index] = el;
		size++;
	}
	int extract(int index)
	{
		if (index >= size || index < 0)
		{
			return -1;
		}
		int res = data[index];
		for (int i = index; i < size - 1; ++i)
		{
			data[i] = data[i + 1];
		}
		size--;
		return res;
	}
	void expand(int add = 0)
	{
		add = (add == 0 ? capacity : add);
		int* newdata = new int[capacity + add] { 0 };
		for (int i = 0; i < size; ++i)
		{
			newdata[i] = data[i];
		}
		delete[] data;
		data = newdata;
		capacity += add;
	}
	void contract()
	{
		int* newdata = new int[size] { 0 };
		for (int i = 0; i < size; ++i)
		{
			newdata[i] = data[i];
		}
		delete[] data;
		data = newdata;
		capacity = size;
	}

	void print()
	{
		std::cout << size << "/" << capacity << ": ";
		for (int i = 0; i < size; ++i)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main(int argc, char* argv[])
{
	ArrayList list(2);
	list.print();
	list.push_back(3);
	list.push_back(5);
	list.push_back(6);
	list.print();
	list.push_start(2);
	list.push_start(1);
	list.insert(4, 3);
	list.print();
	std::cout << list.extract(3) << std::endl;
	std::cout << list.pop_back() << std::endl;
	std::cout << list.pop_start() << std::endl;
	list.print();

	return EXIT_SUCCESS;
}