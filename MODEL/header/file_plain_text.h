#ifndef FILE_PLAIN_TEXT_H
#define FILE_PLAIN_TEXT_H

#include "file_text.h"

class file_plain_text: public virtual file_text
{
    //nessun campo aggiuntivo
public:
    file_plain_text(std::string nome, std::string realExtension, std::string link, unsigned long long int dimension, std::string creatorName,
               std::string descrizione="", std::string author_of_file="", std::string title_of_file="")
        : file_text(nome, realExtension, link, dimension, creatorName, descrizione, author_of_file, title_of_file) {}
    file_base* clone() const;
    virtual std::string getLabel() const;
    //getInfo e exportMyXmlData ereditati
    static file_base* importXmlData(QXmlStreamReader&);
};
#endif
