#include<iostream>

enum Gender { MALE = 1, FEMALE = 2, STUDENT = 4 };

int main()
{
	Gender g = MALE;
	std::cout << g;
	switch (g)
	{
	case MALE: break;
	case FEMALE: break;
	case STUDENT: break;
	}
	return 0;
}
