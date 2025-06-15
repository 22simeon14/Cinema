#include "Haul.h"

int Haul::next_id = 400;

void Haul::free()
{
	for (int i = 0; i < rows; i++) {
		delete[] chairs[i];
	}
	delete[] chairs;
}

void Haul::copyfrom(const Haul& other)
{
	this->chairs = new bool* [other.rows];
	for (int i = 0; i < other.rows; i++) {
		this->chairs[i] = new bool[other.cols];
	}
	for (int i = 0; i < other.rows; i++) {
		for (int j = 0; j < other.cols; j++) {
			this->chairs[i][j] = other.chairs[i][j];
		}
	}
	this->id = other.id;
	this->rows = other.rows;
	this->cols = other.cols;
}

int Haul::get_id() const
{
	return id;
}

bool** Haul::get_chairs() const
{
	return chairs;
}

int Haul::get_rows() const
{
	return rows;
}

int Haul::get_cols() const
{
	return cols;
}

int Haul::get_chair_at(int i, int j) const
{
	if (i < 0 || i >= rows || j < 0 || j >= cols) {
		std::cout << "Invalid indices of a chair! Returning the first one..." << std::endl;
		return chairs[0][0];
	}
	return chairs[i][j];
}

void Haul::set_id(int id)
{
	if (id < 0) {
		std::cout << "Id of room cannot be negative!" << std::endl;
		return;
	}
	this->id = id;
}

void Haul::set_rows(int i)
{
	if (i < 1) {
		std::cout << "Rows cannot be less than 1! Setting default value (1)..." << std::endl;
		this->rows = 1;
		return;
	}
	this->rows = i;
}

void Haul::set_cols(int j)
{
	if (j < 1) {
		std::cout << "Cols cannot be less than 1! Setting default value (1)..." << std::endl;
		this->cols = 1;
		return;
	}
	this->cols = j;
}

void Haul::set_chairs(int i, int j)
{
	if (i < 1 || j < 1) {
		std::cout << "Invalid chairs dimensions! Creating default 2-dim array (1*1) ..." << std::endl;
		this->rows = 2;
		this->cols = 2;
		this->chairs = new bool* [2];
		this->chairs[0] = new bool[2];
		this->chairs[1] = new bool[2];
		return;
	}
	this->rows = i;
	this->cols = j;
	this->chairs = new bool* [i];
	for (int k = 0; k < i; k++) {
		this->chairs[k] = new bool[j];
	}
}

void Haul::set_chair(int i, int j, bool val)
{
	chairs[i][j] = val;
}

void Haul::take_chair_at(int i, int j)
{
	chairs[i][j] = 1;
}

Haul::Haul()
{
	id = next_id++;
	this->rows = 2;
	this->cols = 2;
	set_chairs(rows, cols);
}

Haul::Haul(int r, int c)
{
	id = next_id++;
	set_rows(r);
	set_cols(c);
	set_chairs(rows, cols);
}

Haul::Haul(const Haul& other)
{
	copyfrom(other);
}

Haul& Haul::operator=(const Haul& other)
{
	if (this != &other) {
		free();
		copyfrom(other);
	}
	return *this;
}

Haul::~Haul()
{
	free();
}
