#include "ListTicketsCommand.h"

void ListTicketsCommand::execute(System* sys, Session* ses, mystring& args)
{
	size_t tickets_count = ses->get_user()->get_tickets().get_count();
	if (tickets_count == 0) {
		std::cout << "You don't have any tickets!" << std::endl;
		return;
	}
	for (size_t i = 0; i < tickets_count; i++) {
		ses->get_user()->get_tickets()[i]->print_ticket();
	}
}
