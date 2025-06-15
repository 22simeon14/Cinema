#include "DocumentaryMovie.h"

double DocumentaryMovie::base_price = 5;

const Theme DocumentaryMovie::get_theme() const
{
	return theme;
}

const mystring DocumentaryMovie::get_theme_as_string() const
{
	switch (theme) {
	case Theme::Nature: return "nature";
	case Theme::History: return "history";
	case Theme::HistoricalFigure: return "historical_figure";
	default: return "Unknown";
	}
}

void DocumentaryMovie::set_theme(const mystring& val)
{
	if (val == "nature") {
		this->theme = Theme::Nature;
	}
	else if (val == "history") {
		this->theme = Theme::History;
	}
	else if (val == "historical_figure") {
		this->theme = Theme::HistoricalFigure;
	}
	else throw std::invalid_argument("Invalid theme value! Must be nature, history or historical_figure!");
}

void DocumentaryMovie::set_is_based_on_true_events(const mystring& val)
{
	if (val == "yes")is_based_on_true_events = true;
	else if (val == "no") is_based_on_true_events = false;
	else std::cout << "You must answer the question Is the movie based on true events with yes or no.";
}

void DocumentaryMovie::calculate_price()
{
	this->set_price(base_price + (is_based_on_true_events ? 1 : 0) * 3);
}

void DocumentaryMovie::print_movie() const
{
	Movie::print_movie();
	std::cout << ", genre: " << get_genre() << ", theme: " << get_theme_as_string() << ", ticket price: " << get_price() << std::endl;
}

DocumentaryMovie::DocumentaryMovie() : Movie()
{
	is_based_on_true_events = true;
	this->set_genre("documentary");
	theme = Theme::Nature;
	calculate_price();
}

DocumentaryMovie::DocumentaryMovie(const mystring& tit, Vector<double> rat, int len, int rel_y, Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end, const mystring& th, const mystring& based)
	:Movie(tit, rat, len, rel_y, h, pr_d, pr_st, pr_end)
{
	this->set_genre("documentary");
	set_theme(th);
	set_is_based_on_true_events(based);
	calculate_price();
}

DocumentaryMovie::DocumentaryMovie(const mystring& tit, int rel_y, int len, Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end, const mystring& th, const mystring& based)
	: Movie(tit, rel_y, len, h, pr_d, pr_st, pr_end)
{
	this->set_genre("documentary");
	set_theme(th);
	set_is_based_on_true_events(based);
	calculate_price();
}


