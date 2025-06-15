#include "DramaMovie.h"

double DramaMovie::base_price = 7;

bool DramaMovie::get_has_comedy_elements() const
{
	return has_comedy_elements;
}

void DramaMovie::set_has_comedy_elements(const mystring& val)
{
	if (val == "yes")has_comedy_elements = true;
	else if (val == "no") has_comedy_elements = false;
	else std::cout << "You must answer the question Does the movie have comedy elements with yes or no.";
}

DramaMovie::DramaMovie() : Movie()
{
	this->set_genre("drama");
	has_comedy_elements = true;
	calculate_price();
}

DramaMovie::DramaMovie(const mystring& tit, Vector<double> rat, int len, int rel_y,Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end, mystring& has_el)
	: Movie(tit,rat,len,rel_y,h, pr_d,pr_st,pr_end)
{
	this->set_genre("drama");
	set_has_comedy_elements(has_el);
	calculate_price();
}

DramaMovie::DramaMovie(const mystring& tit, int rel_y, int len, Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end, const mystring& com_el)
	:Movie(tit, rel_y, len, h, pr_d, pr_st, pr_end)
{
	this->set_genre("drama");
	set_has_comedy_elements(com_el);
	calculate_price();
}

void DramaMovie::calculate_price()
{
	this->set_price(base_price + (has_comedy_elements ? 1 : 0) * 2);

}

void DramaMovie::print_movie() const
{
	Movie::print_movie();
	std::cout << ", genre: " << get_genre() << ", ticket price: " << get_price() << std::endl;
}
