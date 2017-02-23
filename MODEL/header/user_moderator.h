#ifndef USER_MODERATOR
#define USER_MODERATOR

#include <string>
#include "user.h"

class user_moderator: public user
{
public:
	user_moderator(std::string n, std::string p) : user(n, p) {}
	virtual bool isAdmin() const;
	virtual bool canItemAdd() const;
	virtual bool canItemEdit() const;
	virtual bool canItemDelete() const;

	user_moderator* clone() const;

private:
    virtual std::string getLabel() const;
	
	//copia, assegnazione standard
	//distruttore virtuale dal padre
};
#endif
