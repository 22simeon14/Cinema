#pragma once
#include "Command.h"
class LogoutCommand : public Command
{
public:
	void execute(System* sys, Session* ses, mystring& args) override;
};

