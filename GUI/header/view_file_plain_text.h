#ifndef VIEW_FILE_PLAIN_TEXT_H
#define VIEW_FILE_PLAIN_TEXT_H

#include "../../MODEL/header/file_base.h"
#include <QWidget>

#include "view_file_text.h"

class view_file_plain_text : public view_file_text
{
public:
    view_file_plain_text(file_base* file, QWidget* parent=nullptr):view_file_text(file, parent) {}
};



#endif // VIEW_FILE_PLAIN_TEXT_H
