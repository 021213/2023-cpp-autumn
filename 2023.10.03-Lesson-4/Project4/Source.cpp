#include<iostream>
#include<cstdlib>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;
	int a[100]{ 0 };

	int* b = new int[n] { 0 };
	delete[] b;

	int* c = (int*)malloc(sizeof(int) * n);
	free(c);

	return EXIT_SUCCESS;
}