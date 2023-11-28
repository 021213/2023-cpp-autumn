#include<iostream>

void hanoy(int count, int from = 1, int to = 3)
{
	if (count <= 0)
	{
		return;
	}

	int res = 6 - from - to;

	if (count == 1)
	{
		printf("1 %d %d\n", from, to);
	}
	else
	{
		hanoy(count - 1, from, to);
		hanoy(count - 2, to, res);
		printf("0 %d %d\n", from, to);
		hanoy(count - 2, res, from);
		hanoy(count - 1, from, to);
	}
}

/*
1											1
2			1					1			2
3			2     1		  1		2			3
4		    3     2		  2		3			4
5 . .	5 . 4	5 3 4	4 3 5	4 . 5	. . 5

1							1
2 . .   2 . 1   1 . 2   . . 2
*/


int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoy(n);
	return 0;
}