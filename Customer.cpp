#include "Customer.h"

const char* Customer::get_role() const
{
	return "customer";
}


Customer::Customer() : User()
{
}

Customer::Customer(const mystring& fn, const mystring& ln, const mystring& pass, double b):User(fn,ln,pass,b)
{
}


