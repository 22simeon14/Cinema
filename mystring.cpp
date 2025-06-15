#include "mystring.h"
#include "mystring.h"
void mystring::free() {
	delete[] data;
}
void mystring::copyfrom(const mystring& other) {
	size_t len = other.getlen() + 1;
	data = new char[len];
	strcpy_s(data, len, other.c_str());
}
const size_t mystring::getlen() const {
	return strlen(data);
}
const char* mystring::c_str() const {
	return data;
}
mystring::mystring(const char* str) {
	if (!str) {
		data = new char[1];
		data[0] = '\0';
	}
	else {
		size_t len = strlen(str) + 1;
		data = new char[len];
		strcpy_s(data, len, str);
	}
}
mystring::mystring() {
	data = new char[1];
	data[0] = '\0';
}
mystring::mystring(const mystring& other) {
	copyfrom(other);
}
mystring& mystring::operator=(const mystring& other) {
	if (this != &other) {
		free();
		copyfrom(other);
	}
	return *this;
}
mystring::~mystring() {
	free();
}

mystring mystring::drop_first_subword() {
	int len = strlen(data);
	int i = 0;

	// Find end of first word
	while (i < len && data[i] != ' ')
		i++;

	// Copy first word
	char* word = new char[i + 1];
	strncpy(word, data, i);
	word[i] = '\0';
	mystring result(word);
	delete[] word;

	// Skip any spaces
	int j = i;
	while (j < len && data[j] == ' ')
		j++;

	// Copy remaining string
	int rem_len = len - j;
	char* remainder = new char[rem_len + 1];
	strcpy(remainder, data + j);

	// Replace this->data
	delete[] data;
	data = remainder;

	return result;
}

int mystring::convert_to_int()
{
	int len = strlen(data);
	int res = 0;
	for (int i = 0; i < len; i++) {
		res = res * 10 + (data[i] - '0');
	}
	return res;
}
/*
double mystring::convert_to_double_grade()
{
	if (this->data[1] != '.' || this->getlen() != 4) {
		std::cerr << "Invalid grade format!" << std::endl;
	}
	double res = (data[0] - '0') * 100 + (data[2] - '0') * 10 + (data[3] - '0');
	res /= 100;
	return res;
}
*/

mystring& mystring::operator+=(const mystring& other) {
	size_t res_len = this->getlen() + other.getlen() + 1;
	char* result = new char[res_len];
	result[0] = '\0';
	strcat_s(result, res_len, this->data);
	strcat_s(result, res_len, other.c_str());
	delete[] this->data;
	data = new char[res_len];
	strcpy_s(data, res_len, result);
	delete[] result;
	return *this;
}
char& mystring::operator[](size_t index) {
	//returns the last element of  mystring if index >= length of string
	if (index >= this->getlen()) index = getlen() - 1;
	return this->data[index];
}
const char mystring::operator[](size_t index) const {
	//returns the last element of  mystring if index >= length of string
	if (index >= this->getlen()) index = getlen() - 1;
	return this->data[index];
}
std::istream& operator>>(std::istream& is, mystring& string) {
	char buffer[1024];
	is >> buffer;

	size_t buffer_len = strlen(buffer) + 1;
	if (string.data != nullptr)
		delete[] string.data;
	string.data = new char[buffer_len];
	strcpy_s(string.data, buffer_len, buffer);
	return is;
}

void mystring::getline(std::istream& is) {
	char buffer[1024];
	is.getline(buffer, 1024);

	size_t len = strlen(buffer) + 1;
	delete[] data;
	data = new char[len];
	strcpy_s(data, len, buffer);
}

std::ostream& operator<<(std::ostream& os, const mystring& string) {
	return os << string.c_str();
}
mystring operator+(const mystring& lhs, const mystring& rhs) {
	mystring res(lhs);
	res += rhs;
	return res;
}

bool operator>(const mystring& lhs, const mystring& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator>=(const mystring& lhs, const mystring& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator<(const mystring& lhs, const mystring& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}
bool operator<=(const mystring& lhs, const mystring& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator==(const mystring& lhs, const mystring& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const mystring& lhs, const mystring& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}
