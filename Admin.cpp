#include "Admin.h"
#include "System.h"

Admin::Admin(System* sys) 
{
	set_first_name("the");
	set_last_name("admin");
	set_id(0);
	set_balance(50);
	set_password("0000");
	this->sys = sys;
}

const char* Admin::get_role() const {
	return "admin";
}

/*
void Admin::add_movie(Movie* m)
{
	int movies_count = sys->get_movies().get_count();
	for (int i = 0; i < movies_count; i++) {
		if ((sys->movies[i]->get_haul()->get_id() == m->get_haul()->get_id()) // are in one haul
			&& are_dates_equal(sys->movies[i]->get_proj_date(), m->get_proj_date()) // are on one date
			&& do_hours_intersect(sys->movies[i]->get_proj_start(), sys->movies[i]->get_proj_end(), m->get_proj_start(), m->get_proj_end())) { // proj hours intersect
			std::cout << "Movie cannot be added, because the haul is occupated during these hours!" << std::endl;
			return;
		}
	}
	this->sys->get_movies().Push(m);
	std::cout << "Successfully added " << m->get_title() << " to Cinema movie offers!" << std::endl;
}
*/
