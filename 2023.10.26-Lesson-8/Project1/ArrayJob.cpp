#include "ArrayJob.h"
#include<ctime>
#include<cstdlib>
#include<iostream>

int** initMatrix(int n, int m)
{
	int** res = nullptr;
	res = new int* [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		res[i] = new int[m] { 0 };
	}
	return res;
}

void randomizeMatrix(
	int** matr,
	int n, int m,
	int mn, int mx)
{
	srand(time(0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			matr[i][j] = rand() % (mx - mn + 1) + mn;
		}
	}
}

void printMatrix(int** matr, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << matr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void deleteMatrix(int** matr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] matr[i];
	}
	delete[] matr;
}
