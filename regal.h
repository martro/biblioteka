#ifndef REGAL_H_INCLUDED
#define REGAL_H_INCLUDED
#include "ksiazka.h"
#include "czasopismo.h"
#include <vector>



using namespace std;

//template <class Ksiazka, class Czasopismo>
class Regal
{
private:
    vector<Ksiazka> ks;
    vector<Czasopismo> czas;
public:
    Regal()
    {

    };
    ~Regal(){
    };
    void push(Ksiazka)
    {
        cout<<"dodawanie ksiazki";
    }
};


#endif // REGAL_H_INCLUDED
