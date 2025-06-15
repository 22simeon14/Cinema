#pragma once
#include "Command.h"
class RegisterCommand : public Command
{
public:
	void execute(System* sys, Session* session, mystring& args) override;
};

