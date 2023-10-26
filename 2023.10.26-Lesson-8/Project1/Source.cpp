#include<iostream>
#include"ArrayJob.h"

int main(int argc, char* argv[])
{
	int n = 5;
	int m = 5;

	int** matr = nullptr;

	matr = initMatrix(n, m);
	randomizeMatrix(matr, n, m);
	printMatrix(matr, n, m);
	deleteMatrix(matr, n);

	return EXIT_SUCCESS;
}
