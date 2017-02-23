#include "../../GUI/header/admin_widget.h"

Admin_widget::Admin_widget(listUser& lista_utenti ,QWidget* parent):
    QWidget(parent), listaUtenti(lista_utenti)
{
    grid = new QGridLayout();
    listaTasti = new Admin_buttons();
    listaUtentiGrafica = new Admin_list_users(listaUtenti);
    grid->addItem(listaTasti,0,0);
    grid->addItem(listaUtentiGrafica,0,1);
    setLayout(grid);

    connect(listaUtentiGrafica, SIGNAL(newSelectedItem()), listaTasti, SLOT(newSelectedItem()));
    connect(listaTasti, SIGNAL(addUser()), listaUtentiGrafica, SLOT(addUser()));
    connect(listaTasti, SIGNAL(removedSelected()), listaUtentiGrafica, SLOT(removedSelected()));
    connect(listaTasti, SIGNAL(close()), this, SIGNAL(closeNow()));
    connect(listaTasti, SIGNAL(changeSelectedPassword()), listaUtentiGrafica, SLOT(changeSelectedPassword()));
}
