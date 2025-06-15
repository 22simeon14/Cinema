#pragma once
#include "Command.h"
class UpdateMovieHaulCommand : public Command
{
public:
	void execute(System* sys, Session* ses, mystring& args)override;
};

