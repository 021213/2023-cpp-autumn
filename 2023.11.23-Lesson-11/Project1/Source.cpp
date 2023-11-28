#include<iostream>

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

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoy(n);
	return 0;
}