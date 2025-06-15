#pragma once
#include "User.h"
#include "System.h"
class Session 
{
private:
	User* current_user;
	bool logged_in;
public:
	Session() : current_user(nullptr), logged_in(false) {};

	bool is_logged_in() const;

	User* get_user() const;

	bool login(System* system,mystring& fn,mystring& ln, const mystring& password);


	void logout();

	bool require_role(const char* role) const;
};

