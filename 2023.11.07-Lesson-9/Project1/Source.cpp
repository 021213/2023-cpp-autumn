#include<iostream>
#include<ctime>

int* initRandomArray(int len, int mn = 0, int mx = 9);
void printArray(int* a, int len);
void reversePart(int* a, int n, int k, int l);
void swap(int& a, int& b);
void shiftRight(int* a, int len);
void shiftLeft(int* a, int len);

int main(int argc, char* argv[])
{
	srand(time(0));
	int n = 10;
	int* a = initRandomArray(n);
	printArray(a, n);
		
	{ //развернуть часть массива от k до l
		int k = rand() % n;
		int l = rand() % n;
		std::cout << k << " <-> " << l << std::endl;
		reversePart(a, n, k, l);
		printArray(a, n);
	}

	{
		//сдвинуть на 1 вправо
		shiftRight(a, n);
		printArray(a, n);
		//сдвинуть на 1 влево
		shiftLeft(a, n);
		printArray(a, n);
	}

	{
		//поменять две половинки массива местами
		//циклически сдвинуть массив на k вправо
		//0 1 2 3 4 5 6 7 8 9
		//k = 4
		//6 7 8 9 0 1 2 3 4 5
		int k = 4;
		//0 1 2 3 4 5 6 7 8 9
		reversePart(a, n, 0, n - k);
		//5 4 3 2 1 0 6 7 8 9
		reversePart(a, n, n - k + 1, n - 1);
		//5 4 3 2 1 0 9 8 7 6
		reversePart(a, n, 0, n - 1);
		//6 7 8 9 0 1 2 3 4 5
	}


	return EXIT_SUCCESS;
}

int* initRandomArray(int len, int mn, int mx)
{
	int* res = new int[len] { 0 };
	for (int i = 0; i < len; ++i)
	{
		res[i] = rand() % (mx - mn + 1) + mn;
	}
	return res;
}

void printArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void reversePart(int * a, int n, int k, int l)
{
	if (k > l)
	{
		return reversePart(a, n, l, k);
	}
	int len = l - k + 1;
	for (int i = 0; i < len / 2; ++i)
	{
		swap(a[k + i], a[l - i]);
	}
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void shiftRight(int * a, int len)
{
	int t = a[len - 1];
	for (int i = len - 1; i > 0; --i)
	{
		a[i] = a[i - 1];
	}
	a[0] = t;
}

void shiftLeft(int * a, int len)
{
	int t = a[0];
	for (int i = 0; i < len - 1; ++i)
	{
		a[i] = a[i + 1];
	}
	a[len - 1] = t;
}
