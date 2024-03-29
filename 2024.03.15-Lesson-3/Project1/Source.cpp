#include<iostream>
#include<string>

template<typename T>
struct ArrayList
{
	T* data;
	int capacity;
	int size;

	ArrayList(int capacity = 5) :
		data(new T[capacity]), capacity(capacity), size(0)
	{
	}
	ArrayList(const ArrayList& src) :
		data(new T[src.size]), capacity(src.size), size(src.size)
	{
		std::cout << "copy constructor" << std::endl;
		for (int i = 0; i < size; data[i] = src.data[i++]);
	}
	~ArrayList()
	{
		std::cout << "destructor" << std::endl;
		delete[] data;
	}

	void expand(int add = 0)
	{
		add = (add == 0 ? capacity : add);
		T* newdata = new T[capacity + add];
		for (int i = 0; i < size; newdata[i] = data[i++]);
		delete[] data;
		capacity += add;
		data = newdata;
	}
	void push_back(T val)
	{
		if (size == capacity)
		{
			expand();
		}
		data[size++] = val;
	}
	void print()
	{
		std::cout << "[" << size << "/" << capacity << "]: ";
		for (int i = 0; i < size; ++i)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};

void CopyConstructorTest1(ArrayList<int> list)
{
	std::cout << "TEST1 start" << std::endl;
	list.print();
	list.push_back(50);
	list.data[0] = 1000;
	list.print();
	std::cout << "TEST1 end" << std::endl;
}

void CopyConstructorTest1(ArrayList<std::string> list)
{
	std::cout << "TEST1 start" << std::endl;
	list.print();
	list.push_back("Vasya");
	list.data[0] = "Petya";
	list.print();
	std::cout << "TEST1 end" << std::endl;
}

int main()
{
	ArrayList <int> intList;
	intList.push_back(1);
	intList.push_back(2);
	intList.push_back(2);

	intList.print();
	CopyConstructorTest1(intList);
	intList.print();

	return EXIT_SUCCESS;
}