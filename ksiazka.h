#ifndef KSIAZKA_H_INCLUDED
#define KSIAZKA_H_INCLUDED
#include "publikacja.h"


using namespace std;


class Ksiazka: public Publikacja
{
protected:
    string autor;
public:
    Ksiazka(string tytul="bez_tytulu", string gatunek="bez_gatunku", string autor="brak_autora"): Publikacja(tytul,gatunek), autor(autor)
    {

    };
    ~Ksiazka()
    {
    };

    void ustaw_autora()
    {
        cout<<"Autor: ";
        cin>>autor;
    }

    void wyswietl()
    {
        cout<<"\""<<tytul<<"\", "<<autor;
    }

    string jaki_autor()
    {
        return autor;
    }

    string jaki_tytul()
    {
        return tytul;
    }
};


#endif // KSIAZKA_H_INCLUDED
