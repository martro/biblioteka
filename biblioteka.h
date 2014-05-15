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
            v_reg.at(i).wyswietl();
            cout<<endl;
        }
    }

};


#endif // BIBLIOTEKA_H_INCLUDED
