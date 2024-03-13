#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

bool isLetter(char c)
{
	return (c >= '�' && c <= '�') || (c >= '�' && c <= '�') ||
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
��������� ���������� ���� � ������, ������� ����� ������� �����������.

����������� �������

strcat() - �������� �����
strcat("mama ", "banana") -> "mama banana"

strstr() - ����� ���������
strstr("mama banana", "banana") -> 5

substr() - ��������� ��������� "mama banana"
substr("mama banana", 5, 6) -> "banana"

strcmp() - ��������� �����

strmult() - ��������� ������ �� �����: "ba" * 3 == "bababa"

C++
����� ����� ����� ������������� �����.
����������� �������, �����������, �������� �� ������ �����������.

*/