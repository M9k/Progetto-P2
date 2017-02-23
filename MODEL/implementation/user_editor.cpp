#include "../header/user_editor.h"

bool user_editor::isAdmin() const
{
	return false;
}

bool user_editor::canItemAdd() const
{
	return true;
}

bool user_editor::canItemEdit() const
{
	return false;
}

bool user_editor::canItemDelete() const
{
    return false;
}

std::string user_editor::getLabel() const
{
   return "EDITOR";
}

user_editor* user_editor::clone() const
{
	return new user_editor(*this);
}
