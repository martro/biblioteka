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




};

void Regal:: push(Ksiazka ksiazka)
{

    cout<<"\ndodawanie ksiazki\n"<<jaka_tematyka()<<"-"<<ksiazka.jaki_autor();
    if (this->jaka_tematyka()==ksiazka.jaka_tematyka())
    {
        v_ks.push_back (ksiazka);
        cout<<"\nDODANO\n";
    }
}

void Regal:: push(Czasopismo czasopismo)
{

    cout<<"\ndodawanie czasopisma\n";
    v_czas.push_back (czasopismo);
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
