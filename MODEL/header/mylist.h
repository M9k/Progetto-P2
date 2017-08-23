#ifndef MYLIST_H
#define MYLIST_H

#include <QString>
#include <string>


//classe templetizzata astratta, come base per le altre liste
template<class T, class C> //T tipo del contenitore, C oggetto contenuto
class mylist{
protected:
    T list;
    void clean()
    {
        //dealloco gli oggetti
        for(auto ci = list.begin(); ci != list.end(); ++ci)
            delete *ci;
        //svuoto la lista
        list.erase(list.begin(), list.end());
    }
public:
    void removeEnd()
    {
        if(!list.empty())
        {
            delete *(--list.end());
            list.pop_back();
        }
    }

    virtual bool addEnd(C) = 0; //comportamento polimorfico
    bool remove(std::string nome)
    {
        for(auto ci = list.begin(); ci != list.end(); ++ci)
            if((*ci)->getName() == nome)
            {
                delete *ci;
                list.erase(ci);
                return true;
            }
        return false;
    }

    virtual QString getStartLabelXml() const = 0;
    virtual QString getDefaultFile() const = 0;

    void exportXml()
    {
        QFile file(getDefaultFile());
        file.open(QIODevice::WriteOnly);
        QXmlStreamWriter xmlOutput(&file);
        xmlOutput.setAutoFormatting(true);
        xmlOutput.writeStartDocument();

        xmlOutput.writeStartElement(getStartLabelXml());
        for(auto ci = begin(); ci != end(); ++ci)
            (*ci)->exportXml(xmlOutput);
        xmlOutput.writeEndElement();
        xmlOutput.writeEndDocument();
        file.close();
    }

    virtual bool importXml() = 0;

    class const_iterator;
    class iterator{
        friend class const_iterator;
        private:
           typename  T::iterator i;
        public:
            iterator(typename T::iterator it) : i(it) {}
            C operator *() {return *i;}
            iterator& operator ++() {++i; return *this;}
            iterator operator ++(int) {typename T::iterator tmp=i; operator++(); return tmp;}
            iterator& operator = (iterator i2) {i = i2.i; return *this;}
            bool operator ==(iterator i2) {return i == i2.i;}
            bool operator !=(iterator i2) {return i != i2.i;}
    };
    class const_iterator{
        private:
            typename T::const_iterator i;
        public:
            const_iterator(typename T::const_iterator it) : i(it) {}
            //conversione da iteratore a const_iteratore
            const_iterator(iterator it) : i(it.i) {}
            const C operator *() {return *i;}
            const_iterator& operator ++() {++i; return *this;}
            const_iterator operator ++(int) {typename T::const_iterator tmp=i; operator++(); return tmp;}
            const_iterator& operator = (const_iterator i2) {i = i2.i; return *this;}
            bool operator ==(const_iterator i2) {return i == i2.i;}
            bool operator !=(const_iterator i2) {return i != i2.i;}
    };

    iterator begin()
    {
        return list.begin();
    }

    iterator end()
    {
        return list.end();
    }

    mylist() {}
    mylist(const mylist& m) {addFrom(m.list);}
    virtual ~mylist() {removeMemoryAllocations();}
    mylist& operator = (const mylist& m)
    {
        if(&m != this)
        {
            importFrom(m.list);
        }
        return *this;
    }

protected:
    void removeMemoryAllocations() const
    {
        for(auto ci = list.begin(); ci != list.end(); ++ci)
            delete *ci;
    }
    void addFrom(T n)
    {
        for(auto ci = n.begin(); ci != n.end(); ++ci)
            addEnd((*ci)->clone());
    }

    void importFrom(T n)
    {
        clean();
        addFrom(n);
    }
};

#endif // MYLIST_H
