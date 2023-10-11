#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << j + 1 << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << n - j << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << std::min(n - j, j + 1) << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << std::min(n - i, i + 1) << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << i + 1 << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << (i + j) % n + 1 << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << 2 * n - i - j - 1 << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << std::max(std::min(i + 1, n - i), std::min(j + 1, n - j)) << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << std::min(std::min(i + 1, n - i), std::min(j + 1, n - j)) << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << (i + 1) % 2 * (j + 1) + i % 2 * (n - j) << " ";
				//std::cout << (i % 2 == 0 ? j + 1 : n - j) << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << n - std::max(abs(n - 1 - i - j), abs(i - j)) << " ";
			}
			std::cout << std::endl;
		}
	}

	return EXIT_SUCCESS;
}