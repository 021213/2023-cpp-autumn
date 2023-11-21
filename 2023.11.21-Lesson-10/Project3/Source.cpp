#include<iostream>
/*
https://informatics.msk.ru/mod/statements/view.php?id=2550&chapterid=3050#1
*/
void hanoi(int n, int from, int to)
{
	if (n <= 0)
	{
		return;
	}

	int res = 6 - from - to;
	hanoi(n - 1, from, res);
	printf("%d %d %d\n", n, from, to);
	hanoi(n - 1, res, to);
}

int main(int argc, char* argv[])
{
	hanoi(2, 1, 3);
	std::cout << std::endl;
	hanoi(3, 1, 3);
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
