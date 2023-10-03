#include<iostream>

union Number {
	float f;
	int i;
	double d;
};

int main()
{
	Number n;
	n.i = 34;
	std::cout << n.i << std::endl;
	n.f = 53.0f;
	std::cout << n.f << std::endl;
	std::cout << n.i << std::endl;
	std::cout << sizeof(Number) << std::endl;
	return 0;
}
