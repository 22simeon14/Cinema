#include "ListUserHistoryCommand.h"

void ListUserHistoryCommand::execute(System* sys, Session* ses, mystring& args)
{
	int user_id = args.drop_first_subword().convert_to_int();
	int watched_movies_count;
	if (user_id == 0) {
		watched_movies_count = sys->get_admin()->get_watched_movies().get_count();
		for (int i = 0; i < watched_movies_count; i++) {
			sys->get_admin()->get_watched_movies()[i]->print_movie();
		}
	}
	User* user = sys->get_user_by_id(user_id);
	watched_movies_count = user->get_watched_movies().get_count();
	for (int i = 0; i < watched_movies_count; i++) {
		user->get_watched_movies()[i]->print_movie();
	}
	delete user;
}
