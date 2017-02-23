#ifndef MAIN_DIALOG
#define MAIN_DIALOG

#include <QMainWindow>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QString>
#include <QMessageBox>
#include <QString>

#include "../../MODEL/header/listUser.h"
#include "../../GUI/header/main_widget.h"
#include "../../GUI/header/status_bar.h"
#include <string>

class Main_dialog : public QMainWindow {
    Q_OBJECT

public:
    Main_dialog(listUser& lu, user* loginUser, bool& reloginRef, QWidget *parent=0);

private:
    Status_bar* statoBarra;
    Main_widget* mainWidget;
    QMenuBar* menubar;
    QMenu* mbFile;
    QMenu* mbTools;
    QMenu* mbInfo;
    QAction* mbLogOut;
    QAction* mbEsci;
    QAction* mbTotalSize;
    QAction* mbInfoShow;

    listUser& listaUtenti;
    user* chiamante;
    bool& relogin;
    void setUser();
    void setMenuBar();

public slots:
    void reloginSlot();
private slots:
    void showInfo();
};

#endif
