#include "CommandFactory.h"

Command* CommandFactory::createCommand(System* sys, Session* ses, mystring& args)
{
	mystring command_name = args.drop_first_subword();
	if (!ses->is_logged_in()) {
		if (command_name == "login") {// okay
			return new LoginCommand();
		}
		else if (command_name == "register") {  //okay
			return new RegisterCommand();
		}
		else {
			std::cout << "You must login first!" << std::endl;
			return nullptr;
		}
	}
	if (command_name == "logout") {//okay
		return new LogoutCommand();
	}

	if (command_name == "buy_ticket") return new BuyTicketCommand(); // okay
	if (command_name == "exit") return new ExitCommand();
	if (command_name == "list_history") return new ListHistoryCommand(); 
	if (command_name == "list_movies") return new ListMoviesCommand(); //okay
	if (command_name == "list_tickets") return new ListTicketsCommand(); // okay
	if (command_name == "rate_movie") return new RateMovieCommand(); 
	if (ses->require_role("admin")) {
		if (command_name == "add_movie") return new AddMovieCommand(); //okay
		if (command_name == "list_user_history") return new ListUserHistoryCommand(); 
		if (command_name == "list_user_tickets") return new ListUserTicketsCommand(); // okay
		if (command_name == "open_haul") return new OpenHaulCommand(); //okay
		if (command_name == "remove_movie") return new RemoveMovieCommand(); // okay
		if (command_name == "remove_user") return new RemoveUserCommand(); //okay
		if (command_name == "update_movie_haul") return new UpdateMovieHaulCommand(); //okay
		if (command_name == "update_movie_title") return new UpdateMovieTitleCommand(); //okay
	}
}
