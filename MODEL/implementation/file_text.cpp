#include "../header/file_text.h"

std::string file_text::getAuthor() const
{
    return author;
}

std::string file_text::getTitle() const
{
    return file_text::title;
}

void file_text::setAuthor(std::string newAuthor)
{
    author = newAuthor;
}

void file_text::setTitle(std::string newTitle)
{
    title = newTitle;
}

std::string file_text::getInfo() const
{
    std::string rit = file_base::getInfo();
    getAuthor()!="" ? rit+= "\nAutore: " + getAuthor() : rit+= "\nAutore non specificato";
    getTitle()!="" ? rit+= "\nTitolo: " + getTitle() : rit+= "\nTitolo non specificato";
    return rit;
}

const color_file file_text::getColor() const
{
    return color_file(r,g,b);
}
void file_text::importMyXmlData(QXmlStreamReader &xmlInput, std::string& author, std::string& title)
{
    importTagXml(xmlInput, "author", author);
    importTagXml(xmlInput, "title", title);
}

void file_text::exportMyXmlData(QXmlStreamWriter& xmlOutput) const
{
    file_base::exportMyXmlData(xmlOutput);
    xmlOutput.writeTextElement("author", QString::fromStdString(getAuthor()));
    xmlOutput.writeTextElement("title", QString::fromStdString(getTitle()));
}
