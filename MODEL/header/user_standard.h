#ifndef USER_STANDARD
#define USER_STANDARD

#include <string>
#include "user.h"

class user_standard: public user
{
public:
	user_standard(std::string n, std::string p) : user(n, p) {}
	virtual bool isAdmin() const;
	virtual bool canItemAdd() const;
	virtual bool canItemEdit() const;
    virtual bool canItemDelete() const;

	user_standard* clone() const;
	
	//copia, assegnazione standard
	//distruttore virtuale dal padre
private:
    virtual std::string getLabel() const;
};
#endif
