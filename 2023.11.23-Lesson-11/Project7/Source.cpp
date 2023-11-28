#include<iostream>

int n[4] { 0 };
int** d = new int* [4] {nullptr, new int[10], new int[10], new int[10]};

void shift(int from = 1, int to = 3)
{
	std::cout << d[from][n[from] - 1] << " " << from << " " << to << std::endl;
	d[to][n[to]++] = d[from][--n[from]];
	/*
	* --n[from];
	* d[to][n[to]] = d[from][n[from]];
	* n[to]++;
	*/
	/*
   [4,0,0]
	1
	2
	3
	4 . .

   [3,0,1]
	2
	3
	4 . 1
	*/
}

void hanoy(int count, int from = 1, int to = 3)
{
	if (count == 0)
	{
		return;
	}

	int res = 6 - from - to;

	hanoy(count - 1, from, res);
	shift(from, to); //std::cout << count << " " << from << " " << to << std::endl;
	hanoy(count - 1, res, to);
}

void sort()
{

}

int main(int argc, char* argv[])
{
	std::cin >> n[1];
	for (int i = n[1] - 1; i >= 0; --i)
	{
		std::cin >> d[1][i];
	}
	sort();
	return EXIT_SUCCESS;
}

/*
5
2
4		4
8		8		8		
3		3		3		3   2
1		1		1	2	1   4
6		6	2	6   4	6   5
7 . .	7 . 5	7 . 5	7 . 8
h(0,3,2)h(1,3,2)h(3,3,2)h(1,3,2)
sh(1,3) sh(1,3)	sh(1,3) sh(1,3)
h(0,2,3)h(1,2,3)h(3,2,3)h(1,2,3)
h(0,3,2)
sh(1,3)
h(0,2,3)
*/