#include "../header/user.h"

std::string user::getName() const
{
	return name;
}

std::string user::getPassword() const
{
	return password;
}

void user::setPassword(std::string pw)
{
    password = pw;
}

void user::exportXml(QXmlStreamWriter& xmlOutput) const
{
    //*this polimorfo, getLabel chiamata superpolimorfa
    xmlOutput.writeStartElement(QString::fromStdString(getLabel()));

    xmlOutput.writeTextElement("nome", QString::fromStdString(name));
    xmlOutput.writeTextElement("password", QString::fromStdString(password));

    xmlOutput.writeEndElement();
}

bool user::operator == (const user& u) const
{
	return name == u.name && password == u.password;
}

bool user::operator != (const user& u) const
{
	return name != u.name || password != u.password;
}
