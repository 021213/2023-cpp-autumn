#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	std::cout << a / 100 + a / 10 % 10 + a % 10 << std::endl;
	return EXIT_SUCCESS;
}