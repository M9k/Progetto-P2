#include "../header/listFile.h"

QString listFile::startLabel = "FILE";
QString listFile::defaultFile = "filedata.xml";

QString listFile::getStartLabelXml() const
{
    return startLabel;
}
QString listFile::getDefaultFile() const
{
    return defaultFile;
}

bool listFile::addEnd(file_base* f)
{
    list.push_back(f->clone());
    return true; //in questo contesto non rifiuto mai l'inserimento
}

file_base* listFile::getAtIndex(int i)
{
    return list[i];
}

bool listFile::deleteAtIndex(int i)
{
    if(static_cast<std::vector<file_base*>::size_type>(i) > list.size())
        return false;
    list.erase(list.begin() + i);
    return true;
}

bool listFile::importXml()
{
    clean();
    bool c=false;

    QFile file(getDefaultFile());
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QXmlStreamReader xmlInput(&file);

        while(xmlInput.readNextStartElement()) {
            if(xmlInput.name() == getStartLabelXml()){
                while(xmlInput.readNextStartElement())
                {
                    //legge il nome della classe
                    std::string classname = (xmlInput.name().toString()).toStdString();

                    //poco estendibile, ma non posso fare altrimenti senza refactoring
                    file_base* f = 0;
                    try
                    {

                        f = FactoryFile::buildWithXmlTag(classname, xmlInput);

                        if(f)
                        {
                            addEnd(f);
                            delete f;
                            c = true;
                        }
                        //porta il puntatore all'elemento successivo
                        xmlInput.skipCurrentElement();
                    }
                    catch(unexpected_tag e)
                    {
                        //salta al prossimo elemento
                        while (!xmlInput.isEndElement() || xmlInput.name() != QString::fromStdString(classname))
                            xmlInput.readNext();
                    }
               }
            }
        }
    }
    file.close();
    return c;
}

double listFile::calcolaGbTot() const
{
    double somma=0;
    for(std::vector<file_base*>::const_iterator i=list.begin(); i!=list.end() ;++i)
        somma+=((*i)->getSize()).getGByte();
    return somma;
}

void listFile::sortBySize()
{
    //lambda function
    std::sort(list.begin(), list.end(), [](const file_base* a, const file_base* b) { return a->getSize() < b->getSize(); });
}

void listFile::sortByName()
{
    std::sort(list.begin(), list.end(), [](const file_base* a, const file_base* b) { return a->getName() < b->getName(); });
}
void listFile::sortBySizeReverse()
{
    std::sort(list.begin(), list.end(), [](const file_base* a, const file_base* b) { return a->getSize() > b->getSize(); });
}

void listFile::sortByNameReverse()
{
    std::sort(list.begin(), list.end(), [](const file_base* a, const file_base* b) { return a->getName() > b->getName(); });
}
