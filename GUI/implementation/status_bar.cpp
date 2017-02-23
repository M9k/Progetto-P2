#include "../../GUI/header/status_bar.h"

Status_bar::Status_bar(QString nome, QWidget* parent) : QStatusBar(parent)
{
    welcome = new QLabel("Benvenuto " + nome);
    status = new QLabel("Login effettuato");
    status->setAlignment(Qt::AlignRight);
    addPermanentWidget(welcome,1);
    addPermanentWidget(status,3);
}

void Status_bar::changeStatus(QString nuovo_messaggio)
{
    status->setText(nuovo_messaggio);
}
