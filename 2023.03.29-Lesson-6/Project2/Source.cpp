#include<iostream>
#include<fstream>

int main(int argc, char* argv[])
{
	// >out.txt <in.txt
	std::ifstream fin;
	fin.open("in.txt");
	int n = 0;
	fin >> n;
	fin.close();
	std::ofstream fout;
	fout.open("out.txt"/*, std::ios_base::ate || std::ios_base::binary */ );
	fout << n * n << std::endl;
	std::cout << n * n;
	fout.close();

	return EXIT_SUCCESS;
}