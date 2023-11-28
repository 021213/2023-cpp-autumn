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

	1
	2
. . 3

  1
. 2 3

  1
3 2 .

	1
3 . 2

*/

void hanoy(int count, int from = 1, int to = 3)
{
	if (count == 0)
	{
		return;
	}
	int res = 6 - from - to;

	if ((3 + to - from) % 3 == 1)
	{
		hanoy(count - 1, from, res);
		std::cout << count << " " << from << " " << to << std::endl;
		hanoy(count - 1, res, to);
	}
	else
	{
		hanoy(count - 1, from, to);
		std::cout << count << " " << from << " " << res << std::endl;
		hanoy(count - 1, to, from);
		std::cout << count << " " << res << " " << to << std::endl;
		hanoy(count - 1, from, to);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoy(n);
	return 0;
}