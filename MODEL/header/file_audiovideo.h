#ifndef FILE_AUDIOVIDEO
#define FILE_AUDIOVIDEO

#include "file_audio.h"
#include "file_video.h"
#include "color_file.h"
#include <string>

//eredito il colore dei file multimediali, non lo cambio
class file_audiovideo: public file_audio, public file_video
{
private:
    std::string containerFormat;
	
public:
	file_audiovideo(
                    std::string nome, std::string realExtension, std::string link, unsigned long long int dimension, std::string creatorName, std::string descrizione="", unsigned long int bitrate=0, double durata=0, //file_multimedia
                    std::string codec_audio="", unsigned long int campionamento=0, //file_audio
                    std::string codec_video="", unsigned int width=0, unsigned int height=0, //file_video
                    std::string contenitor_format="")	//campi propri
                    :	file_multimedia(nome, realExtension, link, dimension, creatorName, descrizione, bitrate, durata),
                        file_audio(nome, realExtension, link, dimension, creatorName, descrizione, bitrate, durata, codec_audio, campionamento),
                        file_video(nome, realExtension, link, dimension, creatorName, descrizione, bitrate, durata, codec_video, width, height), //come sopra
                        containerFormat(contenitor_format){}
					
    file_base* clone() const;
    std::string getContainerFormat() const;
    void setContainerFormat(std::string);
	virtual std::string getInfo() const;
    virtual std::string getLabel() const;
    virtual const color_file getColor() const;
    virtual void exportMyXmlData(QXmlStreamWriter&) const;
    static void importMyXmlData(QXmlStreamReader&, std::string&);
    static file_base* importXmlData(QXmlStreamReader&);
};
#endif
