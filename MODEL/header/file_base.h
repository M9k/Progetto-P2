#ifndef FILE_BASE
#define FILE_BASE

#include <string>
#include "common_functions.h"
#include <QXmlStreamWriter>
#include <QString>
#include "color_file.h" 
#include "size_of_file.h"

class file_base
{
private:
	std::string name;
    std::string realExtension;
    std::string link;
    size_of_file size;
    const std::string creatorName;
	std::string description;
	
public:
    file_base(std::string nome, std::string real_extension, std::string link_file, unsigned long long int dimension_file, std::string creator_name, std::string description_file=""):
        name(nome), realExtension(real_extension), link(link_file), size(dimension_file), creatorName(creator_name), description(description_file) {}

	//polimorfici
    virtual std::string getInfo() const;
	virtual const color_file getColor() const = 0;
    virtual std::string getLabel() const;
	
	const std::string& getName() const;
	const std::string& getRealExtension() const;
	const std::string& getLink() const;
	const size_of_file& getSize() const;
	const std::string& getCreatorName() const;
    const std::string& getDescription() const;

    void exportXml(QXmlStreamWriter&) const;
    virtual void exportMyXmlData(QXmlStreamWriter&) const;

    void setName(std::string);
    void setRealExtension(std::string);
    void setLink(std::string);
    void setSize(size_of_file);
    void setDescription(std::string);

    virtual file_base* clone() const = 0;
    virtual ~file_base() {}
    //copia, assegnazione standard

    static void importMyXmlData(QXmlStreamReader&, std::string&, std::string&, std::string&, unsigned long long int&, std::string&, std::string&);
};
#endif
