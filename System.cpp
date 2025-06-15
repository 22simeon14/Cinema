#include "System.h"

Admin* System::get_admin() const {
	return admin;
}

Vector<Movie*>& System::get_movies()
{
	return movies;
}

Vector<Customer*>& System::get_customers()
{
	return customers;
}

Vector<Ticket*>& System::get_tickets()
{
	return tickets;
}

Vector<Haul*>& System::get_hauls()
{
	return hauls;
}

Movie* System::get_movie_by_id(int id)
{
	int m_c = movies.get_count();
	for (int i = 0; i < m_c; i++) {
		if (movies[i]->get_id() == id) {
			return movies[i];
		}
	}
	throw std::invalid_argument("Movie not found!");
}

User* System::get_user_by_id(int id)
{
	int cus_c = customers.get_count();
	for (int i = 0; i < cus_c; i++) {
		if (customers[i]->get_id() == id) {
			return customers[i];
		}
	}
	if (id == 0) return admin;
	throw std::invalid_argument("User not found!");
}

Haul* System::get_haul_by_id(int id)
{
	int haul_c = hauls.get_count();
	for (int i = 0; i < haul_c; i++) {
		if (hauls[i]->get_id() == id) {
			return hauls[i];
		}
	}
	throw std::invalid_argument("Haul not found!");
}



Ticket* System::get_ticket_by_id(int id)
{
	int tickets_count = tickets.get_count();
	for (int i = 0; i < tickets_count; i++) {
		if (tickets[i]->get_id() == id) {
			return tickets[i];
		}
	}
	throw std::invalid_argument("Ticket not found!");

}

System::System() 
{
	admin = new Admin(this);
}



void System::return_money_to_customers(int movie_id)
{
	int customers_count = customers.get_count();
	for (int i = 0; i < customers_count; i++) {
		if (customers[i]->has_ticket_for(movie_id)) {
			std::cout << "The movie has not been projected yet, returning money to customers..." << std::endl;
			customers[i]->set_balance(customers[i]->get_balance() + get_movie_by_id(movie_id)->get_price());
		}
	}
	
}

void System::delete_movie_from_watch_history(int movie_id)
{
	int customers_count = customers.get_count();
	for (int i = 0; i < customers_count; i++) {
		if (customers[i]->has_watched_movie(movie_id)) {
			std::cout << "The movie had been projected, deleteing it from customers watch history..." << std::endl;
			customers[i]->get_watched_movies().remove_by_id(movie_id);
		}
	}
}

std::ofstream& System::Save(std::ofstream& ofs)
{
	return ofs;
}

std::ifstream& System::Load(std::ifstream& ifs)
{
	return ifs;
}
