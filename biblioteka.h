#ifndef BIBLIOTEKA_H_INCLUDED
#define BIBLIOTEKA_H_INCLUDED

#include "regal.h"

class Biblioteka
{

private:

    vector<Regal> v_reg;

public:

    Biblioteka() {};
    ~Biblioteka() {};
    int czy_istnieje_regal(string nazwa_regalu);


    void push(Regal regal)
    {
        cout<<"\nDodawanie regalu\n";
        v_reg.push_back (regal);
    }

    void wyswietl()
    {
        cout<<endl;
        int max=v_reg.size();
        for (int i=0; i<max;i++)
        {
            cout<<"Regal: "<<i<<".";
            v_reg.at(i).wyswietl_tematyke();
            v_reg.at(i).wyswietl();
            cout<<endl;
        }
    }

    void dodaj_regal(Regal reg)
    {
        string nazwa_regalu;

        nazwa_regalu=reg.jaka_tematyka();

    if (czy_istnieje_regal(nazwa_regalu)==0)
    {
        push(reg);
    }
    }

    Regal szukaj_regal(string nazwa_regalu)
    {
        int i=0;
        int max=v_reg.size();
        int czy_istnieje=0;

        Regal reg;

        if (max)
        do
        {
            cout<<"\ntest: "<<v_reg.at(i).jaka_tematyka()<<" "<<nazwa_regalu;
            if (v_reg.at(i).jaka_tematyka()==nazwa_regalu)
            {
                cout<<"Regal o podanej tematyce istnieje.";
                czy_istnieje=1;
            }
        i++;
        }while (i<max && czy_istnieje==0);
        return reg;
    }

    void dodaj_publikacje(Ksiazka ks)
    {
        Regal reg;

    }

};

    int Biblioteka:: czy_istnieje_regal(string nazwa_regalu)
    {
        int i=0;
        int czy_istnieje=0;
        int max=v_reg.size();

        if (max)
        do
        {
            cout<<"\ntest: "<<v_reg.at(i).jaka_tematyka()<<" "<<nazwa_regalu;
            if (v_reg.at(i).jaka_tematyka()==nazwa_regalu)
            {
                cout<<"Regal o podanej tematyce istnieje. Nie zostal utworzony nowy.";
                czy_istnieje=1;
            }
        i++;
        }while (i<max && czy_istnieje==0);


    return czy_istnieje;
    }



#endif // BIBLIOTEKA_H_INCLUDED
