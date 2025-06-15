#include "Ticket.h"

int Ticket::next_id = 200;

int Ticket::get_id() const
{
	return 0;
}

Movie* Ticket::get_movie()
{
	return movie;
}

int Ticket::get_i() const
{
	return i;
}

int Ticket::get_j() const
{
	return j;
}


void Ticket::set_id(int new_id)
{
	if (new_id < 0) {
		std::cout << "Invalid ticket id!" << std::endl;
	}
}

void Ticket::set_movie(Movie* m)
{
	if (m == nullptr) {
		std::cout << "Cannot set ticket movie to nullptr!" << std::endl;
		return;
	}
	this->movie = m;
}

void Ticket::set_i(int i)
{
	if (i < 0 || i >= movie->get_haul()->get_rows()) {
		std::cout << "Ticket seat out of bounds! Setting the seat axis to default (0) ..." << std::endl;
		this->i = 0;
		return;
	}
	this->i = i;
}

void Ticket::set_j(int j)
{
	if (j < 0 || j >= movie->get_haul()->get_cols()) {
		std::cout << "Ticket seat out of bounds! Setting the seat ordinate to default (0) ..." << std::endl;
		this->j = 0;
		return;
	}
	this->j = j;
}

void Ticket::free_chair()
{
	movie->get_haul()->set_chair(i, j, 0);
}

Ticket::Ticket()
{
	movie = nullptr;
	set_i(0);
	set_j(0);
	id = next_id++;
}

Ticket::Ticket(Movie* m, int i, int j)
{
	set_movie(m);
	set_i(i);
	set_j(j);
	id = next_id++;
}
/*
bool Ticket::is_outdated() const
{
	std::time_t now = std::time(nullptr);
	std::tm* current_tm = std::localtime(&now);

	std::tm movie_tm = {};
	movie_tm.tm_year = movie->get_proj_date().year - 1900;       // tm_year is years since 1900
	movie_tm.tm_mon = movie->get_proj_date().month - 1;         // tm_mon is 0-based (0 = Jan)
	movie_tm.tm_mday = movie->get_proj_date().day;
	movie_tm.tm_hour = movie->get_proj_start().hour;
	movie_tm.tm_min = movie->get_proj_start().minutes;
	movie_tm.tm_sec = 0;

	std::time_t movie_time = std::mktime(&movie_tm);

	if (movie_time == -1) return false;

	return std::difftime(now, movie_time) > 0;
}
*/
void Ticket::print_ticket() const
{
	std::cout << "Ticket id: " << id << ", movie title: " << movie->get_title() << ", row: " << i << ", col: " << j << std::endl;
}
