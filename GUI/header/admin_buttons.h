#ifndef ADMIN_BUTTONS_H
#define ADMIN_BUTTONS_H

#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>


class Admin_buttons : public QVBoxLayout
{
    Q_OBJECT
public:
    Admin_buttons(QWidget* parent=0);
private:
    QPushButton *butAggiungi, *butElimina, *butCambiaPassword, *butEsci;
private slots:
    void disableButtons();
public slots:
    void newSelectedItem();
signals:
    void addUser();
    void changeSelectedPassword();
    void removedSelected();
    void close();
};

#endif
