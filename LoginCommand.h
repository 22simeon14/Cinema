#pragma once

#include "Command.h"
class LoginCommand : public Command
{
public:
	void execute(System* sys, Session* session, mystring& args) override;
};

