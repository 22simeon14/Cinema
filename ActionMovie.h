#pragma once
#include "Movie.h"
class ActionMovie : public Movie
{
private:
	static double base_price;
	int action_intensity;
public:
	int get_action_intensity() const;
	void set_action_intensity(int ac_inten);

	ActionMovie();
	ActionMovie(const mystring& tit, Vector<double> rat,int len, int rel_y,Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end, int intens);
	ActionMovie(const mystring& tit, int rel_y, int len, Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end, int act_int);
	void calculate_price() override;
	void print_movie() const override;
};

