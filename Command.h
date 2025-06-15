#pragma once
#include "System.h"
#include "Session.h"
#include "mystring.h"
class Command
{
public:
	virtual void execute(System* sys, Session* session, mystring& args) = 0;
	virtual ~Command() = default;
};

