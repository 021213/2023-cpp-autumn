#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
// pure C
// C++
int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");
	// r - read; w - write; a - append
	int a = 0;
	fscanf(f, "%d", &a);
	int b = 0;
	fscanf(f, "%d", &b);
	fclose(f);

	f = fopen("out.txt", "w");
	fprintf(f, "%d + %d = %d\n", a, b, a + b);
	fclose(f);

	f = fopen("in.txt", "r");
	int sum = 0;
	while (!feof(f))
	{
		int x = 0;
		fscanf(f, "%d", &x);
		sum += x;
	}
	fclose(f);
	printf("sum = %d\n", sum);

	return EXIT_SUCCESS;
}