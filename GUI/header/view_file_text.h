#ifndef VIEW_FILE_TEXT_H
#define VIEW_FILE_TEXT_H

#include "../../MODEL/header/file_base.h"
#include "../../MODEL/header/file_text.h"
#include <QWidget>
#include <QLineEdit>

#include "view_file_base.h"

class view_file_text : public view_file_base
{
public:
    view_file_text(file_base* file, QWidget* parent=nullptr):view_file_base(file, parent) {}
    virtual ~view_file_text() = 0;

protected:
    virtual void edit() const;
    virtual void build_field();
private:
    QLineEdit* author;
    QLineEdit* title;

};

#endif // VIEW_FILE_TEXT_H
