#ifndef PUBLIKACJA_H_INCLUDED
#define PUBLIKACJA_H_INCLUDED
#include <string>

using namespace std;

class Publikacja
{
protected:
    string tytul;
    int typ;

public:

    Publikacja(string tytul="aaa", int typ=0):tytul(tytul),typ(typ)
    {

    };
    ~Publikacja()
    {

    };


    void ustaw_tytul()
    {
        cout<<"Tytul: ";
        cin>>tytul;
    }
    virtual void wyswietl()
    {
        cout<<tytul;
    }
};

#endif // PUBLIKACJA_H_INCLUDED
