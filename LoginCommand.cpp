#include "LoginCommand.h"

void LoginCommand::execute(System* sys, Session* session, mystring& args)
{
	mystring fn = args.drop_first_subword();
	mystring ln = args.drop_first_subword();
	mystring password = args;
	session->login(sys, fn, ln, password);
}
