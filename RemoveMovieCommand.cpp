#include "RemoveMovieCommand.h"

void RemoveMovieCommand::execute(System* sys, Session* ses, mystring& args)
{
	int movie_id = args.drop_first_subword().convert_to_int();
	int movie_count = sys->get_movies().get_count();

	
	/*if (sys->get_movie_by_id(movie_id) == nullptr) {
		std::cout << "No movie with ID " << movie_id << " exists!" << std::endl;
		return;
	}*/

	int refund = sys->get_movie_by_id(movie_id)->get_price();
	int user_count = sys->get_customers().get_count();

	if (!sys->get_movie_by_id(movie_id)->has_been_projected()) {
		//int user_count = sys->get_customers().get_count();
		int tickets_count;
		for (int i = 0; i < user_count; i++) {
			tickets_count = sys->get_customers()[i]->get_tickets().get_count();
			for (int j = 0; j < tickets_count; j++) {
				if (sys->get_customers()[i]->get_tickets()[j]->get_movie()->get_id() == movie_id) {
					sys->get_customers()[i]->set_balance(sys->get_customers()[i]->get_balance() + refund);
				}
			}
		}
		int admin_tickets = sys->get_admin()->get_tickets().get_count();
		for (int k = 0; k < admin_tickets; k++) {
			if (sys->get_admin()->get_tickets()[k]->get_movie()->get_id() == movie_id) {
				sys->get_admin()->set_balance(sys->get_admin()->get_balance() + refund);

			}
		}
	}

	else {
		int user_count = sys->get_customers().get_count();
		for (int i = 0; i < user_count; i++) {
			sys->get_customers()[i]->get_watched_movies().remove_by_id(movie_id);
		}
		sys->get_admin()->get_watched_movies().remove_by_id(movie_id);
	}
	remove_ticket(movie_id, user_count, sys);
	sys->get_movies().remove_by_id(movie_id);
	

	std::cout << "Movie with id " << movie_id << " successfully removed from everywhere" << std::endl;
}

void remove_ticket(int movie_id, int user_count, System* sys)
{
	int customer_tickets_count, ticket_id;
	for (int i = 0; i < user_count; i++) {
		customer_tickets_count = sys->get_customers()[i]->get_tickets().get_count();
		for (int j = 0; j < customer_tickets_count; j++) {

			if (sys->get_customers()[i]->get_tickets()[j]->get_movie()->get_id() == movie_id) {
				ticket_id = sys->get_customers()[i]->get_tickets()[j]->get_id();
				--customer_tickets_count;
				sys->get_ticket_by_id(ticket_id)->free_chair();
				sys->get_customers()[i]->get_tickets().remove_by_id(ticket_id);
			}
		}
	}

	customer_tickets_count = sys->get_admin()->get_tickets().get_count();
	for (int k = 0; k < customer_tickets_count; k++) {
		if (sys->get_admin()->get_tickets()[k]->get_movie()->get_id() == movie_id) {
			--customer_tickets_count;
			ticket_id = sys->get_admin()->get_tickets()[k]->get_id();
			sys->get_ticket_by_id(ticket_id)->free_chair();
			sys->get_admin()->get_tickets().remove_by_id(ticket_id);
		}
	}
}
