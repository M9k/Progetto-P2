#include "../../GUI/header/view_file_audiovideo.h"


void view_file_audiovideo::edit() const
{
    view_file_audio::edit();
    edit_only_video();
    file_audiovideo* fav = dynamic_cast<file_audiovideo*>(f);
    fav->setContainerFormat(containerFormat->text().toStdString());
}

void view_file_audiovideo::build_field()
{
    view_file_audio::build_field();
    build_filed_only_video();
    file_audiovideo* fav = dynamic_cast<file_audiovideo*>(f);
    containerFormat = new QLineEdit();
    containerFormat->setText(QString::fromStdString(fav->getContainerFormat()));
    layout->addRow(new QLabel("Formato del contenitore: "), containerFormat);
}

