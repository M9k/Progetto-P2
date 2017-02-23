#ifndef VIEW_FILE_BASE_H
#define VIEW_FILE_BASE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QMessageBox>
#include <QLineEdit>
#include <QRegExpValidator>

#include "../../MODEL/header/file_base.h"

class view_file_base : public QWidget{
    Q_OBJECT
public:
    view_file_base(file_base* file, QWidget* parent=nullptr):QWidget(parent),  f(file){}
    void buildGUI();
    virtual ~view_file_base() = 0;
private:
    void build_buttons();
protected:
    virtual bool check() const; //controlla se i campi inseriti sono validi - virtual anche se non utilizzato per poterlo estendere in futuro, aggiungendo controlli a nuove classi
    virtual void edit() const; //converte da QString ai tipi corretti e modifica i campi dell'oggetto, NON CONTROLLA
    virtual void build_field(); //costruisce i campi per l'oggetto, senza i tasti ok/annulla

    file_base* f;
    QFormLayout* layout;
    QPushButton* bNo;
    QPushButton* bOk;

    //file_base
    QLineEdit* name;
    QLineEdit* realExtension;
    QLineEdit* link;
    QLineEdit* size;
    QLineEdit* description;

public slots:
    void checkAndEdit();
    void rejectedits();
signals:
    //da mandare a addeditfile per signal allo status
    void reject();      //modifiche annullate -> chiamerò il reject in addeditfile
    void accept();    //modifiche confermate -> accept in addeditfile
};

#endif // VIEW_FILE_BASE_H
