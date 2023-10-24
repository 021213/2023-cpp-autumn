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
	int* a = nullptr;
	int len = 0;
	bool exit = false;
	while (!exit)
	{
		{
			system("cls");
			printMenu();
			printArray(a, len);
		}
		int choice = 0;
		{
			std::cin >> choice;
		}
		{
			switch (choice)
			{
			case 0:
				exit = true;
				break;
			case 1:
				printArray(a, len);
				system("pause");
				break;
			case 2:
			{
				int element = 0;
				std::cout << "Input element to add : ";
				std::cin >> element;
				addElement(a, len, element);
				break;
			}
			case 3:
			{
				int index = 0;
				std::cout << "Input index to extract : ";
				std::cin >> index;
				std::cout << "Extracted  " << extractElement(a, len, index) << std::endl;
				break;
			}
			default:
				std::cout << "Unknown command" << std::endl;
				break;
			}
		}
	}
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

void printMenu()
{
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - Print array" << std::endl;
	std::cout << "2 - Append element to array" << std::endl;
	std::cout << "3 - Extract element from array" << std::endl;
}
