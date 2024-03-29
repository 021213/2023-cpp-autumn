#include<iostream>

class CArrayList
{
public:
	CArrayList(int capacity = 5) :
		_data(new int[capacity]), _capacity(capacity), _size(0)
	{
		for (int i = 0; i < _capacity; ++i)
		{
			_data[i] = 0;
		}
	}
	CArrayList(const CArrayList& src) :
		_data(new int[src._size]), _capacity(src._size), _size(src._size)
	{
		for (int i = 0; i < _size; _data[i] = src._data[i++]);
	}
	~CArrayList()
	{
		delete[] _data;
	}

private:
	void _expand(int add = 0)
	{
		add = (add == 0 ? _capacity : add);
		int* newdata = new int[_capacity + add];
		for (int i = 0; i < _size; newdata[i] = _data[i++]);
		delete[] _data;
		_capacity += add;
		_data = newdata;
	}

	bool _indexValid(int index)
	{
		return (index >= 0 && index < _size);
	}

public:
	void push_back(int val)
	{
		if (_size == _capacity)
		{
			_expand();
		}
		_data[_size++] = val;
	}

	void print()
	{
		std::cout << "[" << _size << "]: ";
		for (int i = 0; i < _size; ++i)
		{
			std::cout << _data[i] << " ";
		}
		std::cout << std::endl;
	}

	int getEl(int index)
	{
		if (!_indexValid(index))
		{
			return -1;
		}
		return _data[index];
	}

	void setEl(int index, int val)
	{
		if (_indexValid(index))
		{
			_data[index] = val;
		}
	}

	int size()
	{
		return _size;
	}

	int& cell(int index)
	{
		if (!_indexValid(index))
		{
			return _err;
		}
		return _data[index];
	}

	int& operator[](int index)
	{
		if (!_indexValid(index))
		{
			return _err;
		}
		return _data[index];
	}

private:
	int _err = 0;
	int* _data;
	int _capacity;
	int _size;
};

int main(int argc, char* argv[])
{
	CArrayList list;
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.print();

	list.setEl(0, 10);
	std::cout << list.getEl(3) << std::endl;

	std::cout << list.cell(4) << std::endl;
	list.cell(2) = 555;
	list.cell(100) = 100;

	list.print();

	list[4] = 40;
	list[5] = 50;
	list[100] = 100;
	list.print();
	
	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}

/*
1. Абстракция
2. Инкапсуляция
	default (struct -> public, class -> private)
	public
	private
	protected
	static
*/