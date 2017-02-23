#ifndef ADMIN_LAYOUT_H
#define ADMIN_LAYOUT_H

#include <QGridLayout>
#include <QWidget>

#include "../../MODEL/header/listUser.h"
#include "admin_buttons.h"
#include "admin_list_users.h"

class Admin_widget : public QWidget
{
    Q_OBJECT

public:
    Admin_widget(listUser& lista_utenti ,QWidget* parent=0);

private:
    listUser& listaUtenti;
    QGridLayout* grid;
    Admin_buttons* listaTasti;
    Admin_list_users* listaUtentiGrafica;

signals:
    void closeNow();
};

#endif
