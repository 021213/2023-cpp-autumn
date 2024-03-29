#include<iostream>
// MOO moo mOO Moo mOo
// Ook ook oOK

class CPoint
{
public:
	CPoint(double x, double y, double z) :
		_x(x), _y(y), _z(z) {}
	CPoint() :
		_x(0), _y(0), _z(0) {}
	CPoint(const CPoint& point) :
		_x(point._x), _y(point._y), _z(point._z) {}
	~CPoint()
	{
		_x = _y = _z = 0;
	}

	double abs2()
	{
		return _x * _x + _y * _y + _z * _z;
	}

	double x()
	{
		return _x;
	}
	double y()
	{
		return _y;
	}
	double z()
	{
		return _z;
	}

	CPoint operator-(const CPoint point)
	{
		CPoint res;
		res._x = this->_x - point._x;
		res._y = this->_y - point._y;
		res._z = this->_z - point._z;
		return res;
	}

	CPoint operator*(double m)
	{
		CPoint res;
		res._x = _x * m;
		res._y = _y * m;
		res._z = _z * m;
		return res;
	}
	friend CPoint operator*(double m, CPoint point);
	friend std::ostream& operator<<(std::ostream& stream, CPoint p);

private:
	double _x;
	double _y;
	double _z;
};

double distance(CPoint p1, CPoint p2)
{
	CPoint point(p2 - p1);
	return sqrt(point.abs2());
}

void print(CPoint p)
{
	std::cout << "(" << p.x() << "; " << p.y() << "; " << p.z() << ")" << std::endl;
}

CPoint operator*(double m, CPoint point)
{
	CPoint res;
	res._x = point._x * m;
	res._y = point._y * m;
	res._z = point._z * m;
	return res;
}

std::ostream& operator<<(std::ostream& stream, CPoint p)
{
	stream << "(" << p._x << "; " << p._y << "; " << p._z << ")";
	return stream;
}

int main(int argc, char* argv[])
{
	CPoint p1(3, 1, 2);
	CPoint p2(-3, 2, -1);

	std::cout << distance(p1, p2) << std::endl;
	std::cout << p1 << " - " << p2 << " = " << p1 - p2 << std::endl;
	print(p2 * 1.5);
	print(1.5 * p2);

	//int a = 10;
    //        10     12    13   13            14
	//int b = a++ + ++a + ++a + a++;      //  48
	return EXIT_SUCCESS;
}
