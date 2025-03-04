
#include "mystl.h"
#include <iostream>

void mystringTest(void);
int main(void)
{
	int choice;
	std::cout << "Testing the mySTL !" << std::endl;
	std::cout << "Input what would you like to test"<< std::endl;
	std::cout << "1. mystring" << std::endl;
	std::cin >> choice;

	switch (choice)
	{
		case 1:
		{
			mystringTest();
			break;
		}
	}
	return 0;
}

void mystringTest(void)
{

	mystring s1("Hello");
	mystring s2("World");
	mystring s3 = s1 + s2;
	std::cout << s3 << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	if (s1 == s2)
	{
		std::cout << "Equal" << std::endl;
	}
	else
	{
		std::cout << "Not Equal" << std::endl;
	}

	if (s1 != s2)
	{
		std::cout << "Not Equal" << std::endl;
	}
	else
	{
		std::cout << "Equal" << std::endl;
	}
}