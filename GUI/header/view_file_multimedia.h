#ifndef VIEW_FILE_MULTIMEDIA_H
#define VIEW_FILE_MULTIMEDIA_H

#include "view_file_base.h"
#include "../../MODEL/header/file_multimedia.h"

#include <QDoubleSpinBox>
#include <QLineEdit>

class view_file_multimedia : public view_file_base
{
public:
    view_file_multimedia(file_base* file, QWidget* parent=nullptr):view_file_base(file, parent) {}
    virtual ~view_file_multimedia() = 0;

protected:
    virtual void edit() const;
    virtual void build_field();

private:
    QLineEdit* bitrate;
    QDoubleSpinBox* durataSec;
};

#endif // VIEW_FILE_MULTIMEDIA_H
