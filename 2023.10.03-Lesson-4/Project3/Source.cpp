#include<iostream>

int main(int argc, char* argv[])
{
	int a[10]{ 0 };
	int b[5]{ 1, 2, 3, 4, 5 };
	int c[5]{ 1, 2, 0 };
	//int d[2]{ 1, 2, 0 };
	std::cout << sizeof(a) / sizeof(int) << std::endl;
	std::cout << a << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		a[i] = i;
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}