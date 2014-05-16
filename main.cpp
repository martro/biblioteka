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
    Ksiazka ks4("Inferno2","Sensacja","Dan Brown");
    Ksiazka ks5("Inferno3","Sensacja","Dan Brown");
    Ksiazka ks6("Inferno4","Sensacja","Dan Brown");

    Czasopismo czas1("National Geographic","Przyrodnicze","15/05/14");
    Czasopismo czas2("Zbrodnie w ciemnosci", "Sensacja","01/01/14");
    Czasopismo czas3;

    bib.dodaj_publikacje(czas1);
    bib.dodaj_publikacje(ks1);
    bib.dodaj_publikacje(ks2);
    bib.dodaj_publikacje(ks3);
    bib.dodaj_publikacje(czas2);
    bib.dodaj_publikacje(ks4);
    bib.dodaj_publikacje(ks5);
    bib.dodaj_publikacje(ks6);





    bib.wyswietl_regaly();
    bib.wyswietl_index_pub();
/*
    bib.usun_publikacje(1);
    bib.usun_publikacje(2);
    bib.usun_publikacje(3);
    bib.usun_publikacje(4);
    bib.usun_publikacje(5);
    bib.usun_publikacje(6);
    bib.usun_publikacje(7);
    bib.usun_publikacje(8);*/



    bib.wyswietl_regaly();
    bib.wyswietl_index_pub();

    cout<<"\n\nWyszukiwanie: ";
    bib.szukaj_tytul("Na");

    bib.edytuj_publikacje(4);

    bib.wyswietl_regaly();
    bib.wyswietl_index_pub();



}
