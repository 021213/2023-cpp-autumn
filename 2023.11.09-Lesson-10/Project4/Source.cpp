#include<iostream>

enum FigureType
{
	POINT,
	LINE,
	TRIANGLE
};

struct Point {
	float x;
};

struct Line {
	float x;
	float y;
};

struct Triangle {
	float x;
	float y;
	float z;
};

union UFigure {
	Point p;
	Line l;
	Triangle t;
};

struct Figure
{
	FigureType type;
	UFigure data;
};

void printSumCoords(Figure f)
{
	switch (f.type)
	{
	case POINT:
		std::cout << f.data.p.x;
	case LINE:
		std::cout << f.data.l.x + f.data.l.y;
	case TRIANGLE:
		std::cout << f.data.t.x + f.data.t.y + f.data.t.z;
	}
}

int main(int argc, char* argv[])
{
	Figure f1;
	f1.type = LINE;
	f1.data.l.x = 5;
	f1.data.l.y = 7;

	return EXIT_SUCCESS;
}