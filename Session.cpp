#include "Session.h"
bool Session::is_logged_in() const
{
    return logged_in;
}

User* Session::get_user() const
{
    return current_user;

}

bool Session::login(System* system,mystring& fn, mystring& ln, const mystring& password)
{
    for (int i = 0; i < system->get_customers().get_count(); ++i) {
        if (system->get_customers()[i]->get_first_name() == fn &&
            system->get_customers()[i] ->get_last_name() == ln &&
            system->get_customers()[i]->get_password() == password) {
            current_user = system->get_customers()[i];
            std::cout << "Login successful!\n";
            std::cout << current_user->get_first_name() << " " << current_user->get_last_name() << " " << current_user->get_role() << std::endl;
            logged_in = true;
            return true;
        }
    }
    if (password == "0000") {
        current_user = system->get_admin();
        std::cout << "Login successful!\n";
        std::cout << fn << " " << ln << " " << password << std::endl;
        logged_in = true;
        return true;
    }
    std::cout << "Invalid credentials!\n";
    return false;
}

void Session::logout()
{
    if (logged_in) {
        std::cout << current_user->get_first_name() << " " << current_user->get_last_name() << " logged out.\n";
    }
    current_user = nullptr;
    logged_in = false;
}

bool Session::require_role(const char* role) const
{
    if (!logged_in) {
        std::cout << "Not logged in!" << std::endl;
        return false;
    }
    return strcmp(current_user->get_role(), role) == 0;
}