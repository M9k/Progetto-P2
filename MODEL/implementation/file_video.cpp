#include "../header/file_video.h"

file_base* file_video::clone() const
{
	return new file_video(*this);
}

std::string file_video::getVideoCodec() const
{
	return videoCodec;
}

unsigned int file_video::getWidth() const
{
	return width;
}

unsigned int file_video::getHeight() const
{
    return height;
}

void file_video::setVideoCodec(std::string newVideoCodec)
{
    videoCodec = newVideoCodec;
}

void file_video::setWidth(unsigned int newWidth)
{
    width = newWidth;
}

void file_video::setHeight(unsigned int newHeigth)
{
    height = newHeigth;
}

std::string file_video::getInfo() const
{
	std::string rit = file_multimedia::getInfo();
	getVideoCodec()!="" ? rit+= "\nCodec video: " + getVideoCodec(): rit+="\nCodec video non specificato";
    getWidth()!=0 ? rit+= "\nAltezza: " + std::to_string(getWidth()) + " pixel": rit+="\nAltezza non specificata";
    getHeight()!=0 ? rit+= "\nLarghezza: " + std::to_string(getHeight()) + " pixel": rit+="\nLarghezza non specificata";
    return rit;
}

std::string file_video::getLabel() const
{
    return "VIDEO";
}

const color_file file_video::getColor() const
{
    return color_file(r,g,b);
}

void file_video::exportMyXmlData(QXmlStreamWriter& xmlOutput) const
{
    file_multimedia::exportMyXmlData(xmlOutput);
    xmlOutput.writeTextElement("videoCodec", QString::fromStdString(getVideoCodec()));
    xmlOutput.writeTextElement("width", QString::number(getWidth()));
    xmlOutput.writeTextElement("height", QString::number(getHeight()));
}

void file_video::importMyXmlData(QXmlStreamReader &xmlInput, std::string& videoCodec, std::string& width, std::string& height)
{
    importTagXml(xmlInput, "videoCodec", videoCodec);
    importTagXml(xmlInput, "width", width);
    importTagXml(xmlInput, "height", height);
}
file_base* file_video::importXmlData(QXmlStreamReader& xmlInput)
{
    unsigned long long int size;
    std::string name, realExtension, link, creatorName, description;
    file_base::importMyXmlData(xmlInput, name, realExtension, link, size, creatorName, description);

    std::string bitrate, durataSec;
    file_multimedia::importMyXmlData(xmlInput, bitrate, durataSec);

    std::string videoCodec, width, height;
    file_video::importMyXmlData(xmlInput, videoCodec, width, height);

    return new file_video(name, realExtension, link, size, creatorName, description, std::stoul(bitrate),
            std::stod(durataSec), videoCodec, std::stoi(width), std::stoi(height));
}

