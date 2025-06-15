#pragma once
#include "User.h"
class Customer : public User
{
public:
	
	const char* get_role() const override;
	
	Customer();
	Customer(const mystring& fn, const mystring& ln, const mystring& pass, double b);
	
};

