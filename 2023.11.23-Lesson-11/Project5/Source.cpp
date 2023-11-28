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
	int from = 1;
	int to = 0;
	for (int i = n; i > 0; --i)
	{
		to = (i % 2 == 0 ? 3 : 2);
		hanoy(i, from, to);
		from = to;
	}
	return 0;
}

/*
1		  1		
2		  2		    1	  1		
3		  3		    2	  2		  2 1
4 . .	. 4 .	. 4 3	. 4 3	. 4 3


*/