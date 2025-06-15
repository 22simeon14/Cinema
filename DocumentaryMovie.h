#pragma once
#include "Movie.h"
class DocumentaryMovie :public Movie
{
private:
	static double base_price;
 	Theme theme; 
	bool is_based_on_true_events;
public:
	const Theme get_theme() const;
	const mystring get_theme_as_string() const;

	void set_theme(const mystring& val);
	void set_is_based_on_true_events(const mystring& val);
	DocumentaryMovie();
	DocumentaryMovie(const mystring& tit, Vector<double> rat, int len, int rel_y, Haul* h,const Date pr_d, const Hour pr_st, const Hour pr_end, const mystring& th, const mystring& based);
	DocumentaryMovie(const mystring& tit, int rel_y, int len, Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end, const mystring& th, const mystring& based);
	void calculate_price() override;
	void print_movie() const override;
};

