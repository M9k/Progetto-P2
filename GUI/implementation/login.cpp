#include "../../GUI/header/login.h"

Login::Login(listUser& lista_user, user**loginUserRef, QWidget* parent):
    QDialog(parent), listaUtenti(lista_user), loginUser(loginUserRef)
{
    setWindowTitle("FileShare - Login");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowIcon(QIcon(QPixmap(":/icona")));

    createLayoutLogin();
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutLogin);
    setLayout(mainLayout);
}

void Login::clean()
{
    tname->clear();
    tpass->clear();
    tname->setFocus();
}

void Login::tryLogin()
{
    if(listaUtenti.checkPassword(listaUtenti.search((tname->text()).toStdString()), (tpass->text()).toStdString()))
    {
        //send((listaUtenti.search((tname->text()).toStdString())));
        *loginUser = listaUtenti.search((tname->text()).toStdString());
        this->close();
    }
    else
    {
        QMessageBox msgError;
        if(listaUtenti.search((tname->text()).toStdString()))
        {
            msgError.setText("Password errata");
            msgError.setWindowIcon(QIcon(QPixmap(":/error")));
        }
        else
        {
            msgError.setText("Utente non trovato");
            msgError.setWindowIcon(QIcon(QPixmap(":/warning")));
        }
        msgError.exec();
    }
}

void Login::createLayoutLogin()
{
    layoutLogin = new QGridLayout();
    lname = new QLabel();
    lname->setText("Nome:");
    lpass = new QLabel();
    lpass->setText("Password:");
    lImgLogin = new QLabel;
    QPixmap img;
    img.load(":/login.png");
    lImgLogin->setPixmap(img.scaled(80,80));
    tname = new QLineEdit();
    tpass = new QLineEdit();
    tpass->setEchoMode(QLineEdit::Password);
    layoutLogin->addWidget(lImgLogin, 0, 2, 4, 1); //si "mangia" 4 righe
    layoutLogin->addWidget(lname, 1, 0);
    layoutLogin->addWidget(tname, 1, 1);
    layoutLogin->addWidget(lpass, 2, 0);
    layoutLogin->addWidget(tpass, 2, 1);

    blogin = new QPushButton();
    blogin->setText("Login");
    layoutLogin->addWidget(blogin, 3, 0, 1, 2);
    connect(blogin, SIGNAL(clicked()), this, SLOT(tryLogin()));

    setFixedSize(280,110);
}
