#include<iostream>

void printArray(int* a, int len);
void expandArray(int*& a, int& len);
void addElement(int*& a, int& len, int element);
void contractArray(int*& a, int& len);
bool indexValid(int index, int len);
int extractElement(int*& a, int& len, int index);
void printReverseArray(int* a, int len);
void printMenu();

int main(int argc, char* argv[])
{

	return EXIT_SUCCESS;
}

void printArray(int* a, int len) // 2 + 1 + 5 * len = 3 + 5 * len = O(len)
{
	if (a == nullptr)// 1
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i) // 1 + len * (1 + 2 + (1 + 1))
		{
			std::cout << a[i] << " "; //1 + 1
		}
	}
	std::cout << std::endl; // 1
}

void expandArray(int*& a, int& len) //O(len)
{
	int* newA = new int[len + 1] { 0 };
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
	}
	a = newA;
	++len;
}

void addElement(int*& a, int& len, int element)
{
	expandArray(a, len);
	a[len - 1] = element;
}

void contractArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		int* newA = new int[len - 1];
		for (int i = 0; i < len - 1; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
		a = newA;
		--len;
	}
}

bool indexValid(int index, int len) // O(1)
{
	return (index >= 0 && index < len);
	/*
	switch (index >= 0 && index < len)
	{
	case true:
		return true;
	case false:
		return false;
	}
	*/
	/*
	if (index >= 0 && index < len)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
}

int extractElement(int*& a, int& len, int index)
{
	int res = -1;
	if (indexValid(index, len))
	{
		res = a[index];
		for (int i = index; i < len - 1; ++i)
		{
			a[i] = a[i + 1];
		}
		contractArray(a, len);
	}
	return res;
}

void printReverseArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << a[len - i - 1] << " ";
		}
	}
	std::cout << std::endl;
}

void printMenu()
{
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - Print array" << std::endl;
	std::cout << "2 - Append element to array" << std::endl;
	std::cout << "3 - Extract element from array" << std::endl;
}

void printSquare(int n) //O(n * n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << i + j << " ";
		}
		std::cout << std::endl;
	}
}

//0 .. 1000
//0 .. 500
//250 .. 500
//log_2(1000) ~= 10 -> O(ln(1000))