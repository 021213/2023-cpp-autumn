#include<iostream>
#include<string>

class Message {
public:
	std::string text;
	Message() : text("")
	{
		std::cout << "default" << std::endl;
	}
	Message(std::string text) : text(text)
	{
		std::cout << "parametrized" << std::endl;
	}
	Message(const Message& message) : text(message.text)
	{
		std::cout << "copy" << std::endl;
	}
	Message(Message&& message) : text(message.text)
	{
		std::cout << "move" << std::endl;
	}
	~Message()
	{
		std::cout << "destructor " + text << std::endl;
	}
};

void print(Message message)
{
	std::cout << message.text << std::endl;
}

int main(int argc, char* argv[])
{
	Message m1;
	Message m2("m2");
	print(Message("vasya"));
	int x = 5;
	std::move(x);

	std::string str1 = "vasya";
	std::string str2 = "pupkin";
	std::string str3 = std::move(str1) + " " + str2;
	std::string str4 = "vasya";
	str1[3] = 'p';

	return EXIT_SUCCESS;
}