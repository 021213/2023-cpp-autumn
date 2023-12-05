#include<iostream>
#include<string>

void countDots(std::string str)
{
	int count = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		count += (str[i] == '.');
	}
	std::cout << count << std::endl;
}

void countSubs(std::string str, std::string substr)
{
	int count = 0;
	int index = 0;
	do
	{
		index = str.find(substr, index + 1);
		++count;
	} while (index != -1);
	std::cout << count - 1 << std::endl;
}

void printSent(std::string str)
{
	int ind1 = 0;
	int ind2 = 0;
	do
	{
		ind2 = str.find(".", ind1);
		std::cout << str.substr(ind1, ind2 - ind1 + 1) << std::endl;
		ind1 = ind2 + 1;
	} while (ind2 != -1);
}

int main(int argc, char* argv[])
{
	countDots("Vasya. Kolya. Petya.");
	countSubs("Vasya. Kolya. Petya.", "ya");
	printSent("Vasya. Kolya. Petya.");
	std::string str = "";
	std::cin >> str;
	std::cout << "\"" << str << "\"" << std::endl;
	std::getline(std::cin, str);
	std::cout << "\"" << str << "\"" << std::endl;

	return EXIT_SUCCESS;
}