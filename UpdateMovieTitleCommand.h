#pragma once
#include "Command.h"
class UpdateMovieTitleCommand : public Command
{
public:
	void execute(System* sys, Session* ses, mystring& args) override;
};

