#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //string.h

int strLen(char* str)
{
	int len = 0;
	while (str[len++] != '\0');
	return len - 1;
}

int main(int argc, char* argv[])
{
	//char* str = (char*)malloc(sizeof(char) * 255);
	char str[255];
	strcpy(str, "Banana");
	printf("%s\n", str);
	strcpy(str, "Barabana");
	printf("%s\n", str);
	//scanf("%s", str);
	//printf("[%d] %s\n", strLen(str), str);
	gets_s(str, 255);
	printf("[%d, %d] %s\n", strLen(str), strlen(str), str);
	//ÓÌÍÎÆÅÍÈÅ ÑÒĞÎÊÈ ÍÀ ×ÈÑËÎ strmult()
	//ÑËÎÆÅÍÈÅ ÑÒĞÎÊ  strcat()
	//ÏÎÈÑÊ ÏÎÄÑÒĞÎÊÈ  strstr()
	//ÑĞÀÂÍÅÍÈÅ ÑÒĞÎÊ  strcmp()
	bool counts[256]{ 0 };
	for (int i = 0; i < strlen(str); ++i)
	{
		counts[str[i]] = true;
	}
	for (int i = 0; i < 256; ++i)
	{
		if (counts[i])
		{
			std::cout << (char)i;
		}
	}
	//free(str);
	return EXIT_SUCCESS;
}