#include "../header/user_standard.h"

bool user_standard::isAdmin() const
{
	return false;
}

bool user_standard::canItemAdd() const
{
	return false;
}

bool user_standard::canItemEdit() const
{
	return false;
}

bool user_standard::canItemDelete() const
{
    return false;
}

std::string user_standard::getLabel() const
{
    return "STANDARD";
}

user_standard* user_standard::clone() const
{
	return new user_standard(*this);
}
