#include "../../GUI/header/admin_list_users.h"

Admin_list_users::Admin_list_users(listUser& lista_utenti, QWidget* parent) :
    QVBoxLayout(parent), listaUtenti(lista_utenti)
{
    labelUtenti = new QLabel("Utenti:");

    lista = new QListWidget();
    lista->setFixedWidth(180);

    addWidget(labelUtenti);
    addWidget(lista);

    //cerca
    lsearch = new QLabel("Ricerca:");
    search = new QLineEdit();
    addWidget(lsearch);
    addWidget(search);
    connect(search, SIGNAL(textEdited(const QString&)), this, SLOT(filterWidgetList()));

    //carico la lista nella grafica
    reloadList();
    connect(lista, SIGNAL(itemSelectionChanged()), this, SIGNAL(newSelectedItem()));
}

void Admin_list_users::reloadList()
{
    lista->clear();
    for(listUser::const_iterator i = listaUtenti.begin(); i!= listaUtenti.end(); i++)
    {
        QListWidgetItem *riga = new QListWidgetItem;
        riga->setText(QString::fromStdString((*i)->getName()));
        lista->addItem(riga);
    }
    if(search->text() != "")
        filterList();
}
void Admin_list_users::filterList()
{
    int c=0;
    Qt::CaseSensitivity sens = Qt::CaseInsensitive;

    for(listUser::iterator i=listaUtenti.begin(); i!=listaUtenti.end();(++i,++c))
        if((QString::fromStdString((*i)->getName())).indexOf(search->text(), 0, sens) != -1)
                lista->setRowHidden(c, false);
        else
                lista->setRowHidden(c, true);
}

void Admin_list_users::reloadWidgetList()
{
    reloadList();
}

void Admin_list_users::filterWidgetList()
{
    filterList();
}

void Admin_list_users::addUser()
{
    QWidget * q = new QWidget();
    q->setWindowIcon(QIcon(QPixmap(":/dialog")));
    QDialog inputUserDialog(q);
    inputUserDialog.setWindowTitle("Creazione utente");
    QFormLayout layoutUserDialog(&inputUserDialog);
    //drop-down button
    QComboBox listaTipi;
    listaTipi.addItem("Amministratore");
    listaTipi.addItem("Moderatore");
    listaTipi.addItem("Editore");
    listaTipi.addItem("Utente standard");
    layoutUserDialog.addRow(new QLabel("Tipologia:"), &listaTipi);
    //nome
    QLineEdit lenome;
    layoutUserDialog.addRow(new QLabel("Nome:"), &lenome);
    //password
    QLineEdit lepassword;
    layoutUserDialog.addRow(new QLabel("Password:"), &lepassword);
    //button per accettare
    QPushButton bOk("Crea");
    layoutUserDialog.addRow(&bOk);
    connect(&bOk, SIGNAL(clicked()), &inputUserDialog, SLOT(accept()));
    int rit = inputUserDialog.exec();

    if(rit == QDialog::Accepted)
    {
        //prelievo e controllo i dati
        QString tipo = listaTipi.currentText();
        QString nome = lenome.text();
        QString password = lepassword.text();

        if(nome == "" || password == "")
        {
            QMessageBox avviso;
            avviso.setWindowIcon(QIcon(QPixmap(":/error")));
            avviso.setText("Impossibile aggiungere l'utente, i dati erano errati");
            avviso.exec();
            return;
        }
        if(listaUtenti.search(nome.toStdString()))
        {
            QMessageBox avviso;
            avviso.setWindowIcon(QIcon(QPixmap(":/warning")));
            avviso.setText("Impossibile aggiungere l'utente, è già presente nel sistema");
            avviso.exec();
            return;
        }
        user* newUser = 0;
        if(tipo == "Amministratore")
            newUser = new user_admin(nome.toStdString(), password.toStdString());
        if(tipo == "Moderatore")
            newUser = new user_moderator(nome.toStdString(), password.toStdString());
        if(tipo == "Editore")
            newUser = new user_editor(nome.toStdString(), password.toStdString());
        if(tipo == "Utente standard")
            newUser = new user_standard(nome.toStdString(), password.toStdString());

        if(newUser!=0)
        {
            listaUtenti.addEnd(newUser);
            listaUtenti.exportXml();
            lista->addItem(new QListWidgetItem(QString::fromStdString(newUser->getName())));
            lista->setCurrentRow(lista->count()-1);
        }
    }
}

void Admin_list_users::removedSelected()
{
    QWidget * q = new QWidget();
    q->setWindowIcon(QIcon(QPixmap(":/warning")));
    int confirmation = QMessageBox::question(q,"Elimina", "Sei sicuro di voler cancellare l'utente "+lista->currentItem()->text()+"?","Si","No");
    if (confirmation == 0)
    {
        listaUtenti.remove((lista->currentItem()->text()).toStdString());
        lista->takeItem(lista->currentIndex().row());
        listaUtenti.exportXml();
    }
    lista->clearSelection();
}

void Admin_list_users::changeSelectedPassword()
{
    bool accettato;
    QWidget * q = new QWidget();
    q->setWindowIcon(QIcon(QPixmap(":/dialog")));
    QInputDialog* inputDialog;
    inputDialog = new QInputDialog();
    QString newPass = inputDialog->getText(q, "Cambio password", "Inserisci la nuova password:", QLineEdit::Normal, "", &accettato);
    if(accettato)
    {
        listaUtenti.changePassword(listaUtenti.search((lista->currentItem()->text()).toStdString()), newPass.toStdString());
        listaUtenti.exportXml();
    }
}

