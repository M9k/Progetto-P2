#include "../../GUI/header/main_widget.h"

Main_widget::Main_widget(listUser& listaUser, user* utenteAttuale, QWidget* parent):
    QWidget(parent), listaUtenti(listaUser), chiamante(utenteAttuale)
{

    listaFile.importXml();

    grid = new QGridLayout();
    setLayout(grid);

    //ADMIN
    if(chiamante->isAdmin())
    {
        buttOpenAdminPanelButton = new QPushButton("Apri il pannello admin");
        buttOpenAdminPanelButton->setFixedSize(200 ,25);
        adminControlPanel = new Admin_dialog(listaUtenti);
        connect(buttOpenAdminPanelButton, SIGNAL(clicked()), adminControlPanel, SLOT(show()));

        grid->addWidget(buttOpenAdminPanelButton,9,0);
    }
    //LISTA
    lista = new QListWidget();
    grid->addWidget(lista,0,1,7,1);

    infoView = new QScrollArea;
    info = new QLabel();
    infoView->setWidget(info);
    info->setText("Nessun oggetto selezionato.");
    info->setFixedWidth(178);
    info->setWordWrap(true);

    infoView->setFixedWidth(200);
    infoView->setFixedHeight(200);
    grid->addWidget(infoView,0,0);
    //TASTI
    buttOpenInBrowser = new QPushButton("Apri nel browser");
    grid->addWidget(buttOpenInBrowser,1,0);
    buttOpenInBrowser->setDisabled(true);
    buttAdd = new QPushButton("Aggiungi un file");
    grid->addWidget(buttAdd,2,0);
    if(!chiamante->canItemAdd())
        buttAdd->setDisabled(true); //scelta progettuale - lo lascio visibile ma disabilitato
    buttEdit = new QPushButton("Modifica il file");
    grid->addWidget(buttEdit,3,0);
    buttEdit->setDisabled(true);
    buttDelete = new QPushButton("Elimina il file");
    grid->addWidget(buttDelete,4,0);
    buttDelete->setDisabled(true);
    buttGbTot = new QPushButton("Calcola GB totali");
    grid->addWidget(buttGbTot,5,0);
    sortName = new QPushButton("Riordina per nome");
    grid->addWidget(sortName,6,0);
    sortSize = new QPushButton("Riordina per dimensione");
    grid->addWidget(sortSize,7,0);

    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(showInfoFile()));
    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(refreshOpenBrowser()));
    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(refreshEdit()));
    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(refreshDelete()));
    connect(buttOpenInBrowser, SIGNAL(clicked()), this, SLOT(openInBrowserSelected()));
    connect(lista, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(openInBrowserSelected()));
    connect(buttDelete, SIGNAL(clicked()), this, SLOT(deleteSelected()));
    connect(buttGbTot, SIGNAL(clicked()), this, SLOT(calculateGbTot()));
    connect(buttAdd, SIGNAL(clicked()), this, SLOT(addFile()));
    connect(buttEdit, SIGNAL(clicked()), this, SLOT(editFile()));
    connect(sortName, SIGNAL(clicked()), this, SLOT(sortByName()));
    connect(sortSize, SIGNAL(clicked()), this, SLOT(sortBySize()));

    createSearch();

    //carico i file
    refreshLista();
}

void Main_widget::refreshLista()
{
    lista->clear();
    for(listFile::iterator i=listaFile.begin(); i!=listaFile.end();i++)
    {
        QListWidgetItem *riga = new QListWidgetItem;
        riga->setText(QString::fromStdString((*i)->getName()));
        riga->setBackgroundColor(QColor((*i)->getColor().r, (*i)->getColor().g,(*i)->getColor().b));
        lista->addItem(riga);
    }
    //se c'è un file selezionato ne mostra la descrizione
    showInfoFile();
    emit filtra();
}

void Main_widget::createSearch()
{
    lCerca = new QLabel("Cerca:");
    lCerca->setMaximumHeight(18);
    lCerca->setMinimumHeight(18);
    grid->addWidget(lCerca,7,1);
    search = new QLineEdit();
    grid->addWidget(search,8,1);
    radioLayout = new QHBoxLayout();
    radioName = new QRadioButton("Nel nome");
    radioName->setChecked(true);
    radioDesc = new QRadioButton("Nella descrizione");
    radioNameDesc = new QRadioButton("Entrambi");
    radioLayout->addSpacing(8);
    radioLayout->addWidget(radioName);
    radioLayout->addWidget(radioDesc);
    radioLayout->addWidget(radioNameDesc);
    grid->addLayout(radioLayout,9,1);
    caseLayout = new QHBoxLayout();
    lCase = new QLabel("Case sensitive: ");
    caseSens = new QCheckBox();
    caseSens->setChecked(false);
    caseLayout->addWidget(lCase);
    caseLayout->addWidget(caseSens,1);
    caseLayout->setAlignment(caseSens, Qt::AlignLeft);
    caseLayout->addSpacing(8);
    grid->addLayout(caseLayout,10,1);

    connect(search, SIGNAL(textEdited(const QString&)), this, SLOT(filtra()));
    connect(radioName, SIGNAL(clicked()), this, SLOT(filtra()));
    connect(radioDesc, SIGNAL(clicked()), this, SLOT(filtra()));
    connect(radioNameDesc, SIGNAL(clicked()), this, SLOT(filtra()));
    connect(caseSens, SIGNAL(clicked()), this, SLOT(filtra()));
}
void Main_widget::refreshInfo()
{
    info->setText(QString::fromStdString((listaFile.getAtIndex(lista->currentRow()))->getInfo()));
    info->adjustSize();
}
void Main_widget::showInfoFile()
{
    if(lista->currentRow() >=0)
        refreshInfo();
}

void Main_widget::refreshOpenBrowser()
{
    buttOpenInBrowser->setDisabled(false);
}

void Main_widget::refreshDelete()
{
    if(chiamante->canItemDelete() || (listaFile.getAtIndex(lista->currentRow())->getCreatorName() == chiamante->getName()))
        buttDelete->setDisabled(false);
    else
        buttDelete->setDisabled(true);
}

void Main_widget::refreshEdit()
{
    if(chiamante->canItemEdit() || (listaFile.getAtIndex(lista->currentRow())->getCreatorName() == chiamante->getName()))
        buttEdit->setDisabled(false);
    else
        buttEdit->setDisabled(true);
}

void Main_widget::openInBrowserSelected()
{
    QString link = QString::fromStdString(listaFile.getAtIndex(lista->currentRow())->getLink());
    //se manca www lo aggiusto, ad esempio google.com -> www.google.com
    if(link.indexOf("www",0, Qt::CaseInsensitive) < 0) //i browser non sempre accettano gli indirizzi senza www, ma li accettano senza http o https
    {
        if(link.left(1) != ".")
            link = "www." + link;
        else
            link = "www" + link;
    }
    QDesktopServices::openUrl(QUrl(link));
    emit changeStatus("Link aperto con successo");
}

void Main_widget::deleteSelected()
{
    int confirmation = QMessageBox::question(this, "Elimina", "Sei sicuro di voler cancellare il file "+lista->currentItem()->text()+"?", "Si", "No");
    if (confirmation == 0)
    {
        listaFile.deleteAtIndex(lista->currentRow());
        lista->takeItem(lista->currentIndex().row());
        listaFile.exportXml();
        clearSelection();
        emit changeStatus("File eliminato con successo");
    }
}

void Main_widget::calculateGbTot()
{
    QMessageBox msgInfo;
    msgInfo.setWindowIcon(QIcon(QPixmap(":/info")));
    msgInfo.setWindowTitle("Dimensione dei file");
    msgInfo.setText("La dimensione complessiva dell'archivio è di "+QString::number(listaFile.calcolaGbTot(),'f',2)+" Gbyte");
    emit changeStatus("Dimensione totale: "+QString::number(listaFile.calcolaGbTot(),'f',2)+" Gbyte");
    msgInfo.exec();
}

void Main_widget::editFile()
{
    int tmpPos = lista->currentRow();
    file_base* f = listaFile.getAtIndex(lista->currentRow());
    //chiama la modifica
    AddEditFile* aef = new AddEditFile(f);
    int ris = aef->exec();
    if(ris == QDialog::Accepted)
    {
        listaFile.exportXml();
        lista->item(lista->currentRow())->setText(QString::fromStdString(f->getName()));
        emit changeStatus("Modifiche apportate con successo");
        refreshInfo();
    }
    else
        emit changeStatus("Modifiche ignorate");
    lista->setCurrentRow(tmpPos);
}

void Main_widget::addFile()
{
    int tmpPos = lista->currentRow();
    QStringList listaTipi;
    listaTipi << "Audio";
    listaTipi << "Video";
    listaTipi << "Contenitore video";
    listaTipi << "Testo semplice";
    listaTipi << "Epub";
    listaTipi << "File generico";

    QInputDialog* inputDialog;
    inputDialog = new QInputDialog();
    bool accettato = false;
    QString tipo = inputDialog->getItem(this, QString("Selezione del tipo di file"), QString("Tipo del file che si vuole creare:"),
                                               listaTipi, 0, true, &accettato);
    if(accettato)
    {
        file_base* f=FactoryFile::build(tipo, chiamante->getName());

        if(f!=nullptr)
        {
            //chiama la modifica
            AddEditFile* aef = new AddEditFile(f);
            aef->exec();
            //ricontrollo nuovamente che i dati siano sufficenti e implicitamente controllo anche se è stato accettato
            if(f->getName()!="" && f->getRealExtension()!="" && f->getLink()!="" && f->getSize()!=0)
            {
                listaFile.addEnd(f);
                listaFile.exportXml();
                lista->addItem(new QListWidgetItem(QString::fromStdString(f->getName())));
                lista->setCurrentRow(lista->count()-1);
                emit changeStatus("File aggiunto con successo");
            }
            else
            {
                lista->setCurrentRow(tmpPos);
                emit changeStatus("File non inserito");
            }
        }
        else
        {
            //nel caso sia inserito un tipo non presente nella lista
            QMessageBox msgErr;
            msgErr.setWindowTitle("Errore!");
            msgErr.setText("Il tipo inserito è invalido.");
            msgErr.setWindowIcon(QIcon(QPixmap(":/error")));
            msgErr.exec();
            lista->setCurrentRow(tmpPos);
            emit changeStatus("Errore durante la creazione del file");
        }

    }
    else
        emit changeStatus("File non inserito");
}

void Main_widget::filtra()
{
    int c=0;

    Qt::CaseSensitivity sens;
    if(caseSens->isChecked())
        sens =  Qt::CaseSensitive;
    else
        sens = Qt::CaseInsensitive;

    for(listFile::iterator i=listaFile.begin(); i!=listaFile.end();(++i,++c))
    {
        if(radioName->isChecked())
        {
            if((QString::fromStdString((*i)->getName())).indexOf(search->text(), 0, sens) != -1)
                lista->setRowHidden(c, false);
            else
                lista->setRowHidden(c, true);
        }
        if(radioDesc->isChecked())
        {
            if((QString::fromStdString((*i)->getDescription())).indexOf(search->text(), 0, sens) != -1)
                lista->setRowHidden(c, false);
            else
                lista->setRowHidden(c, true);
        }
        if(radioNameDesc->isChecked())
        {
            if((QString::fromStdString((*i)->getName())).indexOf(search->text()) != -1 ||
                (QString::fromStdString((*i)->getDescription())).indexOf(search->text(), 0, sens) != -1)
                lista->setRowHidden(c, false);
            else
                lista->setRowHidden(c, true);
        }
    }
}

void Main_widget::clearSelection()
{
    lista->clearSelection();
    buttOpenInBrowser->setDisabled(true);
    buttDelete->setDisabled(true);
    buttEdit->setDisabled(true);
    info->setText("Nessun oggetto selezionato.");
    info->adjustSize();
}

bool Main_widget::switchbuttonName = false;
bool Main_widget::switchbuttonSize = false;

void Main_widget::sortByName()
{
    if(!switchbuttonName)
    {
        listaFile.sortByName();
        switchbuttonName = true;
        switchbuttonSize = false;
        emit changeStatus("Ordinato in modalità ascendente per nome");
    }
    else
    {
        listaFile.sortByNameReverse();
        switchbuttonName = false;
        emit changeStatus("Ordinato in modalità discendente per nome");
    }
    listaFile.exportXml();
    refreshLista();
    clearSelection();
}

void Main_widget::sortBySize()
{
    if(!switchbuttonSize)
    {
        listaFile.sortBySizeReverse();
        switchbuttonSize = true;
        switchbuttonName = false;
        emit changeStatus("Ordinato in modalità discendente per dimensione");
    }
    else
    {
        listaFile.sortBySize();
        switchbuttonSize = false;
        emit changeStatus("Ordinato in modalità ascendente per dimensione");
    }
    listaFile.exportXml();
    refreshLista();
    clearSelection();
}
