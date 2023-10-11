#include<iostream>

int main(int argc, char* argv[])
{
	{
		std::cout << "Dividor" << std::endl;
		int a = 179;
		int b = 20;
		while (a != b)
		{
			if (a % 2 == 1 || 2 * b > a)
			{
				std::cout << "-1" << std::endl;
				a -= 1;
			}
			else
			{
				std::cout << ":2" << std::endl;
				a /= 2;
			}
		}
		std::cout << std::endl;
	}
	{
		std::cout << "Aquarius" << std::endl;
		const int maxA = 3;
		const int maxB = 5;
		const int res = 1;
		int a = 0;
		int b = 0;
		do
		{
			if (a == 0)
			{
				std::cout << ">A" << std::endl;
				a = maxA;
			}
			else if (b == maxB)
			{
				std::cout << "B>" << std::endl;
				b = 0;
			}
			else
			{
				std::cout << "A>B" << std::endl;
				if (b + a <= maxB)
				{
					b += a;
					a = 0;
				}
				else
				{
					a -= maxB - b;
					b = maxB;
				}
			}
		} while (!(a == 0 && b == 0) && !((b == res) || (a == res)));
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}