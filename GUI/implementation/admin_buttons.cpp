#include "../../GUI/header/admin_buttons.h"

Admin_buttons::Admin_buttons(QWidget* parent) : QVBoxLayout(parent)
{
    butAggiungi = new QPushButton();
    butElimina = new QPushButton();
    butCambiaPassword = new QPushButton();
    butEsci = new QPushButton();
    butAggiungi->setText("Aggiungi un utente");
    butElimina->setText("Elimina l'utente");
    butElimina->setDisabled(true);
    butCambiaPassword->setText("Cambia la password");
    butCambiaPassword->setDisabled(true);
    butEsci->setText("Torna alla gestione dati");
    addWidget(butAggiungi);
    addWidget(butElimina);
    addWidget(butCambiaPassword);
    addWidget(butEsci);
    connect(butAggiungi, SIGNAL(clicked()), this, SIGNAL(addUser()));
    connect(butElimina, SIGNAL(clicked()), this, SIGNAL(removedSelected()));
    connect(butElimina, SIGNAL(clicked()), this, SLOT(disableButtons()));
    connect(butCambiaPassword, SIGNAL(clicked()), this, SIGNAL(changeSelectedPassword()));
    connect(butEsci, SIGNAL(clicked()), this, SIGNAL(close()));
}

void Admin_buttons::newSelectedItem()
{
    butElimina->setDisabled(false);
    butCambiaPassword->setDisabled(false);
}

void Admin_buttons::disableButtons()
{
    butElimina->setDisabled(true);
    butCambiaPassword->setDisabled(true);
}
