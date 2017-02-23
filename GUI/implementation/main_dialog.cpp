#include "../../GUI/header/main_dialog.h"

Main_dialog::Main_dialog(listUser& lu, user* loginUser, bool& reloginRef, QWidget* parent)
    : QMainWindow(parent), listaUtenti(lu), chiamante(loginUser), relogin(reloginRef)
{
    setWindowTitle("FileShare");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowIcon(QIcon(QPixmap(":/icona")));
    setUser();
    setMenuBar();
}

void Main_dialog::setUser()
{
    statoBarra = new Status_bar(QString::fromStdString(chiamante->getName()));
    setStatusBar(statoBarra);

    mainWidget = new Main_widget(listaUtenti, chiamante);
    setCentralWidget(mainWidget);
    connect(mainWidget, SIGNAL(changeStatus(QString)), statoBarra, SLOT(changeStatus(QString)));
    connect(mainWidget,SIGNAL(reloginSlot()),this, SLOT(reloginSlot()));
}

void Main_dialog::setMenuBar()
{
    menubar = menuBar();
    //parent senza valore di default su alcune versioni di QT (ad esempio in laboratorio)
    mbFile = new QMenu("File", nullptr);
    mbLogOut = new QAction("Cambia utente", nullptr);
    mbEsci = new QAction("Esci", nullptr);
    mbFile->addAction(mbLogOut);
    mbFile->addSeparator();
    mbFile->addAction(mbEsci);
    menubar->addMenu(mbFile);

    mbTools = new QMenu("Tools", nullptr);
    mbTotalSize = new QAction("Calcola dimensione totale", nullptr);
    mbTools->addAction(mbTotalSize);
    menubar->addMenu(mbTools);

    mbInfo  = new QMenu("Info", nullptr);
    mbInfoShow = new QAction("Info sullo sviluppatore", nullptr);
    mbInfo->addAction(mbInfoShow);
    menubar->addMenu(mbInfo);

    connect(mbLogOut, SIGNAL(triggered(bool)), this, SLOT(reloginSlot()));
    connect(mbLogOut, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(mbEsci, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(mbTotalSize, SIGNAL(triggered(bool)), mainWidget, SLOT(calculateGbTot()));
    connect(mbInfoShow, SIGNAL(triggered(bool)), this, SLOT(showInfo()));
}

void Main_dialog::reloginSlot()
{
    relogin = true;
}

void Main_dialog::showInfo()
{
    QMessageBox info;
    info.setText("Applicazione creata da Cailotto Mirco.");
    info.setWindowTitle("Informazioni sullo sviluppatore");
    info.setWindowIcon(QIcon(QPixmap(":/info")));
    info.exec();
}
