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
			//a - ����� ������ �������
			//a + i - ����� ������ � ������� �������� ������ i-�� ������
			//*(a + i) - ����� ������ i-�� ������
			//*(a + i) + j - ����� j-�� �������� � i-� ������
			//*(*(a + i) + j) - j-� ������� � i-� ������			
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
		free(*(a + i)); //������� ��� �������
	}
	free(a); //������� ��������� �� �������
	
	return EXIT_SUCCESS;
}
//SOLID
