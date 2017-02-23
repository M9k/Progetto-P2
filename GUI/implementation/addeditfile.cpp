#include "../../GUI/header/addeditfile.h"

AddEditFile::AddEditFile(file_base* file_to_edit, QWidget* parent) : QDialog(parent), f(file_to_edit)
{
    if(f->getName() == "")
        setWindowTitle("Creazione nuovo file");
    else
        setWindowTitle("Modifica file");
    setWindowIcon(QIcon(QPixmap(":/dialog")));

    layout = new QFormLayout(this);
    if(view_file_base* vfb = FactoryAddEdit_View::build(f))
    {
        vfb->buildGUI();
        layout->addWidget(vfb);

        connect(vfb, SIGNAL(accept()), this, SLOT(accept()));
        connect(vfb, SIGNAL(reject()), this, SLOT(reject()));
    }
    else
    {
        //in caso di nullprt
        layout->addRow(new QLabel("L'oggetto passato è invalido, impossibile proseguire"));
        setWindowIcon(QIcon(QPixmap(":/error")));
    }
}
