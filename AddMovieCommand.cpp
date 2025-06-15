#include "AddMovieCommand.h"
#include "ActionMovie.h"
#include "DocumentaryMovie.h"
#include "DramaMovie.h"
void AddMovieCommand::execute(System* sys, Session* ses, mystring& args)
{

	mystring genre = args.drop_first_subword();
	mystring title = args.drop_first_subword();
	int release_year = args.drop_first_subword().convert_to_int();
	int length = args.drop_first_subword().convert_to_int();
	int haul_id = args.drop_first_subword().convert_to_int();
	int day = args.drop_first_subword().convert_to_int();
	int month = args.drop_first_subword().convert_to_int();
	int year = args.drop_first_subword().convert_to_int();
	Date proj_date{ day, month, year };
	int hour1 = args.drop_first_subword().convert_to_int();
	int minutes1 = args.drop_first_subword().convert_to_int();
	Hour proj_start{ hour1, minutes1 };
	int hour2 = args.drop_first_subword().convert_to_int();
	int minutes2 = args.drop_first_subword().convert_to_int();
	Hour proj_end{hour2, minutes2};
	Haul* haul = sys->get_haul_by_id(haul_id);
	Movie* movie;
	
	int movies_count = sys->get_movies().get_count();
	for (int i = 0; i < movies_count; i++) {
		if ((sys->get_movies()[i]->get_haul()->get_id() == haul->get_id()) // are in one haul
			&& are_dates_equal(sys->get_movies()[i]->get_proj_date(), proj_date) // are on one date
			&& do_hours_intersect(sys->get_movies()[i]->get_proj_start(), sys->get_movies()[i]->get_proj_end(), proj_start, proj_end)) { // proj hours intersect
			std::cout << "Movie cannot be added, because the haul is occupated during these hours!" << std::endl;
			return;
		}
	}


	if (genre == "action" ) {
		//action intensity                                          Movie(const mystring& tit, int rel_y, int len, Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end);
		int intensity = args.drop_first_subword().convert_to_int();
		movie = new ActionMovie(title,release_year, length, haul, proj_date, proj_start,proj_end, intensity);
	}
	else if (genre == "documentary") {
		//theme isbasedontrueevents
		mystring theme = args.drop_first_subword();
		mystring is_based = args.drop_first_subword();
		movie = new DocumentaryMovie(title, release_year, length, haul, proj_date, proj_start, proj_end, theme, is_based);
	}
	else if (genre == "drama") {
		// has comedy elements
		mystring has_el = args.drop_first_subword();
		movie = new DramaMovie(title, release_year, length, haul, proj_date, proj_start, proj_end, has_el);
	}
	else {
		std::cout << "Invalid genre" << std::endl;
		return;
	}

	
	sys->get_movies().Push(movie);
	std::cout << "Successfully added " << movie->get_title() << " to Cinema movie offers!" << "  ID: " << movie->get_id()<< std::endl;

}
