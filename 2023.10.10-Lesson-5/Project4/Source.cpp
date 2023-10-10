#include<iostream>
#include<ctime>
#include<cstdlib>

int* initArray(int);
void printArray(int, int*);
int sum(int, int*);
int mx(int, int*);
int maxIndex(int, int*);
int minIndex(int, int*);

void reverse(int, int*);
void swapPairs(int, int*);
void shiftL(int, int*);
void shiftR(int, int*);
void swapParts(int, int*, int);

int main(int argc, char* argv[])
//void main()
{
	int n = 10;
	int* a = initArray(n);
	printArray(n, a);
	std::cout << "Index of minimum" << minIndex(n, a) << std::endl;

	std::cout << "Reverse : ";
	reverse(n, a);
	printArray(n, a);

	delete[] a;
	return EXIT_SUCCESS;
}

int* initArray(int len)
{
	srand(time(0));
	int* res = new int[len] { 0 };
	int min = -99;
	int max = 99;
	for (int i = 0; i < len; ++i)
	{
		res[i] = rand() % (max - min + 1) + min;
	}
	return res;
}

void printArray(int len, int* a)
{
	for (int i = 0; i < len; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

int sum(int len, int* a)
{
	int res = 0;
	for (int i = 0; i < len; ++i)
	{
		res += a[i];
	}
	return res;
}

int mx(int len, int* a)
{
	return a[maxIndex(len, a)];
}

int maxIndex(int len, int* a)
{
	int res = 0;
	for (int i = 0; i < len; ++i)
	{
		res = (a[i] > a[res] ? i : res);
	}
	return res;
}

int minIndex(int len, int* a)
{
	int res = 0;
	for (int i = 0; i < len; ++i)
	{
		res = (a[i] < a[res] ? i : res);
	}
	return res;
}