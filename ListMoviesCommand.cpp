#include "ListMoviesCommand.h"

void ListMoviesCommand::execute(System* sys, Session* ses, mystring& args)
{
	size_t movie_count = sys->get_movies().get_count();
	bool flag = true;
	for (size_t i = 0; i < movie_count; i++) {
		if (!sys->get_movies()[i]->has_been_projected()) {
			sys->get_movies()[i]->print_movie();
			flag = false;
		}
	}
	if (flag)std::cout << "No upcoming movies!" << std::endl;
}
