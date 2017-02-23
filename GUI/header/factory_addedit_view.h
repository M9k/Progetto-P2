#ifndef FACTORY_ADDEDIT_VIEW_H
#define FACTORY_ADDEDIT_VIEW_H

#include <string>
#include <QString>
#include "../../MODEL/header/file_base.h"
#include "../../MODEL/header/file_raw.h"
#include "../../MODEL/header/file_video.h"
#include "../../MODEL/header/file_audio.h"
#include "../../MODEL/header/file_audiovideo.h"
#include "../../MODEL/header/file_text.h"
#include "../../MODEL/header/file_plain_text.h"
#include "../../MODEL/header/file_epub.h"

#include "view_file_base.h"
#include "view_file_raw.h"
#include "view_file_text.h"
#include "view_file_plain_text.h"
#include "view_file_epub.h"
#include "view_file_audio.h"
#include "view_file_video.h"
#include "view_file_audiovideo.h"

class FactoryAddEdit_View {
public:
    static view_file_base* build(file_base*);
    virtual ~FactoryAddEdit_View() = 0; //per forzare l'astrazione
};

#endif // FACTORY_ADDEDIT_VIEW_H
