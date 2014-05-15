#ifndef PUBLIKACJA_H_INCLUDED
#define PUBLIKACJA_H_INCLUDED
#include <string>

using namespace std;

class Publikacja
{
protected:
    string tytul;
    string gatunek;
    int typ;
    int numer_bib;

public:

    Publikacja(string tytul="brak_tytulu", string gatunek="brak_gatunku",int typ=0):tytul(tytul),gatunek(gatunek),typ(typ)
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

    string jaka_tematyka()
    {
        return gatunek;
    }
};

#endif // PUBLIKACJA_H_INCLUDED
