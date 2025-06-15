#pragma once
#include <ctime>
#include "Movie.h"
#include "Haul.h"
class Ticket
{
private:
	static int next_id;
	int id;
	Movie* movie;
	int i;
	int j;
public:
	int get_id() const;
	Movie* get_movie();
	int get_i() const;
	int get_j() const;

	void set_id(int new_id);
	void set_movie(Movie* m);
	void set_i(int i);
	void set_j(int j);
	void free_chair();

	Ticket();
	Ticket(Movie* m, int i, int j);

	//bool is_outdated() const;
	void print_ticket() const;
};

