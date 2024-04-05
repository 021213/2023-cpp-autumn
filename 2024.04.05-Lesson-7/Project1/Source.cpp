#include<iostream>

class CGraph {
public:
	CGraph(int n = 1) : _n(n), _matr(nullptr) { initMatrix(); };
	CGraph(const CGraph& src) : _n(src._n) {
		initMatrix();
		for (int i = 0; i < _n; ++i)
		{
			for (int j = 0; j < _n; ++j)
			{
				_matr[i][j] = src._matr[i][j];
			}
		}
	}
	~CGraph() { disposeMatrix(); }
	void readMatrix();
	void readAdj();
	void readEdges();
	void printMatrix();
	void printAdj();
	void printEdges();
	void printPowers();
	bool isFull();
	bool isOriented();
	bool isRegular();
private:
	void initMatrix();
	void disposeMatrix();
	int power(int vertex);
	int isSrc(int vertex);
	int _n;
	int** _matr;
};

void CGraph::initMatrix()
{
	_matr = new int* [_n] {0};
	for (int i = 0; i < _n; ++i)
	{
		_matr[i] = new int[_n] {0};
	}
}

void CGraph::disposeMatrix()
{
	for (int i = 0; i < _n; ++i)
	{
		delete[] _matr[i];
	}
	delete[] _matr;
}

int CGraph::power(int vertex)
{
	int pw = 0;
	for (int j = 0; j < _n; ++j)
	{
		pw += _matr[vertex][j];
	}
	return pw;
}

int CGraph::isSrc(int vertex)
{
	for (int i = 0; i < _n; ++i)
	{
		if (_matr[i][vertex] != 0)
		{
			return false;
		}
	}
	return true;
}

void CGraph::readMatrix()
{
	disposeMatrix();
	std::cin >> _n;
	initMatrix();
	for (int i = 0; i < _n; ++i)
	{
		for (int j = 0; j < _n; ++j)
		{
			std::cin >> _matr[i][j];
		}
	}
}

void CGraph::readAdj()
{
	disposeMatrix();
	std::cin >> _n;
	initMatrix();
	for (int i = 0; i < _n; ++i)
	{
		int m = 0;
		std::cin >> m;
		for (int j = 0; j < m; ++j)
		{
			int k = 0;
			std::cin >> k;
			_matr[i][k - 1] = 1;
		}
	}
}

void CGraph::readEdges()
{
	disposeMatrix();
	std::cin >> _n;
	initMatrix();
	int m = 0;
	std::cin >> m;
	for (int k = 0; k < m; ++k)
	{
		int i = 0;
		int j = 0;
		std::cin >> i >> j;
		_matr[i - 1][j - 1] = 1;
	}
}

void CGraph::printMatrix()
{
	std::cout << _n << std::endl;
	for (int i = 0; i < _n; ++i)
	{
		for (int j = 0; j < _n; ++j)
		{
			std::cout << _matr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void CGraph::printAdj()
{
	std::cout << _n << std::endl;
	for (int i = 0; i < _n; ++i)
	{
		std::cout << power(i) << " ";
		for (int j = 0; j < _n; ++j)
		{
			if (_matr[i][j] != 0)
			{
				std::cout << j + 1 << " ";
			}
		}
		std::cout << std::endl;
	}
}

void CGraph::printEdges()
{
	std::cout << _n << " ";
	int m = 0;
	for (int i = 0; i < _n; m += power(i), ++i);
	std::cout << m << std::endl;
	for (int i = 0; i < _n; ++i)
	{
		for (int j = 0; j < _n; ++j)
		{
			if (_matr[i][j] != 0)
			{
				std::cout << i + 1 << " " << j + 1 << " ";
			}
		}
		std::cout << std::endl;
	}
}

void CGraph::printPowers()
{
	for (int i = 0; i < _n; ++i)
	{
		std::cout << power(i) << " ";
	}
}

bool CGraph::isFull()
{
	if (!isOriented())
	{
		return false;
	}
	int m = 0;
	for (int i = 0; i < _n; m += power(i), ++i);
	return (m * 2 == _n * (_n - 1));
}

bool CGraph::isOriented()
{
	for (int i = 0; i < _n; ++i)
	{
		if (_matr[i][i] == 1)
		{
			return false;
		}
	}
	for (int i = 0; i < _n; ++i)
	{
		for (int j = i + 1; j < _n; ++j)
		{
			if (_matr[i][j] != _matr[j][i])
			{
				return true;
			}
		}
	}
	return false;
}

bool CGraph::isRegular()
{
	for (int i = 0; i < _n; ++i)
	{
		if (power(i) != power(0))
		{
			return false;
		}
	}
	return true;
}