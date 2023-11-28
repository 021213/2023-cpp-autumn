#include<iostream>

int n[3] { 0 };
int** d = new int* [3] {new int[10], new int[10], new int[10]};

void shift(int from = 1, int to = 3)
{
	std::cout << d[from][n[from] - 1] << " " << from << " " << to << std::endl;
	d[to][n[to]++] = d[from][--n[from]];
}

void hanoy(int from = 1, int to = 3)
{
	if (n[from] == 0)
	{
		return;
	}

	int res = 6 - from - to;

	hanoy(from, res);
	shift(from, to);
	hanoy(res, to);
}

void sort()
{
	hanoy(1, 3);
}

int main(int argc, char* argv[])
{
	std::cin >> n[0];
	for (int i = 0; i < n[0]; ++i)
	{
		std::cin >> d[0][i];
	}
	sort();
	return EXIT_SUCCESS;
}