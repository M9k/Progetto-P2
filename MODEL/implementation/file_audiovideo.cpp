#include "../header/file_audiovideo.h"


file_base* file_audiovideo::clone() const
{
	return new file_audiovideo(*this);
}

std::string file_audiovideo::getContainerFormat() const
{
    return containerFormat;
}

void file_audiovideo::setContainerFormat(std::string newContainerFormat)
{
 containerFormat = newContainerFormat;
}

std::string file_audiovideo::getInfo() const
{
    std::string rit = file_audio::getInfo();
	getVideoCodec()!="" ? rit+= "\nCodec video: " + getVideoCodec(): rit+="\nCodec video non specificato";
    getWidth()!=0 ? rit+="\nAltezza: " + std::to_string(getWidth()) + " pixel": rit+="\nAltezza non specificata";
    getHeight()!=0 ? rit+="\nLarghezza: " + std::to_string(getHeight()) + " pixel": rit+="\nLarghezza non specificata";
	getContainerFormat()!="" ? rit+="\nFormato del contenitore: " + getContainerFormat() : rit+="\nFormato del contenitore non specificato";
    return rit;
}

std::string file_audiovideo::getLabel() const
{
    return "AUDIOVIDEO";
}

const color_file file_audiovideo::getColor() const
{
    return file_video::getColor();
}

void file_audiovideo::exportMyXmlData(QXmlStreamWriter& xmlOutput) const
{
    file_multimedia::exportMyXmlData(xmlOutput);
    //audio
    xmlOutput.writeTextElement("audioCodec", QString::fromStdString(getAudioCodec()));
    xmlOutput.writeTextElement("campionamento", QString::number(getCampionamento()));
    //video
    xmlOutput.writeTextElement("videoCodec", QString::fromStdString(getVideoCodec()));
    xmlOutput.writeTextElement("width", QString::number(getWidth()));
    xmlOutput.writeTextElement("height", QString::number(getHeight()));
    //propri
    xmlOutput.writeTextElement("containerFormat", QString::fromStdString(getContainerFormat()));
}

void file_audiovideo::importMyXmlData(QXmlStreamReader &xmlInput, std::string& containerFormat)
{
    importTagXml(xmlInput, "containerFormat", containerFormat);
}

file_base* file_audiovideo::importXmlData(QXmlStreamReader& xmlInput)
{
    unsigned long long int size;
    std::string name, realExtension, link, creatorName, description;
    file_base::importMyXmlData(xmlInput, name, realExtension, link, size, creatorName, description);

    std::string bitrate, durataSec;
    file_multimedia::importMyXmlData(xmlInput, bitrate, durataSec);

    std::string audioCodec, campionamento;
    file_audio::importMyXmlData(xmlInput, audioCodec, campionamento);

    std::string videoCodec, width, height;
    file_video::importMyXmlData(xmlInput, videoCodec, width, height);

    std::string containerFormat;
    file_audiovideo::importMyXmlData(xmlInput, containerFormat);

    return new file_audiovideo(name, realExtension, link, size, creatorName, description, std::stoul(bitrate),
            std::stod(durataSec), audioCodec, std::stoul(campionamento), videoCodec,
            std::stoi(width), std::stoi(height), containerFormat);
}
