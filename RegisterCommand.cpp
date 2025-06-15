#include "RegisterCommand.h"

void RegisterCommand::execute(System* sys, Session* session, mystring& args)
{
	mystring fn = args.drop_first_subword();
	mystring ln = args.drop_first_subword();
	mystring password = args.drop_first_subword();

	Customer* customer = new Customer(fn, ln, password,50);
	sys->get_customers().Push(customer);
	std::cout << "You susccessfully registered in our system!" << std::endl;
}
