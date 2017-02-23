#ifndef VIEW_FILE_RAW_H
#define VIEW_FILE_RAW_H

#include "../../MODEL/header/file_base.h"
#include <QWidget>

#include "view_file_base.h"

class view_file_raw : public view_file_base
{
public:
    view_file_raw(file_base* file, QWidget* parent=nullptr):view_file_base(file, parent) {}
};

#endif // VIEW_FILE_RAW_H
