#include<iostream>

void apply(int n);
void cancel(int n);

void cancel(int n)
{
	if (n > 0)
	{
		cancel(n - 2);
		std::cout << -n << " ";
		apply(n - 2);
		cancel(n - 1);
	}
}

void apply(int n)
{
	if (n > 0)
	{
		apply(n - 1);
		cancel(n - 2);
		std::cout << n << " ";
		apply(n - 1);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	apply(n);
	return EXIT_SUCCESS;
}