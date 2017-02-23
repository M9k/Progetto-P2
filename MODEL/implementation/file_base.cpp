#include "../header/file_base.h"

const std::string& file_base::getName() const
{
	return name;
}

const std::string& file_base::getRealExtension() const
{
	return realExtension;
}

const std::string& file_base::getLink() const
{
	return link;
}

const size_of_file& file_base::getSize() const
{
	return size;
}

const std::string& file_base::getCreatorName() const
{
	return creatorName;
}

const std::string& file_base::getDescription() const
{
    return description;
}

std::string file_base::getLabel() const
{
    return "FILE";
}

void file_base::exportXml(QXmlStreamWriter& xmlOutput) const
{
    xmlOutput.writeStartElement(QString::fromStdString(getLabel()));
    exportMyXmlData(xmlOutput);
    xmlOutput.writeEndElement();
}

void file_base::exportMyXmlData(QXmlStreamWriter& xmlOutput) const
{
    xmlOutput.writeTextElement("name", QString::fromStdString(getName()));
    xmlOutput.writeTextElement("realExtension", QString::fromStdString(getRealExtension()));
    xmlOutput.writeTextElement("link", QString::fromStdString(getLink()));
    xmlOutput.writeTextElement("size", QString::number(getSize()));
    xmlOutput.writeTextElement("creatorName", QString::fromStdString(getCreatorName()));
    xmlOutput.writeTextElement("description", QString::fromStdString(getDescription()));
}

std::string file_base::getInfo() const
{
    std::string rit = "Tipo " + getLabel() + "\nNome: " + getName() + '.' + getRealExtension() +
            "\nDimensione: " + std::to_string(getSize().getMByte()) + "Mb\nLink: " + getLink() +
            "\nUtente: " + getCreatorName();
    getDescription()!="" ? rit += "\nDescrizione: " + getDescription() : rit += "\nDescrizione non disponibile" ;
    return rit;
}

void file_base::setName(std::string newName)
{
    name = newName;
}

void file_base::setRealExtension(std::string newRealExtension)
{
    realExtension = newRealExtension;
}

void file_base::setLink(std::string newLink)
{
    link = newLink;
}

void file_base::setSize(size_of_file newSize)
{
    size = newSize;
}

void file_base::setDescription(std::string newDesc)
{
    description = newDesc;
}
void file_base::importMyXmlData(QXmlStreamReader &xmlInput, std::string& name, std::string& realExtension, std::string& link, unsigned long long int& size, std::string& creatorName, std::string& description)
{
    std::string stringsize;
    importTagXml(xmlInput, "name", name);
    importTagXml(xmlInput, "realExtension", realExtension);
    importTagXml(xmlInput, "link", link);
    importTagXml(xmlInput, "size", stringsize);
    size = stoull(stringsize);
    importTagXml(xmlInput, "creatorName", creatorName);
    importTagXml(xmlInput, "description", description);
}
