#include "../header/file_audio.h"

file_base* file_audio::clone() const
{
	return new file_audio(*this);
}

const std::string& file_audio::getAudioCodec() const
{
	return audioCodec;
}

unsigned long int file_audio::getCampionamento() const
{
    return campionamento;
}

void file_audio::setAudioCodec(std::string newAudioCodec)
{
    audioCodec = newAudioCodec;
}

void file_audio::setCampionamento(unsigned long newCampionamento)
{
    campionamento = newCampionamento;
}

std::string file_audio::getInfo() const
{
    std::string rit = file_multimedia::getInfo();
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << getCampionamento();
	getAudioCodec()!="" ? rit+= "\nCodec audio: " + getAudioCodec(): rit+="\nCodec audio non specificato";
    getCampionamento()!=0 ? rit+="\nCampionamento: " + stream.str() + "Hz": rit+="\nCampionamento non specificato";
    return rit;
}

std::string file_audio::getLabel() const
{
    return "AUDIO";
}

const color_file file_audio::getColor() const
{
    return color_file(r,g,b);
}

void file_audio::exportMyXmlData(QXmlStreamWriter& xmlOutput) const
{
    file_multimedia::exportMyXmlData(xmlOutput);
    xmlOutput.writeTextElement("audioCodec", QString::fromStdString(getAudioCodec()));
    xmlOutput.writeTextElement("campionamento", QString::number(getCampionamento()));
}

void file_audio::importMyXmlData(QXmlStreamReader &xmlInput, std::string& audioCodec, std::string& campionamento)
{
    importTagXml(xmlInput, "audioCodec", audioCodec);
    importTagXml(xmlInput, "campionamento", campionamento);
}
file_base* file_audio::importXmlData(QXmlStreamReader& xmlInput)
{
    unsigned long long int size;
    std::string name, realExtension, link, creatorName, description;
    file_base::importMyXmlData(xmlInput, name, realExtension, link, size, creatorName, description);

    std::string bitrate, durataSec;
    file_multimedia::importMyXmlData(xmlInput, bitrate, durataSec);

    std::string audioCodec, campionamento;
    file_audio::importMyXmlData(xmlInput, audioCodec, campionamento);

    return new file_audio(name, realExtension, link, size, creatorName, description, std::stoul(bitrate),
                         std::stod(durataSec), audioCodec, std::stoul(campionamento));
}


