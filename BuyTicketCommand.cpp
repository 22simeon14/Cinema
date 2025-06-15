#include "BuyTicketCommand.h"

void BuyTicketCommand::execute(System* sys, Session* ses, mystring& args)
{
	int movieId = args.drop_first_subword().convert_to_int();
	int row = args.drop_first_subword().convert_to_int();
	int col = args.drop_first_subword().convert_to_int();

	
	if (sys->get_movie_by_id(movieId)->get_haul()->get_chair_at(row, col) == 1) {
		std::cout << "The seat you are trying to buy ticket for is already taken!" << std::endl;
		return;
	}

	if (ses->get_user()->get_balance() < sys->get_movie_by_id(movieId)->get_price()) {	
		std::cout << "You don't have enough money to buy a ticket for this move=ie\n Your balance : " << ses->get_user()->get_balance()<<"\nMovie ticket price: "<<sys->get_movie_by_id(movieId)->get_price() << std::endl;
		return;
	}

	Ticket* ticket = new Ticket(sys->get_movie_by_id(movieId), row, col);
	ticket->get_movie()->get_haul()->take_chair_at(row, col);
	sys->get_user_by_id(ses->get_user()->get_id())->get_tickets().Push(ticket);
	sys->get_tickets().Push(ticket);
	ses->get_user()->set_balance(ses->get_user()->get_balance() - sys->get_movie_by_id(movieId)->get_price());
}
