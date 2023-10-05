#include<iostream>
#include<cstdlib>

int main()
{
	int n = 10;
	int* a = (int*) malloc(sizeof(int) * n);
	*(a + 3) = 4;
	std::cout << a[3];
	scanf("%d", a + 2);
	scanf("%d", &a[2]);
	free(a);
	
	a = new int[10];
	delete[] a;

	return 0;
}
