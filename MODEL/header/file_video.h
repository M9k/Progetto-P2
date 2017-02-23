#ifndef FILE_VIDEO
#define FILE_VIDEO

#include "file_multimedia.h"
#include <string>

class file_video: public virtual file_multimedia
{
private:
    std::string videoCodec;
    unsigned int width, height;
    static const int r = 200, g = 100, b = 255;
	
public:
    file_video(std::string nome, std::string realExtension, std::string link, unsigned long long int dimension, std::string creatorName, std::string descrizione="", unsigned long int bitrate=0, double durata=0, std::string video_codec="", unsigned int width_file=0, unsigned int height_file=0)
        : file_multimedia(nome, realExtension, link, dimension, creatorName, descrizione, bitrate, durata), videoCodec(video_codec), width(width_file), height(height_file) {}
    file_base* clone() const;
    std::string getVideoCodec() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    void setVideoCodec(std::string);
    void setWidth(unsigned int);
    void setHeight(unsigned int);
    virtual std::string getInfo() const;
    virtual std::string getLabel() const;
    virtual const color_file getColor() const;
    virtual void exportMyXmlData(QXmlStreamWriter&) const;
    static void importMyXmlData(QXmlStreamReader&, std::string&, std::string&, std::string&);
    static file_base* importXmlData(QXmlStreamReader&);
};
#endif
