#include "../header/user_moderator.h"

bool user_moderator::isAdmin() const
{
	return false;
}

bool user_moderator::canItemAdd() const
{
	return true;
}

bool user_moderator::canItemEdit() const
{
	return true;
}

bool user_moderator::canItemDelete() const
{
    return true;
}

std::string user_moderator::getLabel() const
{
    return "MODERATOR";
}

user_moderator* user_moderator::clone() const
{
	return new user_moderator(*this);
}

