#include<iostream>
#include<cmath>


double distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

struct Point {
	double x;
	double y;
};

double distance(Point p1, Point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void printPoint(Point p)
{
	printf("(%lf; %lf)\n", p.x, p.y);
}

int main(int argc, char* argv[])
{
	double x1 = 10;
	double y1 = 5;
	double x2 = 3;
	double y2 = 7;
	std::cout << distance(x1, y1, x2, y2) << std::endl;

	double pa1[2]{ 10, 5 };
	double pa2[2]{ 3, 7 };

	Point p1{ 0, 0 };
	printPoint(p1);
	p1.x = 10;
	p1.y = 5;
	Point p2{ 3, 7 };
	std::cout << distance(p1, p2) << std::endl;
	return EXIT_SUCCESS;
}