#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

bool isLetter(char c)
{
	return (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я') ||
		(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isSyntax(char c)
{
	return (c == '.' || c == ',' || 
		c == ';' || c == ':' || 
		c == '!' || c == '?');
}

int main(int argc, char** argv)
{
	printf("%d \t %ld \t %f \t %lf \t %c \n", 15, 15ll, 1.5f, 1.5, '0');
	
	double d = 3.1415926535;

	printf("%09.4lf %9.4lf", d, d);

	scanf("%lf", &d);

	char str[255];
	gets_s(str);
	printf("%s", str);
	
	scanf("%s", str);
	printf("%s", str);

	return 0;
}

/*
pureC
Посчитать количество слов в тексте, вывести самое длинное предложение.

Реализовать функции

strcat() - сложение строк
strcat("mama ", "banana") -> "mama banana"

strstr() - поиск подстроки
strstr("mama banana", "banana") -> 5

substr() - выделение подстроки "mama banana"
substr("mama banana", 5, 6) -> "banana"

strcmp() - сравнение строк

strmult() - умножение строки на число: "ba" * 3 == "bababa"

C++
Найти самое часто встречающееся слово.
Реализовать функцию, проверяющую, является ли строка палиндромом.

*/