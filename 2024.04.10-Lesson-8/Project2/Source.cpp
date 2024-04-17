#include<iostream>
#include<string>
// this friend
struct Record {
public:
	std::string name;
	friend void printTime(Record* rec);
private:
	int time;
};

void printTime(Record* rec)
{
	std::cout << rec->time << std::endl;
}

int main(int argc, char* argv[])
{
	Record rec;
	rec.name = "Proga";

	Record* recs;
	// recs = new Record[1];
	recs = new Record();
	(*recs).name = "Matan";
	recs->name = "Matan";
	printTime(recs);
	delete recs;

	return EXIT_SUCCESS;
}