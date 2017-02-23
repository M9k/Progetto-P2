#include "../../MODEL/header/factoryfile.h"

file_base* FactoryFile::build(const QString& tipo, const std::string& creatore){

    if(tipo == "Audio")
        return new file_audio("","","",0,creatore);
    if(tipo == "Video")
        return new file_video("","","",0,creatore);
    if(tipo == "Contenitore video")
        return new file_audiovideo("","","",0,creatore);
    if(tipo == "Testo semplice")
        return new file_plain_text("","","",0,creatore);
    if(tipo == "Epub")
        return new file_epub("","","",0,creatore);
    if(tipo == "File generico")
        return new file_raw("","","",0,creatore);
    return nullptr;
}

file_base* FactoryFile::buildWithXmlTag(const std::string& classname, QXmlStreamReader& xmlInput)
{
    if (classname == "RAW")
        return file_raw::importXmlData(xmlInput);
    if (classname == "AUDIO")
        return file_audio::importXmlData(xmlInput);
    if (classname == "VIDEO")
        return file_video::importXmlData(xmlInput);
    if (classname == "AUDIOVIDEO")
        return file_audiovideo::importXmlData(xmlInput);
    if (classname == "PLAIN_TEXT")
        return file_plain_text::importXmlData(xmlInput);
    if (classname == "EPUB")
        return file_epub::importXmlData(xmlInput);
    return nullptr;
}

FactoryFile::~FactoryFile() {}
