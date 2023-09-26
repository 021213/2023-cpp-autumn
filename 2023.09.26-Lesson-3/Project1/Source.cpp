#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>

int main(int argc, char* argv[])
{
	{
		//while (1) malloc(1);
		int i = 0;
		while (i < 10)
		{
			std::cout << i << " ";
			++i;
		}
		std::cout << std::endl;
	}
	{
		for (int i = 0; i < 10; ++i)//;
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	{
		int i = 0;
		do
		{
			std::cout << i << " ";
			++i;
		} while (i < 10);
		std::cout << std::endl;
	}
	{
		int i = 0;
	banana:
		std::cout << i << " ";
		++i;
		if (i < 10) goto banana;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				printf("%2d ", i + j);
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

	}
	{
		int a = 1230;
		int b = 112120;
		//scanf_s("%d", &a);
		//scanf("%d", &b);
		printf("%d + %d = %d\n", a, b, a + b);
		//%d, %ld, %f, %lf, %c, %s
		//printf("banana\n");
		//printf("\n \t \r \" \\ \0");
		printf("%04d + %4d = %03d\n", a, b, a + b);
		double f = 3.1415926535;
		printf("%8.5lf\n%9.4lf\n%7.3lf\n", f, f, f);
		std::cout << std::fixed << std::scientific << std::setprecision(20) << f << std::endl;
		double d = 0.01;
		double dd = 0;
		for (int i = 0; i < 100; ++i, dd += d);
		std::cout << std::fixed << std::scientific << std::setprecision(20) << dd << std::endl;
		float epsilon = 0.01;
		std::cout << (fabs(dd - 1) <= epsilon) << std::endl;
	}
	return EXIT_SUCCESS;
}