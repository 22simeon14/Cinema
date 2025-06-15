#pragma once
//admin commands
#include "AddMovieCommand.h" 
#include "ListUserHistoryCommand.h" 
#include "ListUsersCommand.h" 
#include "ListUserTicketsCommand.h" 
#include "OpenHaulCommand.h" 
#include "RemoveMovieCommand.h" 
#include "RemoveUserCommand.h" 
#include "UpdateMovieHaulCommand.h" 
#include "UpdateMovieTitleCommand.h" 
//mutual commands
#include "BuyTicketCommand.h"
#include "ExitCommand.h"
#include "ListHistoryCommand.h"
#include "ListMoviesCommand.h"
#include "ListTicketsCommand.h"
#include "LoginCommand.h"
#include "LogoutCommand.h"
#include "RateMovieCommand.h"
#include "RegisterCommand.h"

class CommandFactory
{
public:
	static Command* createCommand(System* sys, Session* ses, mystring& args);
};

