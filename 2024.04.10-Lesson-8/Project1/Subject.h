#pragma once
#include<string>

class Subject
{
public:
	Subject();
	Subject(std::string name);
	Subject(const Subject& other);
	Subject(Subject&& other);
	~Subject();
	Subject operator=(Subject other);
	bool operator<(Subject other);
	bool operator==(Subject other);
	bool operator>(Subject other);
	bool operator<=(Subject other);
	bool operator>=(Subject other);
	bool operator!=(Subject other);
	//Subject operator+=(int mark);
	friend std::ostream& operator<<(std::ostream& stream, Subject& subject);
	//std::string toString();
private:
	void dispose();
	std::string _name;
	int* _marks;
	int _markscount;
};

