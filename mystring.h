#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>

class mystring
{
private:
	char* data;
	void free();
	void copyfrom(const mystring& other);
public:
	const char* c_str() const;
	const size_t getlen() const;
	mystring(const char*);
	mystring();
	mystring(const mystring&);
	mystring& operator=(const mystring&);
	~mystring();

	mystring drop_first_subword();
	int convert_to_int();
	//double convert_to_double_grade();

	void getline(std::istream& ifs);
	mystring& operator+=(const mystring&);
	char& operator[](size_t);
	const char operator[](size_t) const;
	friend std::istream& operator>>(std::istream&, mystring&);
};
std::ostream& operator<<(std::ostream&, const mystring&);
mystring operator+(const mystring&, const mystring&);
bool operator>(const mystring&, const mystring&);
bool operator>=(const mystring&, const mystring&);
bool operator<(const mystring&, const mystring&);
bool operator<=(const mystring&, const mystring&);
bool operator==(const mystring&, const mystring&);
bool operator!=(const mystring&, const mystring&);
