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
        numer_bib=0;

    };
    ~Publikacja()
    {

    };


    void ustaw_tytul()
    {
        cout<<"Tytul: ";
        cin>>tytul;
    }

    void ustaw_nr_bib(int numer_bib)
    {
        this->numer_bib=numer_bib;
    }
    virtual void wyswietl()
    {
        cout<<"\""<<tytul<<"\", "<<numer_bib;
    }

    string jaka_tematyka()
    {
        return gatunek;
    }

    string jaki_tytul()
    {
        return tytul;
    }

    void ustaw_typ(int typ)
    {
        this->typ=typ;
    }
    int jaki_typ()
    {
        return typ;
    }

    int jaki_numer_bib()
    {
        return numer_bib;
    }

};

#endif // PUBLIKACJA_H_INCLUDED
