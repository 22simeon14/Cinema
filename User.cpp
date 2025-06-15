#include "User.h"

int User::next_id = 100;

int User::get_id() const
{
	return id;
}

const mystring User::get_first_name() const
{
	return first_name;
}

const mystring User::get_last_name() const
{
	return last_name;
}

const mystring User::get_password() const
{
	return password;
}

double User::get_balance() const
{
	return balance;
}


void User::set_first_name(const mystring fn)
{
	if (fn == nullptr) {
		std::cout << "Cannot set user name to nullptr! Setting default value (x)..."<<std::endl;
		first_name = "x";
		return;
	}
	this->first_name = fn;
}

void User::set_last_name(const mystring ln)
{
	if (ln == nullptr) {
		std::cout << "Cannot set user name to nullptr! Setting default value (x)..." << std::endl;
		last_name = "x";
		return;
	}
	this->last_name = ln;
}

void User::set_password(const mystring pass)
{
	if (pass == nullptr) {
		std::cout << "Cannot set user password to nullptr! Setting default value (x)..." << std::endl;
		first_name = "x";
		return;
	}
	this->password = pass;
}

void User::set_balance(double b)
{
	if (b < 0) {
		std::cout << "Balance cannot be negative! Setting it to 0..." << ::std::endl;
		balance = 0;
		return;
	}
	this->balance = b;
}

void User::set_id(int id)
{
	this->id = id;
}


User::User() : first_name("x"), last_name("x"), password("x"),balance(0),id(1)
{
}

User::User(const mystring& fn, const mystring& ln, const mystring& pass, double b)
{
	set_first_name(fn);
	set_last_name(ln);
	set_password(pass);
	set_balance(b);
	id = next_id++;
}



Vector<Ticket*>& User::get_tickets()
{
	return tickets;
}

Vector<Movie*>& User::get_watched_movies()
{
	return watched_movies;
}



bool User::has_watched_movie(int movie_id) const
{

	int watched_movies_count = watched_movies.get_count();
	for (int i = 0; i < watched_movies_count; i++) {
		if (watched_movies[i]->get_id() == movie_id) return true;
	}
	return false;
}

bool User::has_ticket_for(int movie_id) const
{
	int ticket_count = tickets.get_count();
	for (int i = 0; i < ticket_count; i++) {
		if (tickets[i]->get_movie()->get_id() == movie_id) {
			return true;
		}
	}
	return false;
}

void User::print_user() const
{
	std::cout << first_name << " " << last_name << " " << "id: " << id << std::endl;
}
