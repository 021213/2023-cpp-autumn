#include<iostream>
#include<fstream>
//iostream
//istream ostream
//ifstream ofstream
void readTwoNumbers(std::istream& stream, int& a, int& b)
{
	stream >> a;
	stream >> b;
}


int main(int argc, char* argv[])
{
	std::ifstream fin("in.txt");
	int a = 0;
	int b = 0;
	fin >> a >> b;
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	fin.close();

	fin.open("in.txt");
	a = 0;
	b = 0;
	readTwoNumbers(fin, a, b);
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	fin.close();

	std::cout << "Input two numbers" << std::endl;
	readTwoNumbers(std::cin, a, b);
	std::cout << a << " + " << b << " = " << a + b << std::endl;

	std::ofstream fout("out.txt");
	fout << a << " + " << b << " = " << a + b << std::endl;
	fout.close();

	int sum = 0;
	fin.open("in.txt");
	while(!fin.eof())
	{
		int x = 0;
		fin >> x;
		sum += x;
	}
	std::cout << sum << std::endl;

	return EXIT_SUCCESS;
}