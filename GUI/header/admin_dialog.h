#ifndef ADMIN_DIALOG_H
#define ADMIN_DIALOG_H

#include <QMainWindow>
#include <QString>
#include "../../MODEL/header/listUser.h"
#include "admin_widget.h"

class Admin_dialog : public QMainWindow
{
public:
    Admin_dialog(listUser& lista_utenti ,QWidget* parent=0);

private:
    listUser& listaUtenti;
    Admin_widget* adminWidget;
};

#endif
