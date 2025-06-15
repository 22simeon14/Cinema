#pragma once
#include "mystring.h"
#include "Vector.h"
#include "Ticket.h"
#include "Movie.h"
class User
{
private:
	static int next_id;
	int id;
	mystring first_name;
	mystring last_name;
	mystring password;
	double balance;
	Vector<Ticket*> tickets;
	Vector<Movie*> watched_movies;
	
	
public:
	int get_id() const;
	const mystring get_first_name() const;
	const mystring get_last_name() const;
	const mystring get_password() const;
	double get_balance() const;
	Vector<Ticket*>& get_tickets();
	Vector<Movie*>& get_watched_movies();

	void set_first_name(const mystring fn);
	void set_last_name(const mystring ln);
	void set_password(const mystring pass);
	void set_balance(double b);
	void set_id(int id);

	User();
	User(const mystring& fn, const mystring& ln, const mystring& pass, double b);
	virtual ~User() = default;

	virtual const char* get_role() const = 0;

	//helper functions
	bool has_watched_movie(int movie_id) const;
	bool has_ticket_for(int movie_id) const;
	void print_user() const;
};


