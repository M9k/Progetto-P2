#include "../header/user_admin.h"

bool user_admin::isAdmin() const
{
	return true;
}

bool user_admin::canItemAdd() const
{
	return true;
}

bool user_admin::canItemEdit() const
{
	return true;
}

bool user_admin::canItemDelete() const
{
    return true;
}

std::string user_admin::getLabel() const
{
   return "ADMIN";
}

user_admin* user_admin::clone() const
{
	return new user_admin(*this);
}
