#include "../../GUI/header/view_file_base.h"

void view_file_base::buildGUI() {
    build_field();
    build_buttons();
}

view_file_base::~view_file_base() {}

void view_file_base::build_field()
{
    layout = new QFormLayout(this);
    name = new QLineEdit();
    realExtension = new QLineEdit();
    link = new QLineEdit();
    size = new QLineEdit();
    description = new QLineEdit();

    name->setPlaceholderText(QString("Es: I promessi sposi - Alessandro Manzoni - 1827"));
    realExtension->setPlaceholderText(QString("Es: zip"));
    link->setPlaceholderText(QString("Es: www.mediafire.com/download?id=a7gqxr"));

    name->setText(QString::fromStdString(f->getName()));
    realExtension->setText(QString::fromStdString(f->getRealExtension()));
    link->setText(QString::fromStdString(f->getLink()));
    size->setText(QString::number(f->getSize()));
    size->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,15}"), this)); //interi fino a 15 cifre (~999TeraByte)
    description->setText(QString::fromStdString(f->getDescription()));
    layout->addRow(new QLabel("*Nome:"), name);
    layout->addRow(new QLabel("*Estensione:"), realExtension);
    layout->addRow(new QLabel("*Link:"), link);
    layout->addRow(new QLabel("*Dimensione (in Byte): "), size);
    layout->addRow(new QLabel("Descrizione:"), description);
}

void view_file_base::build_buttons()
{
    bNo = new QPushButton();
    bOk = new QPushButton();
    bNo->setText("Annulla");
    bNo->setFixedWidth(200);
    bOk->setText("Ok");
    bOk->setFixedWidth(200);
    bOk->setFocus();
    layout->addRow(bNo, bOk);
    layout->addRow(new QLabel("I campi contraddistinti dall'asterisco (*) sono obbligatori"));

    connect(bNo, SIGNAL(clicked()), this, SLOT(rejectedits()));
    connect(bOk, SIGNAL(clicked()), this, SLOT(checkAndEdit()));
}

bool view_file_base::check() const
{
    if(size->text() == "0")
    {
        QMessageBox msgErr;
        msgErr.setWindowTitle("Errore!");
        msgErr.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgErr.setText("La dimensione del file non può essere 0");
        msgErr.exec();
        return false;
    }
    if(name->text() == "" || realExtension->text() == "" || link->text() == "")
    {
        QMessageBox msgErr;
        msgErr.setWindowTitle("Errore!");
        msgErr.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgErr.setText("Controlla di aver inserito tutti i campi obbligatori");
        msgErr.exec();
        return false;
    }
    if(link->text().count(QLatin1Char('.')) < 1 || link->text().count(QLatin1Char(' ')) > 0) //deve esserci almeno un punto per il dominio e nessuno spazio
    {
        QMessageBox msgErr;
        msgErr.setWindowTitle("Errore!");
        msgErr.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgErr.setText("Il link inserito non sembra essere valido");
        msgErr.exec();
        return false;
    }
    return true;
}

void view_file_base::edit() const
{
    f->setName(name->text().toStdString());
    f->setRealExtension(realExtension->text().toStdString());
    f->setLink(link->text().toStdString());
    f->setSize(std::stoull(size->text().toStdString()));
    f->setDescription(description->text().toStdString());
}

void view_file_base::checkAndEdit()
{
    if(check())
    {
        edit();

        emit accept();
    }
    else
    {
        QMessageBox msgErr;
        msgErr.setWindowTitle("Errore!");
        msgErr.setWindowIcon(QIcon(QPixmap(":/error")));
        msgErr.setText("Dati invaliti!");
    }
}

void view_file_base::rejectedits()
{
    emit reject();
}
