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
    ~Regal(){
    };

    void push(Ksiazka ksiazka)
    {

        cout<<"\ndodawanie ksiazki\n"<<jaka_tematyka()<<"-"<<ksiazka.jaki_autor();
        if (this->jaka_tematyka()==ksiazka.jaka_tematyka())
        {
            v_ks.push_back (ksiazka);
            cout<<"\nDODANO\n";
        }
    }

    void push(Czasopismo czasopismo)
    {

        cout<<"\ndodawanie czasopisma\n";
        v_czas.push_back (czasopismo);
    }

    void wyswietl_tematyke()
    {
        cout<<tematyka;
    }

    void wyswietl()
    {
        int max=v_ks.size();
        cout<<"rozm: "<<max<<". ";
        for (int i=0; i<max;i++)
        {
            cout<<i<<". ddddd";
            v_ks.at(i).wyswietl();
            cout<<endl;
        }

        cout<<"\n___________\n"<<endl;
        max=v_czas.size();
        for (int i=0; i<max;i++)
        {
            cout<<i<<".eeeeeeeeee ";
            v_czas.at(i).wyswietl();
            cout<<endl;
        }
    }

    void wyswietl(Ksiazka)
    {
        cout<<endl;
        int max=v_ks.size();
        for (int i=0; i<max;i++)
        {
            cout<<i<<". ";
            v_ks.at(i).wyswietl();
            cout<<endl;
        }
    }

    void wyswietl(Czasopismo)
    {
        cout<<endl;
        int max=v_czas.size();
        for (int i=0; i<max;i++)
        {
            cout<<i<<". ";
            v_czas.at(i).wyswietl();
            cout<<endl;
        }
    }

    string jaka_tematyka()
    {
        return this->tematyka;
    }


};


#endif // REGAL_H_INCLUDED
