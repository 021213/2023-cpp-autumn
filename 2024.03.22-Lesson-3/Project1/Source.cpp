#include<iostream>
#include<ctime>

class Matrix {
public:
	//Matrix() : n(1), m(1), data(new int* [1] {new int[1] {0}}) {}
	Matrix(int n = 1, int m = 1) : _n(n), _m(m), _data(createMatr(n, m))
	{
		/*
		3 * 4
		[   0  1  2  3
		 0 [0, 0, 0, 0],
		 1 [0, 0, 7, 0],
		 2 [0, 5, 0, 0]
		]
		*/
		/*
		12
		 0  1  2  3  4  5  6  7  8  9 10 11
		[0, 0, 0, 0, 0, 0, 7, 0, 0, 5, 0, 0]
		[i, j] -> i * m + j
		[1, 2] -> 1 * 4 + 2 = 6 -> [6 / 4, 6 % 4]
		[2, 1] -> 2 * 4 + 1 = 9 -> [9 / 4, 9 % 4]
		[i, j] -> [k] = i * m + j
		[k] -> [i, j] = [k / m, k % m]
		*/
	}
	Matrix(const Matrix& matr) : _n(matr._n), _m(matr._m)
	{
		_data = createMatr(_n, _m);
		for (int i = 0; i < _n; ++i)
		{
			for (int j = 0; j < _m; ++j)
			{
				_data[i][j] = matr._data[i][j];
			}
		}
	}
	~Matrix()
	{
		deleteMatr(_data, _n, _m);
	}
	int det()
	{
		if (_n != _m)
		{
			return 0;
		}
		return det(_data, _n);
	}
	void test()
	{
		for (int i = 0; i < _n; ++i)
		{
			for(int j = 0; j < _m; ++j)
			{
				_data[i][j] = rand() % 6 * (rand() % 2 == 0 ? 1 : -1);
			}
		}
		for (int i = 0; i < _n; ++i)
		{
			for (int j = 0; j < _m; ++j)
			{
				std::cout << _data[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

		int** mdata = minor(_data, _n, 1, 1);
		for (int i = 0; i < _n - 1; ++i)
		{
			for (int j = 0; j < _m - 1; ++j)
			{
				std::cout << mdata[i][j] << " ";
			}
			std::cout << std::endl;
		}
		deleteMatr(mdata, _n - 1, _m - 1);
		int d = 0;
		int r = det();
		std::cin >> d;
		std::cout << (d == r ? ":-)" : ":-(") << std::endl;
	}
	int** inverse()
	{
		if (_n != _m)
		{
			return nullptr;
		}
		int d = det();
		int** res = createMatr(_n, _n);
		for (int i = 0; i < _n; ++i)
		{
			for (int j = 0; j < _n; ++j)
			{
				res[i][j] = algDop(_data, _n, j, i); // algDop(_data, _n, j, i) / d;
			}
		}
		return res;
	}

private:
	int** createMatr(int n, int m)
	{
		int** data = new int* [n] {0};
		for (int i = 0; i < n; ++i)
		{
			data[i] = new int[m] {0};
		}
		return data;
	}
	void deleteMatr(int**& data, int n, int m)
	{
		for (int i = 0; i < n; ++i)
		{
			delete[] data[i];
		}
		delete[] data;
		data = nullptr;
	}
	int det(int** data, int n)
	{
		if (n == 1)
		{
			return data[0][0];
		}
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			res += data[i][0] * algDop(data, n, i, 0);
		}
		return res;
	}
	int** minor(int** data, int n, int x, int y)
	{
		int** res = createMatr(n - 1, n - 1);
		for (int i = 0, ri = 0; i < n; ++i)
		{
			if (i == x) continue;
			for (int j = 0, rj = 0; j < n; ++j)
			{
				if (j == y) continue;
				res[ri][rj] = data[i][j];
				++rj;
			}
			++ri;
		}
		return res;
	}
	int algDop(int** data, int n, int x, int y)
	{
		int** mnr = minor(data, n, x, y);
		int res = det(mnr, n - 1) * ((x + y) % 2 == 0 ? 1 : -1);
		deleteMatr(mnr, n - 1, n - 1);
		return res;
	}
	int _n;
	int _m;
	int** _data;
};

int main(int argc, char* argv[])
{
	srand(time(0));
	Matrix m(3, 3);
	m.test();
	return EXIT_SUCCESS;
}