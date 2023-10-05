#include<iostream>
#define N 10

int main()
{
	int a[N] { 0 };
	a[0] = 32;
	a[1] = 23;
	a[2] = a[0] + a[1];
	std::cout << a << std::endl; //0x????????
	std::cout << *a << std::endl; // 32
	std::cout << *(a + 1) << " " << a[1] << std::endl; // 23 23
	for(int i = 0; i < N; ++i)
	{
		a[i] = i;
	}
	int sum = 0;
	for(int i = 0; i < N; ++i)
	{
		sum += a[i];
	}
	
	return 0;
}
