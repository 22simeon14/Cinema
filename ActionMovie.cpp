#include "ActionMovie.h"

double ActionMovie::base_price = 9;

int ActionMovie::get_action_intensity() const
{
    return action_intensity;
}

void ActionMovie::set_action_intensity(int ac_inten)
{
    if (ac_inten < 0 || ac_inten > 20) {
        std::cout << "Action scenes intensity must be 0-20. Setting default value (0)..." << std::endl;
        this->action_intensity = 0;
        return;
    }
    this->action_intensity = ac_inten;
}

ActionMovie::ActionMovie() :Movie(), action_intensity(1)
{
    this->set_genre("action");
    calculate_price();
}

ActionMovie::ActionMovie(const mystring& tit,Vector<double> rat,int len, int rel_y,Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end, int intens)
    :Movie(tit, rat, len, rel_y,h, pr_d, pr_st, pr_end)
{
    this->set_genre("action");
    set_action_intensity(intens);
    calculate_price();
}

ActionMovie::ActionMovie(const mystring& tit, int rel_y, int len, Haul* h, const Date pr_d, const Hour pr_st, const Hour pr_end, int act_int)
    :Movie(tit,rel_y, len, h,pr_d, pr_st, pr_end)
{
    this->set_genre("action");
    set_action_intensity(act_int);
    calculate_price();
}

void ActionMovie::calculate_price()
{
    this->set_price(base_price + action_intensity * 1.5);
}

void ActionMovie::print_movie() const
{
    Movie::print_movie();
    std::cout << ", genre: " << get_genre() << ", ticket price: " << get_price() << std::endl;
}
