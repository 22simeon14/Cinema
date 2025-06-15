#pragma once
#include "Command.h"
class ListUserHistoryCommand : public Command
{
public:
	void execute(System* sys, Session* ses, mystring& args) override;
};

