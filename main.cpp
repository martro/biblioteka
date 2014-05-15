#include <iostream>
#include "publikacja.h"
#include "ksiazka.h"
#include "regal.h"
#include "czasopismo.h"
#include "biblioteka.h"

using namespace std;


int main()
{
    Ksiazka ks;

    Czasopismo czas;

    ks.ustaw_tytul();
    ks.ustaw_autora();

    czas.ustaw_date();
    czas.ustaw_tytul();

    Regal reg;

    reg.push(ks);
    reg.push(ks);
    reg.push(ks);

    reg.push(czas);
    reg.push(czas);
    reg.push(czas);

    Biblioteka bib;

    bib.push(reg);
        bib.push(reg);
            bib.push(reg);

    bib.wyswietl();


    return 0;
}
