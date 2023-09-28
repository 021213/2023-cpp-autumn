#include<iostream>

union Number {
	float f;
	int i;
	double d;
}


int main()
{
	Number n;
	n.i = 34;
	std::cout << n.i;
	n.f = 53f;
	std::cout << n.f;
	std::cout << n.i;
	std::cout << sizeof(Number);
	return 0;
}