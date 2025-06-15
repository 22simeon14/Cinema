#include "Movie.h"

int Movie::next_id = 300;

int Movie::get_id() const {
	return id;
}

const mystring Movie::get_title() const
{
	return title;
}

Vector<double> Movie::get_ratings() const
{
	return ratings;
}

int Movie::get_length() const
{
	return length;
}

int Movie::get_release_year() const
{
	return release_year;
}

const mystring Movie::get_genre() const
{
	return genre;
}

Haul* Movie::get_haul() 
{
	return haul;
}

int Movie::get_haul_id()
{
	return haul->get_id();
}

const Date Movie::get_proj_date() const
{
	return proj_date;
}

const Hour Movie::get_proj_start() const
{
	return proj_start;
}

const Hour Movie::get_proj_end() const
{
	return proj_end;
}

double Movie::get_price() const
{
	return price;
}

void Movie::set_title(const mystring val)
{
	if (val == nullptr) {
		std::cout << "The movie title was null pointer! Setting default title (\"\") ..." << std::endl;
		this->title = "";
		return;
	}
	this->title = val;
}

void Movie::set_ratings(Vector<double> val)
{
	
	this->ratings = val;
}

void Movie::set_length(int val)
{
	if (val < 0 || val>300) {
		std::cout << "Invalid movie length! Setting default value (120) ..." << std::endl;
		this->length = 120;
		return;
	}
	this->length = val;
}

void Movie::set_release_year(int val)
{
	if (val < 1900 || val > 2025) {
		std::cout << "Movie release date is out of bounds! Setting default value (1999)..." << std::endl;
		this->release_year = 1999;
		return;
	}
	this->release_year = val;
}

void Movie::set_genre(const mystring g)
{
	if (g == nullptr) {
		std::cout << "Movie genre was nullptr! Setting default value (\"\") ..." << std::endl;
		this->genre = "";
		return;
	}
	this->genre = g;
}

void Movie::set_haul(Haul* r)
{
	if (r == nullptr) {
		std::cout << "Cannot set movie Haul to nullptr!"<<std::endl;
		return;
	}
	haul = r;
}

void Movie::set_proj_date(const Date val)
{
	if (val.day < 1 || val.day > 31 || val.month < 1 || val.month>12 || val.year < 2020) {
		std::cout << "Invalid projection date! Setting default one (17.5.2025) ..." << std::endl;
		Date d{ 17,5,2025 };
		this->proj_date = d;
		return;
	}
	this->proj_date = val;
}

void Movie::set_proj_start(const Hour val)
{
	if (val.hour < 0 || val.hour > 24 || val.minutes < 0 || val.minutes > 59) {
		std::cout << "Invalid projection start hour! Setting default one (23.59) ..." << std::endl;
		Hour h{ 23,59 };
		this->proj_start = h;
		return;
	}
	this->proj_start = val;
}

void Movie::set_proj_end(const Hour val)
{
	if (val.hour < 0 || val.hour > 24 || val.minutes < 0 || val.minutes > 59) {
		std::cout << "Invalid projection end hour! Setting default one (23.59) ..." << std::endl;
		Hour h{ 23,59 };
		this->proj_end = h;
		return;
	}
	this->proj_end = val;
}

void Movie::set_price(double val)
{
	if (val < 0) {
		std::cout << "Movie ticket price must be >=0 ! Setting default price (10)..." << std::endl;
		this->price = 10;
		return;
	}
	this->price = val;
}

void Movie::add_rating(int rating)
{
	if (rating < 0 || rating>10) {
		std::cout << "Invalid rating, setting default value of 5" << std::endl;
		rating = 5;
	}
	ratings.Push(rating);
}

Movie::Movie() :id(0), title(nullptr),length(0), release_year(1900), genre(nullptr),haul(nullptr), proj_date({ 1,1,1900 }), proj_start({ 0,0 }), proj_end({ 23,59 }), price(0), ratings()
{

}

Movie::Movie(const mystring& tit, Vector<double> ratings, int len, int rel_y, Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end)
{
	id = ++next_id;
	genre = nullptr;
	set_title(tit);
	set_ratings(ratings);
	set_length(len);
	set_release_year(rel_y);
	set_haul(h);
	set_proj_date(pr_d);
	set_proj_start(pr_st);
	set_proj_end(pr_end);
}

Movie::Movie(const mystring& tit, int rel_y, int len, Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end)
{
	id = ++next_id;
	set_title(tit);
	set_release_year(rel_y);
	set_length(len);
	set_haul(h);
	set_proj_date(pr_d);
	set_proj_start(pr_st);
	set_proj_end(pr_end);
}

bool Movie::has_been_projected() const
{
	std::time_t now = std::time(nullptr);
	std::tm* current_tm = std::localtime(&now);

	std::tm movie_tm = {};
	movie_tm.tm_year = get_proj_date().year - 1900;       // tm_year is years since 1900
	movie_tm.tm_mon = get_proj_date().month - 1;         // tm_mon is 0-based (0 = Jan)
	movie_tm.tm_mday =get_proj_date().day;
	movie_tm.tm_hour = get_proj_start().hour;
	movie_tm.tm_min = get_proj_start().minutes;
	movie_tm.tm_sec = 0;

	std::time_t movie_time = std::mktime(&movie_tm);

	if (movie_time == -1) return false;

	return std::difftime(now, movie_time) > 0;
	
}

void Movie::print_movie() const
{
	std::cout << "Title: " << title << ", id: " << id << ", ratings: ";
	for (size_t i = 0; i < ratings.get_count(); i++) {
		std::cout << ratings[i];
		if (i != ratings.get_count() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << ", length: " << length
		<< ", release year: " << release_year;
}
