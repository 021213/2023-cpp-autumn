#include<iostream>

struct ArrayList {
	int size;
	int capacity;
	int* data;
	
	ArrayList(int capacity = 10) :
		size(0),
		capacity(10),
		data(new int[capacity] { 0 })
	{}
	//todo: конструктор копирования
	~ArrayList()
	{
		delete[] data;
	}

	void push_back(int el);
	void push_start(int el);
	void insert(int el, int pos);

	void pop_back();
	void pop_start();
	void extract(int pos);

	void expand(int add = 0);
	void contract();

	void print();
};

int main(int argc, char* argv[])
{

	return EXIT_SUCCESS;
}