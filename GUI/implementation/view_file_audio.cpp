#include "../../GUI/header/view_file_audio.h"


void view_file_audio::edit() const
{
    view_file_multimedia::edit();
    file_audio* fa = dynamic_cast<file_audio*>(f);
    fa->setAudioCodec(audioCodec->text().toStdString());
    fa->setCampionamento(std::stoul(campionamento->text().toStdString()));
}

void view_file_audio::build_field()
{
    view_file_multimedia::build_field();
    file_audio* fa = dynamic_cast<file_audio*>(f);
    audioCodec = new QLineEdit();
    campionamento = new QLineEdit();
    audioCodec->setText(QString::fromStdString(fa->getAudioCodec()));
    campionamento->setText(QString::number(fa->getCampionamento()));
    campionamento->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,8}"), this));
    layout->addRow(new QLabel("Codec audio: "), audioCodec);
    layout->addRow(new QLabel("Campionamento (in Hz): "), campionamento);
}

