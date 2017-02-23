#include "../../GUI/header/factory_addedit_view.h"

view_file_base* FactoryAddEdit_View::build(file_base* f){

    if(dynamic_cast<file_audiovideo*>(f))
        return new view_file_audiovideo(f);
    if(dynamic_cast<file_audio*>(f))
        return new view_file_audio(f);
    if(dynamic_cast<file_video*>(f))
        return new view_file_video(f);
    if(dynamic_cast<file_epub*>(f))
        return new view_file_epub(f);
    if(dynamic_cast<file_plain_text*>(f))
        return new view_file_plain_text(f);
    if(dynamic_cast<file_raw*>(f))
        return new view_file_raw(f);
    return nullptr;
}

FactoryAddEdit_View::~FactoryAddEdit_View() {}
