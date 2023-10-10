#include<iostream>

int maxIndex(int, int*);
void printArray(int, int*);
void readArray(int, int*);

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	int* a = new int[n] { 0 };

	readArray(n, a);
	std::cout << maxIndex(n, a);
	printArray(n, a);

	delete[] a;

	return EXIT_SUCCESS;
}

int maxIndex(int n, int* a)
{
	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		mx = (a[i] > a[mx] ? i : mx);
	}
	return mx;
}

void printArray(int n, int* a)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << a[i];
	}
	std::cout << std::endl;
}

void readArray(int n, int* a)
{
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
	}
}