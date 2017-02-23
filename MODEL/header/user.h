#ifndef USER
#define USER

#include <QXmlStreamWriter>
#include <string>

class user
{
private:
	std::string name;
	std::string password;
    virtual std::string getLabel() const = 0;
	
public:
	user(std::string n, std::string pw) : name(n), password(pw) {}
	
    std::string getName() const;
    std::string getPassword() const;
    void setPassword(std::string);
    virtual bool isAdmin() const = 0;
	virtual bool canItemAdd() const = 0;
    virtual bool canItemEdit() const = 0;
    virtual bool canItemDelete() const = 0;
    void exportXml(QXmlStreamWriter&) const;

	virtual user* clone() const = 0;
    virtual ~user() {}
	bool operator == (const user&) const;
	bool operator != (const user&) const;
};
#endif
