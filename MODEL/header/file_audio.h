#ifndef FILE_AUDIO
#define FILE_AUDIO

#include "file_multimedia.h"
#include "color_file.h"
#include <string>
#include <sstream>
#include <iomanip>

class file_audio: public virtual file_multimedia
{
private:
    std::string audioCodec;
    unsigned long int campionamento;
    static const int r = 200, g = 255, b = 255;
	
public:
    file_audio(std::string nome, std::string realExtension, std::string link, unsigned long long int dimension, std::string creatorName, std::string descrizione="", unsigned long int bitrate=0, double durata=0, std::string audio_codec="", unsigned long int campionamento_sec=0)
        : file_multimedia(nome, realExtension, link, dimension, creatorName, descrizione, bitrate, durata), audioCodec(audio_codec), campionamento(campionamento_sec) {}
    file_base* clone() const;
    const std::string& getAudioCodec() const;
    unsigned long int getCampionamento() const;
    void setAudioCodec(std::string);
    void setCampionamento(unsigned long int);
	virtual std::string getInfo() const;
    virtual std::string getLabel() const;
    virtual const color_file getColor() const;
    virtual void exportMyXmlData(QXmlStreamWriter&) const;
    static void importMyXmlData(QXmlStreamReader&, std::string&, std::string&);
    static file_base* importXmlData(QXmlStreamReader&);
};
#endif
