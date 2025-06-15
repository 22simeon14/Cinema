#pragma once
#include "Vector.h"
#include "Movie.h"
#include "Customer.h"
#include "Ticket.h"
#include "Haul.h"
#include "Admin.h"
class System
{
	friend class Admin;	
private:
	Admin* admin;
	Vector<Movie*> movies;
	Vector<Customer*> customers;
	Vector<Ticket*> tickets;
	Vector<Haul*> hauls;
public:
	Admin* get_admin() const;
	Vector<Movie*>& get_movies();
	Vector<Customer*>& get_customers();
	Vector<Ticket*>& get_tickets();
	Vector<Haul*>& get_hauls();

	Movie* get_movie_by_id(int id);
	Haul* get_haul_by_id(int id);
	User* get_user_by_id(int id);
	Ticket* get_ticket_by_id(int id);

	System();
	~System() = default;

	//helper functions
	void return_money_to_customers(int movie_id);
	void delete_movie_from_watch_history(int movie_id);


	std::ofstream& Save(std::ofstream& ofs);
	std::ifstream& Load(std::ifstream& ifs);
};

