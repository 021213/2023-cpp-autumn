#include<iostream>
#include<cstdlib>
#include<cmath>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	int b = 0;
	std::cin >> b;
	int c = 0;
	std::cin >> c;

	int d = a + b + c;
	std::cout << d;

	if (a < b)
	{
		std::cout << a;
	}
	else
	{
		std::cout << b;
	}

	while (a < b)
	{
		++a;
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << " ";
	}

	return EXIT_SUCCESS;
}

/*
1. include
2. пустая строка
3. main
4. ...
5. return EXIT_SUCCESS;
6. пустая строка
*/