#include<iostream>

using namespace std;

void inputMatrix(int a[101][101], int& n)
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
		}
	}
}

void outputMatrix(int a[101][101], int n)
{
	cout << n << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}

void inputEdges(int a[101][101], int& n)
{
	cin >> n;
	int m = 0;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;
		a[s][e] += 1; //в некоторых задачах без добавления
	}
}

void outputEdges(int a[101][101], int n)
{
	int m = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			m += a[i][j];
		}
	}
	cout << n << " " << m << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (a[i][j] == 1)
			{
				cout << i << " " << j << endl;
			}
		}
	}
}

void inputAdjencyList(int a[101][101], int &n)
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int edges = 0;
		cin >> edges;
		for (int j = 0; j < edges; ++j)
		{
			int end = 0;
			cin >> end;
			a[i][end] = 1;
		}
	}
}

void outputAdjencyList(int a[101][101], int n)
{
	cout << n << endl;
	for (int i = 1; i <= n; ++i)
	{
		int count = 0;
		for (int j = 1; j <= n; ++j)
		{
			count += a[i][j];
		}
		cout << count << " ";
		for (int j = 1; j <= n; ++j)
		{
			if (a[i][j] == 1)
			{
				cout << j << " ";
			}
		}
		cout << endl;
	}
}

void outputPowers(int a[101][101], int n)
{
	int powers[101] = { 0 };
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			powers[i] += a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << powers[i] << " ";
	}
}

bool isRegular(int a[101][101], int n)
{
	int powers[101] = { 0 };
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			powers[i] += a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (powers[i] != powers[1])
		{
			return false;
		}
	}
	return true;
}

bool isOriented(int a[101][101], int n)
{
	bool result = false;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i][i] == 1)
		{
			return false;
		}
		for (int j = 1; j <= n; ++j)
		{
			if (a[i][j] != a[j][i])
			{
				result = true;
			}
		}
	}
	return result;
}

bool isFull(int a[101][101], int n)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			if (a[i][j] + a[j][i] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void printOrigins(int a[101][101], int n)
{
	bool origin[101]{ 0 };
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		origin[i] = true;
		for (int j = 1; j <= n; ++j)
		{
			origin[i] &= a[j][i] == 0;
		}
		count += (int)origin[i];
	}
	cout << count << " ";
	for (int i = 1; i <= n; ++i)
	{
		if (origin[i])
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

void printDrains(int a[101][101], int n)
{
	bool drain[101]{ 0 };
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		drain[i] = true;
		for (int j = 1; j <= n; ++j)
		{
			drain[i] &= a[i][j] == 0;
		}
		count += (int)drain[i];
	}
	cout << count << " ";
	for (int i = 1; i <= n; ++i)
	{
		if (drain[i])
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

bool isTournament(int a[101][101], int n)
{
	for (int i = 1; i <= n; ++i)
	{
		if (a[i][i] == 1)
		{
			return false;
		}
		for (int j = i + 1; j <= n; ++j)
		{
			if (a[i][j] + a[j][i] != 1)
			{
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	int a[101][101]{ 0 };
	int n = 0;
	inputMatrix(a, n);
	outputEdges(a, n);
	return 0;
}