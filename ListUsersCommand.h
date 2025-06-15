#pragma once
#include "Command.h"
class ListUsersCommand : public Command
{
public:
	void execute(System* sys, Session* ses, mystring& args) override;

};

