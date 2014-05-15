#include <iostream>
#include "publikacja.h"
#include "ksiazka.h"
#include "regal.h"
#include "czasopismo.h"

using namespace std;


int main()
{
    Ksiazka ks;

    Czasopismo czas;

    ks.ustaw_tytul();
    ks.ustaw_autora();
    ks.wyswietl();
    cout<<endl;
    czas.ustaw_tytul();
    czas.ustaw_date();
    czas.wyswietl();


    Regal reg;

    reg.push(ks);
    reg.push(ks);
    reg.push(ks);
    reg.push(ks);

    reg.wyswietl();

    return 0;
}
