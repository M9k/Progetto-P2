#include "../header/listUser.h"

QString listUser::startLabel = "UTENTI";
QString listUser::defaultFile = "userdata.xml";

QString listUser::getStartLabelXml() const
{
    return startLabel;
}
QString listUser::getDefaultFile() const
{
    return defaultFile;
}

bool listUser::addEnd(user* us)
{
    if(us)
        if(!search(us->getName()))
        {
            list.push_back(us->clone());
            return true;
        }
    return false;
}

user* listUser::search(std::string nome) const
{
    for(std::list<user*>::const_iterator ci = list.begin(); ci != list.end(); ++ci)
		if(nome == (*ci)->getName())
			return *ci;
	return 0;
}

bool listUser::search(const user* u) const
{
    if(u == 0)
        return false;
    for(std::list<user*>::const_iterator ci = list.begin(); ci != list.end(); ++ci)
		if(*u == **ci)
			return true;
	return false;
}

bool listUser::checkPassword(const user* u, std::string pw)
{
    if(!u)
        return 0;
	return u->getPassword() == pw;
}

void listUser::changePassword(user* edit, std::string new_pass)
{
    edit->setPassword(new_pass);
}

bool listUser::importXml()
{
    clean();
    bool c = false;

    QFile file(getDefaultFile());
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QXmlStreamReader xmlInput(&file);

        while(xmlInput.readNextStartElement()) {
            if(xmlInput.name() == getStartLabelXml()){
                while(xmlInput.readNextStartElement())
                {
                    //legge il nome della classe
                    std::string classname = (xmlInput.name().toString()).toStdString();

                    std::string name, pass;
                    try
                    {
                        importTagXml(xmlInput, "nome", name);
                        importTagXml(xmlInput, "password", pass);
                        user* u = 0;
                        if (classname == "ADMIN")
                            u = new user_admin(name, pass);
                        if (classname == "EDITOR")
                            u = new user_editor(name, pass);
                        if (classname == "MODERATOR")
                            u = new user_moderator(name, pass);
                        if (classname == "STANDARD")
                            u = new user_standard(name, pass);

                        if(u)
                        {
                            addEnd(u);
                            delete u;
                            c = true;
                        }
                        //porta il puntatore all'elemento successivo
                        xmlInput.skipCurrentElement();
                    }
                    catch(unexpected_tag e)
                    {
                        //salta al prossimo elemento
                        while (!xmlInput.isEndElement() || xmlInput.name() != QString::fromStdString(classname))
                            xmlInput.readNext();
                    }
               }
            }
        }
    }
    file.close();
    return c;
}

void listUser::defaultData()
{
    clean();
    user_admin u("admin","admin");
    addEnd(&u);
}
