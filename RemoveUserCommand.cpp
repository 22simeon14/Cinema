#include "RemoveUserCommand.h"

void RemoveUserCommand::execute(System* sys, Session* ses, mystring& args)
{
	int user_id = args.drop_first_subword().convert_to_int();
	if (user_id == 0) {
		std::cout << "Cannot remove admin" << std::endl;
	}
	if (!sys->get_user_by_id(user_id)) {
		std::cout << "No user with id " << user_id << std::endl;
		return;
	}
	sys->get_customers().remove_by_id(user_id);
	std::cout << "User with id " << user_id << " removed succesfully" << std::endl;
}
