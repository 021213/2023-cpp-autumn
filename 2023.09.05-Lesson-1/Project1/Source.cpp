#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;
	int c = a + b;
	std::cout << a << " + " << b << " = " << c << std::endl;
	return EXIT_SUCCESS;
}