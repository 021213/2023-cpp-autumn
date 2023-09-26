#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;

	std::cin >> a;
	std::cin >> b;

	if (!(a > b) || a <= 0 && b >= 0 || a != b && 5)
	{
		std::cout << a;
	}
	else if (a < b)
	{
		std::cout << b;
	}
	else
	{
		std::cout << a + b;
	}

	if (a == 1)
	{
		std::cout << "MONDAY" << std::endl;
	}
	else if (a == 2)
	{
		std::cout << "TUESDAY" << std::endl;
	}

kazakov:

	switch (a)
	{
	case 1:
		std::cout << '1' << std::endl;
		break;
	case 2: case 3: case 4:
		std::cout << '2' << std::endl;
		break;
	case 5:
		std::cout << '3' << std::endl;
	case 6:
		std::cout << '4' << std::endl;
		break;
	default:
		std::cout << '5' << std::endl;
	}

chernitsky:

	char c = 0;
	std::cin >> c;
	switch (c)
	{
	case '(': case '{': case '[':
		std::cout << "OPEN" << std::endl;
		break;
	case ')': case '}': case ']':
		std::cout << "CLOSE" << std::endl;
		break;
	default:
		std::cout << "NAN" << std::endl;
		break;
	}


	std::cout << (a < b ? a : b) << std::endl;

	if (a < 0)
	{
		std::cout << "NEGATIVE" << std::endl;
	}
	else if (a > 0)
	{
		std::cout << "POSITIVE" << std::endl;
	}
	else
	{
		std::cout << "NULL" << std::endl;
	}
	std::cout <<
		(a < 0 ? "NEG" : a > 0 ? "POS" : "NULL") << std::endl;

	//if (a > 0) goto chernitsky; else goto kazakov;

	return EXIT_SUCCESS;
}