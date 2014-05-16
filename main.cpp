#include <iostream>
#include "publikacja.h"
#include "ksiazka.h"
#include "regal.h"
#include "czasopismo.h"
#include "biblioteka.h"

using namespace std;


int main()
{
    Biblioteka bib;

    bib.init();

    Ksiazka ks1("Inferno","Sensacja","Dan Brown");//tytul, gatunek, autor
    Ksiazka ks2("Szesc lat pozniej","Sensacja","Harlan Coben");
    Ksiazka ks3("Surely you are joking Mr. Feynman","Biografia", "R.Feynman");

    Czasopismo czas1("National Geographic","Przyrodnicze","15/05/14");
    Czasopismo czas2("Zbrodnie w ciemnosci", "Sensacja","01/01/14");
    Czasopismo czas3;

    bib.dodaj_publikacje(czas1);
    bib.dodaj_publikacje(ks1);
    bib.dodaj_publikacje(ks2);
    bib.dodaj_publikacje(ks3);

    bib.dodaj_publikacje(czas2);

    bib.wyswietl();

    return 0;
}
