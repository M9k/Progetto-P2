#include "../../GUI/header/view_file_multimedia.h"

view_file_multimedia::~view_file_multimedia() {}

void view_file_multimedia::edit() const {
    view_file_base::edit();
    file_multimedia* fm = static_cast<file_multimedia*>(f);
    fm->setBitrate(std::stoul(bitrate->text().toStdString()));
    fm->setDurataSec(std::stod(durataSec->text().toStdString()));
}
void view_file_multimedia::build_field() {
    view_file_base::build_field();
    file_multimedia* fm = static_cast<file_multimedia*>(f);
    bitrate = new QLineEdit();
    durataSec = new QDoubleSpinBox();
    bitrate->setText(QString::number(fm->getBitrate()));
    durataSec->setMaximum(8640000); //100 giorni
    durataSec->setValue(fm->getDurataSec());
    bitrate->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,8}"), this));
    layout->addRow(new QLabel("Bitrate (in KByte/s): "), bitrate);
    layout->addRow(new QLabel("Durata (in secondi): "), durataSec);

}
