#include "UpdateMovieTitleCommand.h"

void UpdateMovieTitleCommand::execute(System* sys, Session* ses, mystring& args)
{
	int movie_id = args.drop_first_subword().convert_to_int();
	mystring new_title = args.drop_first_subword();
	sys->get_movie_by_id(movie_id)->set_title(new_title);

	/*int customers_count = sys->get_customers().get_count();
	int watched_movies;
	for (int i = 0; i < customers_count; i++) {
		if (sys->get_customers()[i]->has_watched_movie(movie_id)) {
			sys->get_customers()[i]->get_watched_movies()->
		}
	}*/
}
