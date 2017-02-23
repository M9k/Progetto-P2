#include "../../GUI/header/view_file_video.h"


void view_file_video::edit() const
{
    view_file_multimedia::edit();
    edit_only_video();
}

void view_file_video::build_field()
{
    view_file_multimedia::build_field();
    build_filed_only_video();
}

void view_file_video::edit_only_video() const
{
    file_video* fv = dynamic_cast<file_video*>(f);
    fv->setVideoCodec(videoCodec->text().toStdString());
    fv->setWidth(std::stoi(width->text().toStdString()));
    fv->setHeight(std::stoi(height->text().toStdString()));
}

void view_file_video::build_filed_only_video()
{
    file_video* fv = dynamic_cast<file_video*>(f);
    videoCodec = new QLineEdit();
    width = new QLineEdit();
    height = new QLineEdit();
    videoCodec->setText(QString::fromStdString(fv->getVideoCodec()));
    width->setText(QString::number(fv->getWidth()));
    height->setText(QString::number(fv->getHeight()));
    width->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,4}"), this));
    height->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,4}"), this));
    layout->addRow(new QLabel("Codec video: "), videoCodec);
    layout->addRow(new QLabel("Larghezza (in pixel): "), width);
    layout->addRow(new QLabel("Altezza (in pixel): "), height);
}
