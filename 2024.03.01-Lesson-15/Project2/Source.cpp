#include<iostream>

enum EColor {
	RED = 0xFF0000,
	GREEN = 0x00FF00,
	BLUE = 0x0000FF
};

union UNumber {
	int i;
	float f;
	double d;
	//____ ____
};

struct SStudent {
	
};

int main(int argc, char* argv[])
{
	EColor color1 = RED;
	EColor color2 = BLUE;
	SStudent student1;
	UNumber num;
	//num.i = 5;
	//std::cout << num.f;

	return EXIT_SUCCESS;
}