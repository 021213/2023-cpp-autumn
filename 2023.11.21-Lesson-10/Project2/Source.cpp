#include<iostream>

typedef unsigned long long uint;

const int N = 50;
uint cc[N][N];

uint C(uint n, uint k)
{
	if (cc[n][k] == -1)
	{
		if (k < 0 || k > n)
		{
			cc[n][k] = 0;
		}
		else if (k == 0 || k == n)
		{
			cc[n][k] = 1;
		}
		else
		{
			cc[n][k] =
				C(n - 1, k - 1) + C(n - 1, k);
		}
	}
	return cc[n][k];
}

int main(int argc, char* argv[])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cc[i][j] = -1;
		}
	}

	for (int i = 0; i < 30; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			std::cout << C(i, j) << " ";
		}
		std::cout << std::endl;
	}

	std::cout << C(30, 15) << " ";

	return EXIT_SUCCESS;
}
