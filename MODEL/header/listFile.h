#ifndef LISTFILE_H
#define LISTFILE_H

#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h> //per le conversioni da string a double/int

#include "file_base.h"

#include <QFile>
#include <QXmlStreamWriter>

#include "common_functions.h"
#include "../header/size_of_file.h"
#include "mylist.h"
#include "factoryfile.h"

template class mylist<std::vector<file_base*>,file_base*>;

class listFile : public mylist<std::vector<file_base*>,file_base*>
{
private:
    static QString startLabel;
    static QString defaultFile;
    QString getStartLabelXml() const;
    QString getDefaultFile() const;

public:
    listFile():mylist() {}
    bool addEnd(file_base* f);

    file_base* getAtIndex(int);
    bool deleteAtIndex(int);

    bool importXml();

    double calcolaGbTot() const;
    void sortByName();
    void sortBySize();
    void sortByNameReverse();
    void sortBySizeReverse();
};



#endif
