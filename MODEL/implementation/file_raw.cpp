#include "../header/file_raw.h"

file_base* file_raw::clone() const
{
	return new file_raw(*this);
}

const color_file file_raw::getColor() const
{
    return color_file(r,g,b);
}

std::string file_raw::getLabel() const
{
    return "RAW";
}

void file_raw::exportMyXmlData(QXmlStreamWriter& xmlOutput) const
{
    file_base::exportMyXmlData(xmlOutput);
}

file_base* file_raw::importXmlData(QXmlStreamReader& xmlInput)
{
    unsigned long long int size;
    std::string name, realExtension, link, creatorName, description;
    file_base::importMyXmlData(xmlInput, name, realExtension, link, size, creatorName, description);
    return new file_raw(name, realExtension, link, size, creatorName, description);
}
