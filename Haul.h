#pragma once
#include <iostream>
class Haul
{
private:
	static int next_id;
	int id;
	bool** chairs;
	int rows;
	int cols;

	void free();
	void copyfrom(const Haul& other);
public:
	int get_id() const;
	bool** get_chairs() const;
	int get_rows() const;
	int get_cols() const;
	int get_chair_at(int i, int j) const;

	void set_id(int id);
	void set_rows(int i);
	void set_cols(int j);
	void set_chairs(int i, int j);
	void set_chair(int i, int j, bool val);
	void take_chair_at(int i, int j);

	Haul();
	Haul(int r, int c);
	Haul(const Haul& other);
	Haul& operator=(const Haul& other);
	~Haul();
};

