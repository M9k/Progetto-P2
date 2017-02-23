#include "../../GUI/header/view_file_epub.h"

void view_file_epub::edit() const
{
    view_file_text::edit();
    file_epub* fe = dynamic_cast<file_epub*>(f); //impossibile usare static_cast anche se so che il cast andrà a buon fine, per via della gerarchia
    if(picsNumberUnknow->isChecked())
        fe->setPicsNumber(-1);
    else
        fe->setPicsNumber(std::stoi(picsNumber->text().toStdString()));
}

void view_file_epub::build_field()
{
    view_file_text::build_field();
    file_epub* fe = dynamic_cast<file_epub*>(f);
    picsNumber = new QLineEdit();
    picsNumber->setText(QString::number(fe->getPicsNumber()));
    picsNumber->setValidator(new QIntValidator(-1, 60000, this));
    picsNumberUnknow = new QCheckBox();

    if(picsNumber->text()=="-1")
    {
        picsNumber->setText("Valore non definito");
        picsNumberUnknow->setChecked(true);
        picsNumber->setDisabled(true);
    }
    else
    {
        picsNumberUnknow->setChecked(false);
        picsNumber->setDisabled(false);
    }
    connect(picsNumberUnknow, SIGNAL(toggled(bool)), this, SLOT(updatePicsInfo(bool)));
    layout->addRow(new QLabel("Numero di immagini: "), picsNumber);
    layout->addRow(new QLabel("Numero di immagini non noto: "), picsNumberUnknow);
}


void view_file_epub::updatePicsInfo(bool s)
{
    if(s)
    {
        picsNumber->setText("Valore non definito");
        picsNumber->setDisabled(true);
    }
    else
    {
        picsNumber->setText("0");
        picsNumber->setDisabled(false);
    }

}
