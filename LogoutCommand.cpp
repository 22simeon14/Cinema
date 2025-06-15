#include "LogoutCommand.h"

void LogoutCommand::execute(System* sys, Session* ses, mystring& args)
{
	ses->logout();
}
