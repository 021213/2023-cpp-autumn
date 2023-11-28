#include<iostream>

union value {
	int i;
	float f;
};

int main(int argc, char* argv[])
{
	value v;
	v.i = 10;
	std::cout << v.i << " " << v.f << std::endl;
	v.f = 10;
	std::cout << v.i << " " << v.f << std::endl;

	int i = 10;
	int* pi = &i;
	void* vi = pi;
	float* pf = (float*)vi;
	float f = *pf;
	f = *((float*)((void*)&i));
	std::cout << f;
	return EXIT_SUCCESS;
}