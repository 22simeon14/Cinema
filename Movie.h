#pragma once
#include "mystring.h"
#include "Haul.h"
#include "Utility.h"
#include "Vector.h"
class Movie
{
private:
	static int next_id;
	int id;
	mystring title;
	Vector<double> ratings;
	int length;
	int release_year;
	mystring genre;
	Haul* haul;
	Date proj_date;
	Hour proj_start;
	Hour proj_end;
	double price;
public:
	int get_id() const;
	const mystring get_title() const;
	Vector<double> get_ratings() const; 
	int get_length() const;
	int get_release_year() const;
	const mystring get_genre() const;
	Haul* get_haul() ;
	int get_haul_id();
	const Date get_proj_date() const;
	const Hour get_proj_start() const;
	const Hour get_proj_end() const;
	double get_price() const;

	void set_title(const mystring val);
	void set_ratings(Vector<double> val);
	void set_length(int val);
	void set_release_year(int val);
	void set_genre(const mystring g);
	void set_haul(Haul* h);
	void set_proj_date(const Date val);
	void set_proj_start(const Hour val);
	void set_proj_end(const Hour val);
	void set_price(double val);
	void add_rating(int rating);

	Movie();
	Movie(const mystring& tit, Vector<double> rat, int len, int rel_y, Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end);
	Movie(const mystring& tit, int rel_y, int len, Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end);
	virtual ~Movie() = default;

	virtual void calculate_price() = 0;
	virtual void print_movie() const;

	//helper functions
	bool has_been_projected()const;
};

