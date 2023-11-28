#include<iostream>

int n[3] { 0 };
int** d = new int* [3] {new int[10], new int[10], new int[10]};

void hanoy(int count, int from = 1, int to = 3)
{
	if (count == 0)
	{
		return;
	}

	int res = 6 - from - to;

	hanoy(count - 1, from, res);
	std::cout << count << " " << from << " " << to << std::endl;
	hanoy(count - 1, res, to);
}

void shift(int from, int to)
{
	d[to][n[to]++] = d[from][--n[from]];
}

void sort()
{

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