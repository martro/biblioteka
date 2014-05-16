#ifndef REGAL_H_INCLUDED
#define REGAL_H_INCLUDED
#include "publikacja.h"
#include "ksiazka.h"
#include "czasopismo.h"
#include <vector>



using namespace std;


class Regal
{
private:
    vector<Ksiazka> v_ks;
    vector<Czasopismo> v_czas;

    string tematyka;




public:
    Regal(string tematyka="brak_tematyki"):tematyka(tematyka)
    {
        this->tematyka=tematyka;
    };
    ~Regal()
    {
    };


    void wyswietl_tematyke();
    void wyswietl();
    void wyswietl(Ksiazka);
    void wyswietl(Czasopismo);
    string jaka_tematyka();

    void push(Ksiazka ksiazka);
    void push(Czasopismo czasopismo);
    void pop_ks(int poz);
    void pop_czas(int poz);
    int znajdz_ks(int numer_bib);
    int znajdz_czas(int numer_bib);




};

void Regal:: push(Ksiazka ksiazka)
{
    if (this->jaka_tematyka()==ksiazka.jaka_tematyka())
        v_ks.push_back (ksiazka);
}

void Regal:: push(Czasopismo czasopismo)
{
    if (this->jaka_tematyka()==czasopismo.jaka_tematyka())
        v_czas.push_back (czasopismo);
}

int Regal:: znajdz_ks(int numer_bib)
{
    int czy_istnieje=0;
    int max=v_ks.size();
    int i=0;

    if (max)
        do
        {
            if (v_ks.at(i).jaki_numer_bib()==numer_bib)
            {
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

int Regal:: znajdz_czas(int numer_bib)
{
    int czy_istnieje=0;
    int max=v_czas.size();
    int i=0;

    if (max)
        do
        {
            if (v_czas.at(i).jaki_numer_bib()==numer_bib)
            {
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

void Regal:: pop_ks(int poz)
{
    v_ks.erase(v_ks.begin()+poz);
}
void Regal:: pop_czas(int poz)
{
    v_czas.erase(v_czas.begin()+poz);
}

void Regal:: wyswietl_tematyke()
{
    cout<<tematyka;
}

void Regal:: wyswietl()
{
    int max=v_ks.size();

    if(max)
        cout<<endl<<"\nKsiazki: \n";

    for (int i=0; i<max; i++)
    {
        cout<<endl<<i<<". ";
        v_ks.at(i).wyswietl();
    }


    max=v_czas.size();
    if(max)
        cout<<endl<<"\nCzasopisma: \n";

    for (int i=0; i<max; i++)
    {
        cout<<endl<<i<<". ";
        v_czas.at(i).wyswietl();
    }
}

void Regal:: wyswietl(Ksiazka)
{
    cout<<endl;
    int max=v_ks.size();
    for (int i=0; i<max; i++)
    {
        cout<<i<<". ";
        v_ks.at(i).wyswietl();
        cout<<endl;
    }
}

void Regal:: wyswietl(Czasopismo)
{
    cout<<endl;
    int max=v_czas.size();
    for (int i=0; i<max; i++)
    {
        cout<<i<<". ";
        v_czas.at(i).wyswietl();
        cout<<endl;
    }
}

string Regal:: jaka_tematyka()
{
    return this->tematyka;
}



#endif // REGAL_H_INCLUDED
