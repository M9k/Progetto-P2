#ifndef VIEW_FILE_EPUB_H
#define VIEW_FILE_EPUB_H

#include "../../MODEL/header/file_base.h"
#include "../../MODEL/header/file_epub.h"
#include <QCheckBox>
#include <QWidget>

#include "view_file_text.h"

class view_file_epub : public view_file_text
{
    Q_OBJECT
public:
    view_file_epub(file_base* file, QWidget* parent=nullptr):view_file_text(file, parent) {}
protected:
    virtual void edit() const;
    virtual void build_field();
private:
    QLineEdit* picsNumber;
    QCheckBox* picsNumberUnknow;
private slots:
    void updatePicsInfo(bool);
};



#endif // VIEW_FILE_PLAIN_TEXT_H
