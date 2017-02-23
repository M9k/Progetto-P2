#ifndef FACTORYFILE_H
#define FACTORYFILE_H

#include "../../MODEL/header/file_base.h"
#include <string>
#include <QString>
#include <QXmlStreamReader>

#include "file_base.h"
#include "file_audio.h"
#include "file_audiovideo.h"
#include "file_epub.h"
#include "file_plain_text.h"
#include "file_raw.h"
#include "file_video.h"

class FactoryFile {
public:
    static file_base* build(const QString&, const std::string&);
    static file_base* buildWithXmlTag(const std::string&, QXmlStreamReader&);
    virtual ~FactoryFile() = 0; //per forzare l'astrazione
};

#endif // FACTORYFILE_H
