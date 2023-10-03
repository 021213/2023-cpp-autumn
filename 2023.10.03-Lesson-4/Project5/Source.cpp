#include<iostream>
#include<cstdlib>

int main(int, char**)
{
	int n = 5;
	int m = 4;
	int** a = (int**)malloc(sizeof(int*) * n);
	for(int i = 0; i < n; ++i)
	{
		*(a + i) = (int*)malloc(sizeof(int) * m);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			*(*(a + i) + j) = i + j;//a[i][j] = i + j;
			//a - адрес начала массива
			//a + i - адрес ячейки в которой хранится начало i-ой строки
			//*(a + i) - адрес начала i-ой строки
			//*(a + i) + j - адрес j-го элемента в i-й строке
			//*(*(a + i) + j) - j-й элемент в i-й строке			
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << *(*(a + i) + j) << " ";
		}
		std::cout << std::endl;
	}
	
	for (int i = 0; i < n; ++i)
	{
		free(*(a + i)); //удалили все строчки
	}
	free(a); //удалили указатели на строчки
	
	return EXIT_SUCCESS;
}
//SOLID
