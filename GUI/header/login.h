#ifndef LOGIN
#define LOGIN

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPicture>
#include <QMessageBox>

#include "../../MODEL/header/listUser.h"
#include "../../MODEL/header/user.h"

class Login : public QDialog {
    Q_OBJECT

public:
    // costruttore
    Login(listUser& lista_user, user**loginUserRef, QWidget* parent=0);
    void clean();

public slots:
    // lista degli slot
    void tryLogin();

signals:
    void send(user*);

private:
    void createLayoutLogin();
    void createLoginButton();

    const listUser& listaUtenti;
    user**loginUser;

    QGridLayout* layoutLogin;
    QLabel* lname;
    QLabel* lpass;
    QLabel* lImgLogin;
    QLineEdit* tname;
    QLineEdit* tpass;
    QPushButton* blogin;
};

#endif
