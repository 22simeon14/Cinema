#include "UpdateMovieHaulCommand.h"

void UpdateMovieHaulCommand::execute(System* sys, Session* ses, mystring& args)
{
	int movie_id = args.drop_first_subword().convert_to_int();
	if (sys->get_movie_by_id(movie_id)->has_been_projected()) return;
	int new_haul_id = args.drop_first_subword().convert_to_int();
	if (!sys->get_haul_by_id(new_haul_id)) {
		std::cout << "No haul with id " << new_haul_id << std::endl;
		return;
	}
	Movie* m = sys->get_movie_by_id(movie_id);
	int movies_count = sys->get_movies().get_count();
	bool flag = true;
	for (int i = 0; i < movies_count; i++) {
		if (sys->get_movies()[i]->get_haul()->get_id() == new_haul_id
			&& are_dates_equal(m->get_proj_date(), sys->get_movies()[i]->get_proj_date())
			&& do_hours_intersect(m->get_proj_start(), m->get_proj_end(), sys->get_movies()[i]->get_proj_start(), sys->get_movies()[i]->get_proj_end())) {
			flag = false;
			std::cout << "Haul is not free on this date and hours!" << std::endl;
			break;
		}
	}
	if (flag) {
		sys->get_movie_by_id(movie_id)->set_haul(sys->get_haul_by_id(new_haul_id));
	}
}
