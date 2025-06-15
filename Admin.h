#pragma once
#include "User.h"

class System;

class Admin : public User
{
private:
	System* sys;
public:
	
	const char* get_role() const override;
	Admin(System* sys);
};

