#ifndef BIBLIOTEKA_H_INCLUDED
#define BIBLIOTEKA_H_INCLUDED

#include "regal.h"

class Biblioteka
{

private:

    vector<Regal> v_reg;

    int czy_istnieje_regal(string nazwa_regalu);
    int szukaj_regal(string nazwa_regalu);
    void push(Regal regal);

public:

    Biblioteka() {};
    ~Biblioteka() {};

    void dodaj_publikacje(Ksiazka ks);
    void dodaj_publikacje(Czasopismo czas);
    void dodaj_regal(Regal reg);
    void wyswietl();
};

    void Biblioteka:: push(Regal regal)
    {
        cout<<"\nDodawanie regalu\n";
        v_reg.push_back (regal);
    }

    void Biblioteka:: wyswietl()
    {
        cout<<endl;
        int max=v_reg.size();
        for (int i=0; i<max; i++)
        {
            cout<<"___________________________";
            cout<<"\nRegal: "<<i<<". ";
            v_reg.at(i).wyswietl_tematyke();
            v_reg.at(i).wyswietl();
            cout<<endl;
        }
    }

    void Biblioteka:: dodaj_regal(Regal reg)
    {
        string nazwa_regalu;

        nazwa_regalu=reg.jaka_tematyka();

        if (czy_istnieje_regal(nazwa_regalu)==0)
        {
            push(reg);
        }
    }

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
        }
        while (i<max && czy_istnieje==0);


    return czy_istnieje;
}

    int Biblioteka:: szukaj_regal(string nazwa_regalu)
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
            }
            while (i<max && czy_istnieje==0);

        i--;

        if (czy_istnieje==0)
            i=-1;
        return i;
    }

void Biblioteka:: dodaj_publikacje(Ksiazka ks)
    {
        Regal reg(ks.jaka_tematyka());
        int poz;

        poz=szukaj_regal(ks.jaka_tematyka());

        if (poz==-1)
        {
            reg.push(ks);
            push(reg);
        }

        if (poz>=0)
            v_reg.at(poz).push(ks);
    }

void Biblioteka:: dodaj_publikacje(Czasopismo czas)
{
    Regal reg(czas.jaka_tematyka());
    int poz;

    poz=szukaj_regal(czas.jaka_tematyka());

    if (poz==-1)
    {
        reg.push(czas);
        push(reg);
    }

    if (poz>=0)
        v_reg.at(poz).push(czas);
}

#endif // BIBLIOTEKA_H_INCLUDED
