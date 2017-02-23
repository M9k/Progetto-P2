#include "../../MODEL/header/common_functions.h"

void importTagXml(QXmlStreamReader& xmlInput, const std::string name, std::string& value)
{
    xmlInput.readNextStartElement();
    if (xmlInput.name() != QString::fromStdString(name))
        throw unexpected_tag();

    value = (xmlInput.readElementText()).toStdString();
}
