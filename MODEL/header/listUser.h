#ifndef LISTUSER
#define LISTUSER

#include <list>

#include "user.h"
#include "common_functions.h"
#include "user_admin.h"
#include "user_moderator.h"
#include "user_editor.h"
#include "user_standard.h"

#include <QFile>
#include <QXmlStreamWriter>
#include <QString>

#include "mylist.h"

template class mylist<std::list<user*>,user*>;

class listUser : public mylist<std::list<user*>,user*>
{
private:
    static QString startLabel;
    static QString defaultFile;
    QString getStartLabelXml() const;
    QString getDefaultFile() const;
public:
    listUser(): mylist() {}
    bool addEnd(user* u);

    user* search(std::string nome) const;
    bool search(const user*) const;
    static bool checkPassword(const user* u, std::string pw);
    void changePassword(user*, std::string);

    bool importXml();

    void defaultData();
};
#endif
