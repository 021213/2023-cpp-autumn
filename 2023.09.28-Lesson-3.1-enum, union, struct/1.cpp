#include<iostream>

enum PersonInfo{ MALE = 1, FEMALE = 2, STUDENT = 4, TEACHER = 8 };
		//0b0001	0b0010	0b0100	0b1000
int main()
{
	int info1 = MALE | TEACHER;//0b1001
	//0b1001
	//0b0001
	//0b0001 -> true
	if (info1 & MALE) {
		std::cout << "MALE";
	}
	
	return 0;
}
