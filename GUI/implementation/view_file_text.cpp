#include "../../GUI/header/view_file_text.h"

view_file_text::~view_file_text() {}

void view_file_text::edit() const
{
    view_file_base::edit();
    file_text* ft = static_cast<file_text*>(f);
    ft->setAuthor(author->text().toStdString());
    ft->setTitle(title->text().toStdString());
}

void view_file_text::build_field()
{
    view_file_base::build_field();
    file_text* ft = static_cast<file_text*>(f);
    author = new QLineEdit();
    title = new QLineEdit();

    author->setPlaceholderText(QString("Es: Alessandro Manzoni"));
    title->setPlaceholderText(QString("Es: I promessi sposi"));

    author->setText(QString::fromStdString(ft->getAuthor()));
    title->setText(QString::fromStdString(ft->getTitle()));
    layout->addRow(new QLabel("Autore del testo: "), author);
    layout->addRow(new QLabel("Titolo del testo: "), title);
}

