#include<iostream>
#include<vector>
#include<cstring>
#include<string>

template<typename T>
T sum(T a, T b)
{
	return a + b;
}

int main(int argc, char* argv[])
{
	bool b = true;
	char c = 0;
	short s = -5;
	int i = 0;
	long l = 0;
	long long ll = 0;
	unsigned short us = -5;
	unsigned int ui = 0;
	unsigned long ul = 0;
	unsigned long long ull = 0;

	std::cout << s << " " << us << "\n";
	// _ _______ ________
	//       5 = 0000 0000 0000 0101
	//      ~5 = 1111 1111 1111 1010
	//~5+1= -5 = 1111 1111 1111 1011
	//5 + (-5) = 0000 0000 0000 0000

	std::cout << sizeof(long long) << "\n";
	
	//std::vector<int> vint;
	//std::vector<bool> vbool;

	int len = 0;
	int cap = 10;
	int* a = new int[cap];
	
	float f = 0; // _ _________________ ___________  1234.5678 = 0.12345678 * 10^4
	double d = 0;//                                                12345678      4
	
	int astat[10];
	int* adyn = new int[10];
	delete[] adyn;
	adyn = (int*)malloc(sizeof(int) * cap);
	free(adyn);
	adyn = (int*)calloc(cap, sizeof(int));
	std::cout << adyn << std::endl;
	adyn = (int*)realloc(adyn, 1);
	std::cout << adyn << std::endl;
	free(adyn);
	/*
	_______________________________________
	_______________________________________
	_______________________________________
	_______________________________________
	_______________________________________
	_______________________________________
	_______________________________________
	_______________________________________
	*/
	char* cc;
	//cstring
	//strcat();
	//strchr();
	//strcmp();
	//strlen();

	std::string str;

	//enum
	//union
	//struct
	return EXIT_SUCCESS;
}