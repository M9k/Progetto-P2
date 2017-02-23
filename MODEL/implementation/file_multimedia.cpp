#include "../header/file_multimedia.h"

unsigned long int file_multimedia::getBitrate() const
{
	return bitrate;
}

double file_multimedia::getDurataSec() const
{
    return file_multimedia::durataSec;
}

void file_multimedia::setBitrate(unsigned long newBitrate)
{
    bitrate = newBitrate;
}

void file_multimedia::setDurataSec(double newDurataSec)
{
    durataSec = newDurataSec;
}

std::string file_multimedia::getInfo() const
{
    std::string rit = file_base::getInfo();
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << getDurataSec();
    getBitrate()!=0 ? rit+= "\nBitrate: " + std::to_string(getBitrate()) + "KB/s" : rit+= "\nBitrate non specificato";
    getDurataSec()!=0 ? rit+= "\nDurata: " +  stream.str() + 's' : rit+= "\nDurata non specificata";
    return rit;
}

void file_multimedia::exportMyXmlData(QXmlStreamWriter& xmlOutput) const
{
    file_base::exportMyXmlData(xmlOutput);
    xmlOutput.writeTextElement("bitrate", QString::number(getBitrate()));
    xmlOutput.writeTextElement("durataSec", QString::number(getDurataSec()));
}

void file_multimedia::importMyXmlData(QXmlStreamReader &xmlInput, std::string& bitrate, std::string& durataSec)
{
    importTagXml(xmlInput, "bitrate", bitrate);
    importTagXml(xmlInput, "durataSec", durataSec);
}
