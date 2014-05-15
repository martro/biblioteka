#ifndef REGAL_H_INCLUDED
#define REGAL_H_INCLUDED
#include "publikacja.h"
#include "ksiazka.h"
#include "czasopismo.h"
#include <vector>



using namespace std;

//template <class Ksiazka, class Czasopismo>
class Regal
{
private:
    vector<Ksiazka> v_ks;
    vector<Czasopismo> v_czas;
public:
    Regal()
    {

    };
    ~Regal(){
    };

    void push(Ksiazka ksiazka)
    {

        cout<<"\ndodawanie ksiazki\n";
        v_ks.push_back (ksiazka);
    }

    void push(Czasopismo czasopismo)
    {

        cout<<"\ndodawanie czasopisma\n";
        v_czas.push_back (czasopismo);
    }

    void wyswietl()
    {
        cout<<endl;
        int max=v_ks.size();
        for (int i=0; i<max;i++)
        {
            cout<<i<<". ";
            v_ks.at(i).wyswietl();
            cout<<endl;
        }

        cout<<endl;
        max=v_czas.size();
        for (int i=0; i<max;i++)
        {
            cout<<i<<". ";
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


};


#endif // REGAL_H_INCLUDED
