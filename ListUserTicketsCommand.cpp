#include "ListUserTicketsCommand.h"

void ListUserTicketsCommand::execute(System* sys, Session* ses, mystring& args)
{
	int user_id = args.drop_first_subword().convert_to_int();
	int tickets_count;
	if (user_id == 0) {
		tickets_count = sys->get_admin()->get_tickets().get_count();
		for (int i = 0; i < tickets_count; i++) {
			sys->get_admin()->get_tickets()[i]->print_ticket();
		}
	}
	User* user = sys->get_user_by_id(user_id);
	tickets_count = user->get_tickets().get_count();
	for (int i = 0; i < tickets_count; i++) {
		user->get_tickets()[i]->print_ticket();
	}
	delete user;
}
