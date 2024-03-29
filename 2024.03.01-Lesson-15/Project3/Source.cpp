#include<iostream>
#include<string>

/*
абстракци€
инкапсул€ци€
наследование
полиморфизм
*/

enum EStudentState {
	otchislen,
	neotchislen,
	vakademe,
	spit,
	agafonov
};

enum ERole {
	STUDENT = 0,
	PREPOD = 1,
	ADMIN = 2,
	VAHTER = 3,
	DISPETCHERRASPISANIYA = 4
};

struct SDate {
	int year; //поле
	int month; //поле
	int day; //поле
	//конструктор + конструктор по умолчанию
	SDate(int y = 1990, int m = 1, int d = 1)
	{
		year = y;
		month = m % 12 + 1; // 1 .. 12
		day = d % 30 + 1; //1 .. 30
	}
};

struct SPerson {
	int id;
	std::string firstname;
	std::string secondname;
	SDate dateOfBirth;
	ERole role;
	int* code;

	SPerson(int i, std::string fn, std::string sn,
		SDate date, ERole r, int* c) //конструктор
	{
		id = i;
		firstname = fn;
		secondname = sn;
		dateOfBirth = date;
		role = r;
		code = c;
	}

	~SPerson() //деструктор
	{
		id = 0;
		delete[] code;
	}
};

struct SStudent : SPerson {
	EStudentState state;
	int obshaganum;
};

void print(SPerson p)
{
	std::cout << "\t";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << p.code[i] << " ";
	}
	std::cout << "\n";
	std::cout << p.id << " " << p.firstname << " " << p.secondname;
	std::cout << std::endl << '\t';
	std::cout << p.dateOfBirth.year << "." << p.dateOfBirth.month << "." << p.dateOfBirth.day << std::endl;
	std::cout << "\trole : " << p.role << std::endl << std::endl;

	p.id = 100;
	p.code[9] = 1234;
}

int main(int argc, char* argv[])
{
	SPerson pers1(1, "Grigory A.", "Nesterchuk",
		SDate(), PREPOD,
		new int[10] {1, 2, 3, 4, 5});

	SPerson pers2{
		2,
		"Grigory A.",
		"Nesterchuk",
		SDate(1991, 3, 12),
		PREPOD,
		new int[10] {3, 3, 3, 4, 5}
	};

	print(pers1);
	print(pers2);
	print(pers2);

	return EXIT_SUCCESS;
}