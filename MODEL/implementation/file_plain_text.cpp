#include "../header/file_plain_text.h"

file_base* file_plain_text::clone() const
{
    return new file_plain_text(*this);
}

std::string file_plain_text::getLabel() const
{
   return "PLAIN_TEXT";
}

file_base* file_plain_text::importXmlData(QXmlStreamReader& xmlInput)
{
    unsigned long long int size;
    std::string name, realExtension, link, creatorName, description;
    file_base::importMyXmlData(xmlInput, name, realExtension, link, size, creatorName, description);

    std::string author, title;
    file_text::importMyXmlData(xmlInput, author, title);

    return new file_plain_text(name, realExtension, link, size, creatorName, description, author, title);
}
