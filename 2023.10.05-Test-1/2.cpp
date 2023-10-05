#include<iostream>
#include<cmath>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << n - std::max(abs(n - 1 - i - j), abs(i - j));
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
