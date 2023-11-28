#include<iostream>

typedef unsigned long long ull;

typedef struct {
	int x;
	int y;
} Point;

#define getrandom(min, max) \
    ((rand()%(int)(((max) + 1)-(min)))+ (min))

#define multiply( a1, a2 ) ( a1 * a2 )

int main(int argc, char* argv[])
{
	std::cout << multiply(3, 2) << std::endl;
	std::cout << getrandom(10, 99) << std::endl;
	return EXIT_SUCCESS;
}