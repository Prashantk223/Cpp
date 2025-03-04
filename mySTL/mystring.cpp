#include "mystring.h"
#include <cstring>


mystring::mystring()
{
	str = NULL;
	len = 0;
}
mystring::mystring(const char* s)
{
	len = mystrlen(s);
	str = new char[len + 1];
	mystrcpy(str, s);
}
mystring::mystring(const mystring& s)
{
	if (s.str != NULL)
	{
		len = mystrlen(s.str);
	}
}
mystring& mystring::operator=(const mystring& s)
{
	if (str != NULL)
	{
		delete[] str;
	}
	if (s.str != NULL)
	{
		len = mystrlen(s.str);
		str = new char[len + 1];
		mystrcpy(str, s.str);
	}
	return *this;
}
//s1 = s2 + s3;
mystring mystring::operator+(const mystring& s)
{
	//Here, can not directly access the temp class's str and len therefore create the concat buffer and then create the temp with constructor to copy the concat string
	int length = len + s.len;
	char *buffer = new char[1 + length];
	mystrcpy(buffer, str);
	mystrcpy(buffer + len, s.str);


	//create tmp class and return it. tmp will be popped off the stack but return will give the values to calling function/class via stack
	mystring tmp(buffer);
	delete[] buffer;

	return tmp;
}


bool mystring::operator==(const mystring& s)
{
	if (mystrlen(str) != mystrlen(s.str))
	{
		return false;
	}
	// do not use while loop as it will require s.str++. this is constant argument and therefore can not be changed
	for (int i = 0; i < len; i++)
	{
		if (s.str[i] != str[i])
			return false;
	}
	return true;

}

bool mystring::operator!=(const mystring& s) {
	return !(*this == s);
}
bool mystring::operator<(const mystring& s)
{
	if (str == NULL && s.str != NULL)
	{
		return true;
	}
	else if (str != NULL && s.str == NULL)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < len && i < s.len; i++)
		{
			if (str[i] < s.str[i])
			{
				return true;
			}
			else if (str[i] > s.str[i])
			{
				return false;
			}
		}
		return len < s.len;

	}

}
bool mystring::operator>(const mystring& s)
{
	return !(*this >= s);
}
bool mystring::operator<=(const mystring& s)
{
	return !(*this > s);
}
bool mystring::operator>=(const mystring& s) {
	return !(*this < s);
}

//Here we return char regerence because it givess access to modify string when it is on left side strstring[0] = 'H'
//but when it is on left side it will let anyone modify itself, since ch is a separate variable (char), it stores a copy of myStr[0].
//char ch = strstring[0]
// but in case char &ch = strstring[0] it lets ch to modify strstring[0]

char& mystring::operator[](int i) {
	return	str[i];
}
std::ostream& operator<<(std::ostream& os, const mystring& s)
{
	if (s.str != NULL)
	{
		std::cout << s.str;
	}

	return os;
}
//if the local buffer inputs a string longer than 1000 characters, the program will experience buffer overflow, potentially leading to :

std::istream& operator>>(std::istream& is, mystring& s)
{

	//to be implemented
	//dont know how to handle length of 'is'

	size_t length = is.gcount();
	char* buffer = new char[length + 1];
	if (s.str != NULL)
	{
		delete[] s.str;
	}

	is >> buffer;
	s.str = new char[length + 1];
	mystrcpy(s.str, buffer);
	delete[] buffer;

	return is;
}


int mystring::getlen()
{
	return len;
}
mystring::~mystring()
{
	if (str != NULL)
	{
		delete[] str;
	}
}