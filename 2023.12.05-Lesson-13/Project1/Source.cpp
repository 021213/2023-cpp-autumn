#include<iostream>
#include<cstring>

int main(int argc, char* argv[])
{
	char c = '\0';
	char s[255] = "Hello \0 world!";
	std::cout << "\n \t \" \\ " << std::endl;
	std::cout << s << std::endl;
	printf("%s\n", s);
	s[6] = '!';
	printf("%s\n", s);
	char s1[255] = "H\ne\nl\nl\no\n, Kuklin!";
	printf("%s\n", s1);
	char a[255] = "Hello";
	char b[255] = "world";
	//strcat(s1, s2); - сложение
	//strcmp(s1, s2); - сравнение "ABC" > "ABB", ASCII
	//strstr(str1 + 10, str2) - поиск
	//strlen(str1) - длина строки
	for (int i = 0; i < 256; ++i)
	{
		std::cout << i << "->" << (char)i << "\t";
	}
	return EXIT_SUCCESS;
}