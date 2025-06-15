#include "ListHistoryCommand.h"

void ListHistoryCommand::execute(System* sys, Session* ses, mystring& args)
{
	size_t count = ses->get_user()->get_watched_movies().get_count();
	if (count == 0) {
		std::cout << "You haven't watched any movies ;( " << std::endl;
		return;
	}
	for (size_t i = 0; i < count; i++) {
		std::cout << "Movie name: " << ses->get_user()->get_watched_movies()[i]->get_title() << std::endl;;
	}
}

