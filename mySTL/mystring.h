#pragma once
#include<iostream>
#include "commonAlgos.h"

class mystring
{
private:
	char* str;
	unsigned long long len;
public:
	mystring();
	mystring(const char* s);
	mystring(const mystring& s);
	~mystring();
	mystring& operator=(const mystring& s);
	mystring operator+(const mystring& s);
	bool operator==(const mystring& s);
	bool operator!=(const mystring& s);
	bool operator<(const mystring& s);
	bool operator>(const mystring& s);
	bool operator<=(const mystring& s);
	bool operator>=(const mystring& s);
	char& operator[](int i);
	friend std::ostream& operator<<(std::ostream& os, const mystring& s);
	friend std::istream& operator>>(std::istream& is, mystring& s);


	//commonutilityfunctions
	int getlen();
};