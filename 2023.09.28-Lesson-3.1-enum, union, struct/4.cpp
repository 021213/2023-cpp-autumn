#include<iostream>

struct Point2D {
	double x;
	double y;
};

int main()
{
	Point2D p;
	p.x = 23;
	p.y = 0.5;
	Point2D p1;
	Point2D p2;
	p1 = p;
	std::cout << sizeof(Point2D); //16
	return 0;
}