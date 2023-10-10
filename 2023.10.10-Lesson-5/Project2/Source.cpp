#include<iostream>

int sum(int = 1, int = 1);
float sum(float = 1, float = 1);

void printSum(int, int);

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a >> b;
	std::cout << sum(a, b);
	std::cout << sum(5, 9);
	std::cout << sum(5);
	//std::cout << sum(,5);
	//std::cout << sum();

	return EXIT_SUCCESS;
}

int sum(int a, int b)
{
	return a + b;
}

float sum(float a, float b)
{
	return a + b;
}

void printSum(int a, int b)
{
	if (a != b)
	{
		return;
	}
	std::cout << sum(a, b) << std::endl;
	return;
}