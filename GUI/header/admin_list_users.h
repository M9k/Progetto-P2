#ifndef ADMIN_LISTA_UTENTI_H
#define ADMIN_LISTA_UTENTI_H

#include <QVBoxLayout>
#include <QListWidget>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QFormLayout>
#include <QInputDialog>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

#include "../../MODEL/header/listUser.h"
#include "../../MODEL/header/user.h"
#include "../../MODEL/header/user_admin.h"
#include "../../MODEL/header/user_editor.h"
#include "../../MODEL/header/user_moderator.h"
#include "../../MODEL/header/user_standard.h"

class Admin_list_users : public QVBoxLayout
{
    Q_OBJECT
public:
    Admin_list_users(listUser& lista_utenti ,QWidget* parent=0);

private:
    listUser& listaUtenti;
    QLabel* labelUtenti;
    QListWidget* lista;

    QLabel* lsearch;
    QLineEdit* search;

    void reloadList();
    void filterList();

signals:
    void newSelectedItem();

public slots:
    void reloadWidgetList();
    void filterWidgetList();
    void addUser();
    void removedSelected();
    void changeSelectedPassword();
};

#endif
