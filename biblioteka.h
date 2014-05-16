#ifndef BIBLIOTEKA_H_INCLUDED
#define BIBLIOTEKA_H_INCLUDED

#include "regal.h"

class Biblioteka
{

private:

    vector<Regal> v_reg;
    vector<Publikacja> v_pub;

    int czy_istnieje_regal(string nazwa_regalu);
    int szukaj_regal(string nazwa_regalu);
    void push(Regal regal);

    int il_publikacji;

public:

    Biblioteka() {};
    ~Biblioteka() {};

    void dodaj_publikacje(Ksiazka ks);
    void dodaj_publikacje(Czasopismo czas);
    void dodaj_regal(Regal reg);
    void wyswietl_regaly();
    void wyswietl_index_pub();
    int ile_pub();
    void init();
    void zwieksz_il_pub();
    void usun_publikacje(int numer_bib);
    int znajdz_publikacje(int numer_pub);
};

void Biblioteka:: push(Regal regal)
{
    cout<<"\nDodawanie regalu\n";
    v_reg.push_back (regal);
}

void Biblioteka:: wyswietl_regaly()
{
    cout<<endl;
    int max=v_reg.size();
    for (int i=0; i<max; i++)
    {
        cout<<"_\n__________________________";
        cout<<"\nRegal: "<<i<<". ";
        v_reg.at(i).wyswietl_tematyke();
        v_reg.at(i).wyswietl();
    }
}

void Biblioteka:: wyswietl_index_pub()
{
    cout<<"\nWszystkie publikacje:\n\n";

    int max=v_pub.size();
    for (int i=0; i<max; i++)
    {
        cout<<"\n"<<i<<". ";
        cout<<"[";
        if (v_pub.at(i).jaki_typ()==0)
            cout<<"Ksiazka";
        if (v_pub.at(i).jaki_typ()==1)
            cout<<"Czasopismo";
        cout<<"] ";
        v_pub.at(i).wyswietl();
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
    Publikacja pub(ks.jaki_tytul(),ks.jaka_tematyka(),ks.jaki_typ());
    int poz;

    poz=szukaj_regal(ks.jaka_tematyka());

    if (poz==-1)
    {
        reg.push(ks);
        push(reg);
    }

    if (poz>=0)
        v_reg.at(poz).push(ks);

    int numer_bib=v_pub.size()+1;
    this->zwieksz_il_pub();
    pub.ustaw_nr_bib(numer_bib);
    v_pub.push_back(pub);
}

void Biblioteka:: dodaj_publikacje(Czasopismo czas)
{
    Regal reg(czas.jaka_tematyka());
    int poz;
    Publikacja pub(czas.jaki_tytul(),czas.jaka_tematyka(),czas.jaki_typ());

    poz=szukaj_regal(czas.jaka_tematyka());

    if (poz==-1)
    {
        reg.push(czas);
        push(reg);
    }

    if (poz>=0)
        v_reg.at(poz).push(czas);

    int numer_bib=v_pub.size()+1;
    this->zwieksz_il_pub();
    pub.ustaw_nr_bib(numer_bib);
    pub.ustaw_typ(1);
    v_pub.push_back(pub);
}

void Biblioteka:: usun_publikacje(int numer_bib)
{
    int max=this->ile_pub();
    int poz=znajdz_publikacje(numer_bib);
    if (poz>=0)
    {
    if ((numer_bib>0)&&(numer_bib<=max))
    {
        v_pub.erase(v_pub.begin()+poz);
    }
    else cout<<"\nNiepoprawny numer biblioteczny.\n";
    }
}

int Biblioteka:: znajdz_publikacje(int numer_bib)
{
    int max=this->ile_pub();
    int i=0;
    int czy_istnieje=0;

        do
        {
            if (v_pub.at(i).jaki_numer_bib()==numer_bib)
            {
                cout<<"Regal o podanej tematyce istnieje. Nie zostal utworzony nowy.";
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

int Biblioteka:: ile_pub()
{
    return il_publikacji;
}

void Biblioteka:: zwieksz_il_pub()
{
    il_publikacji++;
}

void Biblioteka:: init()
{
    il_publikacji=0;
}

#endif // BIBLIOTEKA_H_INCLUDED
