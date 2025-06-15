#pragma once
#include "Command.h"
class RemoveMovieCommand : public Command
{
public:
	void execute(System* sys, Session* ses, mystring& args) override;
	
};
void remove_ticket(int movie_id, int user_count, System* sys);
