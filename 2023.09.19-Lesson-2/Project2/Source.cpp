#include<iostream>
#include<clocale>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Привет!" << std::endl;
	return 0;
}