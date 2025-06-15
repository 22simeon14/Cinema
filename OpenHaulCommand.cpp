#include "OpenHaulCommand.h"

void OpenHaulCommand::execute(System* sys, Session* ses, mystring& args)
{
	int rows = args.drop_first_subword().convert_to_int();
	int cols = args.drop_first_subword().convert_to_int();

	Haul* h = new Haul(rows, cols);
	sys->get_hauls().Push(h);
	std::cout << "Successfully opened a new haul with id " << h->get_id() << std::endl;
}