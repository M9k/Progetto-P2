#ifndef FILE_MULTIMEDIA
#define FILE_MULTIMEDIA

#include <string>

#include "file_base.h"
#include "color_file.h" 
#include <string>
#include <sstream>
#include <iomanip>

#include <QXmlStreamWriter>
#include <QString>

//astratto, non ridefinisco clone e getLabel
class file_multimedia: public file_base
{
private:
    unsigned long int bitrate;
    double durataSec;
	
public:
    file_multimedia(std::string nome, std::string real_extension, std::string link, unsigned long long int dimension, std::string creator_name, std::string description="", unsigned long int bitrate_file=0, double durata_sec=0):
        file_base(nome, real_extension, link, dimension, creator_name, description), bitrate(bitrate_file), durataSec(durata_sec) {}
    unsigned long int getBitrate() const;
    double getDurataSec() const;
    void setBitrate(unsigned long int);
    void setDurataSec(double);
    virtual std::string getInfo() const;
    virtual void exportMyXmlData(QXmlStreamWriter&) const;
    static void importMyXmlData(QXmlStreamReader&, std::string&, std::string&);
};
#endif
