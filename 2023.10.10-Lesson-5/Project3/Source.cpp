#include<iostream>

void inc(int&);
void inc(int*);

int main(int argc, char* argv[])
{
	int n = 10;
	inc(n);
	std::cout << n; // 11
	inc(&n);
	std::cout << n; // 12

	int* a = &n;
	(*a)++;
	std::cout << n; // 13

	int& b = n;
	b++;
	std::cout << n; // 14

	return EXIT_SUCCESS;
}

void inc(int& a)
{
	++a;
	std::cout << a; // 11
}

void inc(int* ptr)
{
	*ptr = *ptr + 1;
	ptr[0]++;
}