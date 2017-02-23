#include "../header/file_epub.h"

file_base* file_epub::clone() const
{
    return new file_epub(*this);
}

int file_epub::getPicsNumber() const
{
    return picsNumber;
}

void file_epub::setPicsNumber(int newPicsNumber)
{
    picsNumber = newPicsNumber;
}

std::string file_epub::getInfo() const
{
    std::string rit = file_text::getInfo();
    getPicsNumber()!=-1 ? rit+= "\nNumero di immagini: " + std::to_string(getPicsNumber()): rit+="\nNumero di immagini non specificato";
    return rit;
}

std::string file_epub::getLabel() const
{
   return "EPUB";
}

void file_epub::exportMyXmlData(QXmlStreamWriter& xmlOutput) const
{
    file_text::exportMyXmlData(xmlOutput);
    xmlOutput.writeTextElement("picsNumber", QString::number(getPicsNumber()));
}

void file_epub::importMyXmlData(QXmlStreamReader &xmlInput, std::string& picsNumber)
{
    importTagXml(xmlInput, "picsNumber", picsNumber);
}

file_base* file_epub::importXmlData(QXmlStreamReader& xmlInput)
{
    unsigned long long int size;
    std::string name, realExtension, link, creatorName, description;
    file_base::importMyXmlData(xmlInput, name, realExtension, link, size, creatorName, description);

    std::string author, title;
    file_text::importMyXmlData(xmlInput, author, title);

    std::string picsNumber;
    file_epub::importMyXmlData(xmlInput, picsNumber);

    return new file_epub(name, realExtension, link, size, creatorName, description, author, title, std::stoi(picsNumber));
}
