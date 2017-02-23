#ifndef FILE_TEXT_H
#define FILE_TEXT_H

#include <string>

#include "file_base.h"
#include "color_file.h"

#include <QXmlStreamWriter>
#include <QString>

//astratto, non ridefinisco clone e getLabel
class file_text: public file_base
{
private:
    std::string author;
    std::string title;
    static const int r = 255, g = 255, b = 150;

public:
    file_text(std::string nome, std::string real_extension, std::string link, unsigned long long int dimension, std::string creator_name, std::string description="", const std::string author_of_file="", const std::string title_of_file=""):
        file_base(nome, real_extension, link, dimension, creator_name, description), author(author_of_file), title(title_of_file) {}
    std::string getAuthor() const;
    std::string getTitle() const;
    void setAuthor(std::string);
    void setTitle(std::string);
    virtual std::string getInfo() const;
    virtual const color_file getColor() const;
    virtual void exportMyXmlData(QXmlStreamWriter&) const;
    static void importMyXmlData(QXmlStreamReader&, std::string&, std::string&);
};
#endif
