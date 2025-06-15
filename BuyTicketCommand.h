#pragma once
#include "Command.h"
class BuyTicketCommand : public Command
{
public:
	void execute(System* sys, Session* ses, mystring& args) override;
};

