#ifndef FILE_RAW
#define FILE_RAW

#include "file_base.h"
#include "color_file.h" 

//file non classificabili in altri modi e di formati specifici di applicazioni o suite, ad esempio progetti, salvataggi, configurazioni etc
//istanziabile, non astratto

class file_raw: public file_base
{
private:
    static const int r = 255, g = 255, b = 255;
public:
    file_raw(std::string nome, std::string real_extension, std::string link, unsigned long long int dimension, std::string creator_name, std::string description="")
        : file_base(nome, real_extension, link, dimension, creator_name, description) {}
    file_base* clone() const;
	virtual const color_file getColor() const;
    virtual std::string getLabel() const;
    virtual void exportMyXmlData(QXmlStreamWriter&) const;
    //getInfo() ereditata
    static file_base* importXmlData(QXmlStreamReader&);
};
#endif
