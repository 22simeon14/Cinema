#pragma once
#include "Command.h"
class ListMoviesCommand : public Command
{
public:
	void execute(System* sys, Session* ses, mystring& args) override;
};

