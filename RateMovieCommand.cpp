#include "RateMovieCommand.h"

void RateMovieCommand::execute(System* sys, Session* ses, mystring& args)
{
	int movie_id = args.drop_first_subword().convert_to_int();
	int rating = args.convert_to_int();
	bool flag = true;

	size_t watched_movies_count = ses->get_user()->get_watched_movies().get_count();
	for (size_t i = 0; i < watched_movies_count; i++) {
		if (ses->get_user()->get_watched_movies()[i]->get_id() == movie_id) {
			ses->get_user()->get_watched_movies()[i]->add_rating(rating);
			flag = false;
			break;
		}
	}
	if (flag)std::cout << "The movie hasn't been watched." << std::endl;
}
