#ifndef PUBLIKACJA_H_INCLUDED
#define PUBLIKACJA_H_INCLUDED
#include <string>

using namespace std;

class Publikacja
{
protected:
    string tytul;
    int typ;
    int numer_bib;

public:

    Publikacja(string tytul="brak_tytulu", int typ=0):tytul(tytul),typ(typ)
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

    void generuj_nr_bib()
    {
        cout<<"Wygenerowany numer biblioteczny: "<<numer_bib;
    }
    virtual void wyswietl()
    {
        cout<<tytul;
    }
};

#endif // PUBLIKACJA_H_INCLUDED
