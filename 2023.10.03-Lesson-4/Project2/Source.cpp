#include<iostream>

int main(int argc, char* argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		std::cout << argv[i] << std::endl;
	}
	return EXIT_SUCCESS;
}

//Project2.exe arg1 arg2 >output.txt <input.txt