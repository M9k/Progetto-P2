#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QScrollArea>
#include <QDesktopServices>
#include <QUrl>
#include <QRadioButton>

#include "../../MODEL/header/listFile.h"
#include "../../MODEL/header/file_base.h"
#include "admin_dialog.h"
#include "addeditfile.h"
#include "../../MODEL/header/factoryfile.h"


class Main_widget : public QWidget
{
    Q_OBJECT
public:
    Main_widget(listUser& listaUser, user* utenteAttuale, QWidget* parent=0);

private:
    QGridLayout* grid;
    listFile listaFile;
    listUser& listaUtenti;
    user* chiamante;
    QPushButton *buttOpenInBrowser, *buttAdd, *buttEdit, *buttDelete;
    QPushButton *buttOpenAdminPanelButton, *buttGbTot, *sortName, *sortSize;
    static bool switchbuttonName, switchbuttonSize;
    Admin_dialog* adminControlPanel;
    QListWidget* lista;
    QLabel *info;
    QScrollArea* infoView;

    QLineEdit* search;
    QHBoxLayout* radioLayout;
    QRadioButton* radioName;
    QRadioButton* radioDesc;
    QRadioButton* radioNameDesc;
    QHBoxLayout* caseLayout;
    QCheckBox* caseSens;
    QLabel* lCerca;
    QLabel* lCase;
    void refreshLista();
    void showInfoSelectedElement();
    void showIfCanEdit();
    void showIfCanDelete();
    void createSearch();
    void refreshInfo();
    void clearSelection();

signals:
    void changeStatus(QString stato);
    void reloginSlot();

private slots:
    void showInfoFile();
    void refreshOpenBrowser();
    void refreshDelete();
    void refreshEdit();
    void openInBrowserSelected();
    void deleteSelected();
    void calculateGbTot();
    void editFile();
    void addFile();
    void filtra();
    void sortByName();
    void sortBySize();
};

#endif
