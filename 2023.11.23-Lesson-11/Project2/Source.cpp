#include<iostream>

/*
1
2
3 . .

	1
3 . 2

	1
. 3 2

1
2 3 .

1
2 . 3

	1
	2
. . 3

*/

void hanoy(int count, int from = 1, int to = 3)
{
	if (count == 0)
	{
		return;
	}
	int res = 6 - from - to;

	hanoy(count - 1, from, to);
	if (from + res != 4)
	{
		std::cout << count << " " << from << " " << res << std::endl;
	}
	else
	{
		std::cout << count << " " << from << " " << to << std::endl;
		std::cout << count << " " << to << " " << res << std::endl;
	}
	hanoy(count - 1, to, from);

	if (to + res != 4)
	{
		std::cout << count << " " << res << " " << to << std::endl;
	}
	else
	{
		std::cout << count << " " << res << " " << from << std::endl;
		std::cout << count << " " << from << " " << to << std::endl;
	}

	hanoy(count - 1, from, to);
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoy(n);
	return 0;
}