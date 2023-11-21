#include<iostream>

typedef unsigned long long uint;

uint fact(uint n)
{
	if (n == 0)
	{
		return 1;
	}
	return n * fact(n - 1);
}


int main(int argc, char* argv[])
{
	uint n = 50;
	uint f = 1;
	for (int i = 2; i <= n; ++i)
	{
		f *= i;
	}
	std::cout << f << std::endl;
	std::cout << fact(n) << std::endl;
	return EXIT_SUCCESS;
}