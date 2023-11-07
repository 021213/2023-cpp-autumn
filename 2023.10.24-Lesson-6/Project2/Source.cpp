#include<iostream>

int main(int argc, char* argv[])
{
	int a[10]{ 0 };
	for (int i = 0; i < 10; ++i)
	{
		a[i] = rand() % 10;
	}
	int b = 10;
	return EXIT_SUCCESS;
}