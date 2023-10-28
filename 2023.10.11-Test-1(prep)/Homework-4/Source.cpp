#include<cstdio>
#include<cstdlib>
#include<ctime>

int main(int argc, char** argv)
{
	srand(time(0));

	int n = 0;
	scanf_s("%d", &n);

	int* a = (int*)malloc(sizeof(int) * n);

	{
		for (int i = 0; i < n; ++i)
		{
			*(a + i) = rand() % 20 - 9;
		}
	}
	{
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", *(a + i));
		}
		printf("\n");
	}
	{
		int countPositive = 0;
		for (int i = 0; i < n; ++i)
		{
			countPositive += (*(a + i) > 0 ? 1 : 0);
		}
		printf("Count Positive = %d\n", countPositive);
	}
	{
		printf("Even indexes: ");
		for (int i = 0; i < n; i += 2)
		{
			printf("%d ", *(a + i));
		}
		printf("\n");
	}
	{
		printf("Odd elements: ");
		for (int i = 0; i < n; ++i)
		{
			if (*(a + i) % 2 == 0)
			{
				continue;
			}
			printf("%d ", *(a + i));
		}
		printf("\n");
	}
	{
		int max = *a;
		for (int i = 0; i < n; ++i)
		{
			max = (*(a + i) > max ? *(a + i) : max);
		}
		printf("Max = %d\n", max);
	}
	{
		printf("reverse: ");
		for (int i = n - 1; i >= 0; --i)
		{
			printf("%d ", *(a + i));
		}
		printf("\n");
	}
	{
		printf("reverse:");
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", *(a + n - i - 1));
		}
		printf("\n");
	}
	{
		int mxInd = 0;
		for (int i = 0; i < n; ++i)
		{
			mxInd = (*(a + i) >= *(a + mxInd) ? i : mxInd);
		}
		int mnInd = 0;
		for (int i = 0; i < n; ++i)
		{
			mnInd = (*(a + i) < *(a + mnInd) ? i : mnInd);
		}
		int c = *(a + mxInd);
		*(a + mxInd) = *(a + mnInd);
		*(a + mnInd) = c;
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", *(a + i));
		}
		printf("\n");
	}
	{
		for (int i = 0; i < n; ++i)
		{
			if (*(a + i) < 0)
			{
				for (int j = i; j < n - 1; ++j)
				{
					*(a + i) = *(a + i + 1);
				}
				--n;
			}
		}

		int* b = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; ++i)
		{
			*(b + i) = *(a + i);
		}
		free(a);
		a = b;

		for (int i = 0; i < n; ++i)
		{
			printf("%d ", *(a + i));
		}
	}

	free(a);
	return 0;
}