#include<iostream>

void printArray(int* a, int len);
void expandArray(int*& a, int& len);
void addElement(int*& a, int& len, int element);
void contractArray(int*& a, int& len);
bool indexValid(int index, int len);
int extractElement(int*& a, int& len, int index);
void printReverseArray(int* a, int len);

int main(int argc, char* argv[])
{
	int len = 0;
	int* a = nullptr;
	printArray(a, len);
	addElement(a, len, 1);
	addElement(a, len, 2);
	addElement(a, len, 3);
	addElement(a, len, 4);
	addElement(a, len, 5);
	addElement(a, len, 6);
	addElement(a, len, 7);
	printArray(a, len);

	std::cout << extractElement(a, len, 3) << std::endl;
	printArray(a, len);
	std::cout << "Reverse print : ";
	printReverseArray(a, len);

	return EXIT_SUCCESS;
}

void printArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << a[i] << " ";
		}
	}
	std::cout << std::endl;
}

void expandArray(int*& a, int& len)
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

bool indexValid(int index, int len)
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