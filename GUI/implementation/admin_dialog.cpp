#include "../../GUI/header/admin_dialog.h"

Admin_dialog::Admin_dialog(listUser &lista_utenti, QWidget *parent): QMainWindow(parent), listaUtenti(lista_utenti)
{
    setWindowTitle("Pannello di amministrazione");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowModality(Qt::ApplicationModal);
    setWindowIcon(QIcon(QPixmap(":/admin")));

    adminWidget = new Admin_widget(listaUtenti);
    setCentralWidget(adminWidget);
    connect(adminWidget, SIGNAL(closeNow()), this, SLOT(close()));

    setMaximumSize(350,500);
}

