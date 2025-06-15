#pragma once
#include "Movie.h"
class DramaMovie : public Movie
{
private:
	static double base_price;
	bool has_comedy_elements;
public:
	bool get_has_comedy_elements() const;
	void set_has_comedy_elements(const mystring& val);

	DramaMovie();
	DramaMovie(const mystring& tit, Vector<double> rat, int len, int rel_y,Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end, mystring& has_el);
	DramaMovie(const mystring& tit, int rel_y, int len, Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end, const mystring& com_el);

	void calculate_price() override;
	void print_movie() const override;
};

