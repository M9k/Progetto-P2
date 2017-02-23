#ifndef ADDEDITFILE_H
#define ADDEDITFILE_H

#include <QFormLayout>

#include "../../MODEL/header/file_base.h"
#include "../../GUI/header/view_file_base.h"
#include "factory_addedit_view.h"

class AddEditFile : public QDialog {
    Q_OBJECT

public:
    AddEditFile(file_base* file_to_edit, QWidget* parent=0);

private:
    file_base* f;
    QFormLayout* layout;
};

#endif
