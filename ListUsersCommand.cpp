#include "ListUsersCommand.h"

void ListUsersCommand::execute(System* sys, Session* ses, mystring& args)
{
	sys->get_admin()->print_user();
	int user_count = sys->get_customers().get_count();
	for (int i = 0; i < user_count; i++) {
		sys->get_customers()[i]->print_user();
	}
	
}
