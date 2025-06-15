#pragma once
#include "Command.h"
class ExitCommand : public Command
{
public:
	void execute(System* sys, Session* ses, mystring& args) override;
};

