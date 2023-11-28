#include<iostream>

int main(int argc, char* argv[])
{
	int coef[4];
	for (int i = 0; i < 4; ++i)
	{
		std::cin >> coef[i];
	}
	for (int x = 0; x <= 1000; ++x)
	{
		int res = 0;
		/*
		coef[0]*x^3 + coef[1]*x^2 + coef[2]*x + coef[3]
		((coef[0] * x + coef[1]) * x + coef[2]) * x + coef[3]
		*/
		for (int i = 0; i < 4; ++i)
		{
			res = res * x + coef[i];
		}
		res = coef[0] * x * x * x + coef[1] * x * x + coef[2] * x + coef[3];
		/* #include<cmath> pow(x, 3)*/
		if (res == 0)
		{
			std::cout << x << " ";
		}
	}
	return EXIT_SUCCESS;
}