#include<iostream>

int createArray(int len, int*& outA)
{
	outA = new int[len] { 0 };
	if (outA == nullptr)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(int argc, char* argv[])
{
	int n = 1000000;
	int* a = nullptr;
	if (createArray(n, a) != 0)
	{
		std::cout << "OOPS" << std::endl;
	}
	return EXIT_SUCCESS;
}

