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

       void ustaw_autora();
        void wyswietl();
        string jaki_autor();
};

   void Ksiazka:: ustaw_autora()
    {
        cout<<"Autor: ";
        cin>>autor;
    }

    void Ksiazka:: wyswietl()
    {
        cout<<"\""<<tytul<<"\", "<<autor;
    }

string Ksiazka:: jaki_autor()
    {
        return autor;
    }




#endif // KSIAZKA_H_INCLUDED
