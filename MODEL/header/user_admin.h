#ifndef USER_ADMIN
#define USER_ADMIN

#include <string>
#include "user.h"
class user_admin: public user
{
public:
	user_admin(std::string n, std::string p) : user(n, p) {}
	virtual bool isAdmin() const;
	virtual bool canItemAdd() const;
	virtual bool canItemEdit() const;
    virtual bool canItemDelete() const;

    user_admin* clone() const;

private:
    virtual std::string getLabel() const;

	//copia, assegnazione standard
	//distruttore virtuale dal padre
};
#endif
