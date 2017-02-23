#ifndef FILE_EPUB_H
#define FILE_EPUB_H

#include "file_text.h"

#include <QXmlStreamWriter>
#include <QString>

class file_epub: public virtual file_text
{
private:
    int picsNumber; //-1 = non specificato

public:
    file_epub(std::string nome, std::string realExtension, std::string link, unsigned long long int dimension, std::string creatorName,
               std::string descrizione="", std::string author_of_file="", std::string title_of_file="", int number_of_pics=-1)
        : file_text(nome, realExtension, link, dimension, creatorName, descrizione, author_of_file, title_of_file), picsNumber(number_of_pics) {}
    file_base* clone() const;
    int getPicsNumber() const;
    void setPicsNumber(int);
    virtual std::string getInfo() const;
    virtual std::string getLabel() const;
    virtual void exportMyXmlData(QXmlStreamWriter&) const;
    static void importMyXmlData(QXmlStreamReader&, std::string&);
    static file_base* importXmlData(QXmlStreamReader&);
};

#endif
