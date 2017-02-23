#ifndef USER_EDITOR
#define USER_EDITOR

#include <string>
#include "user.h"

class user_editor: public user
{
public:
	user_editor(std::string n, std::string p) : user(n, p) {}
	virtual bool isAdmin() const;
	virtual bool canItemAdd() const;
	virtual bool canItemEdit() const;
    virtual bool canItemDelete() const;
	
	user_editor* clone() const;

private:
    virtual std::string getLabel() const;
	
	//copia, assegnazione standard
	//distruttore virtuale dal padre
};
#endif
