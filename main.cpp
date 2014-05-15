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

    Ksiazka ks1("Inferno","Sensacja","Dan Brown");//tytul, gatunek, autor
    Ksiazka ks2("Szesc lat pozniej","Sensacja","Harlan Coben");
    Ksiazka ks3("Surely you are joking Mr. Feynman","Biografia", "R.Feynman");

    Czasopismo czas1("National Geographic","Przyrodnicze","15/05/14");
    Czasopismo czas2;
    Czasopismo czas3;

    Regal reg("Sensacja");
    //reg.push(ks1);

    bib.dodaj_regal(reg);
    bib.dodaj_publikacje(ks1);
    bib.dodaj_publikacje(ks2);
    bib.dodaj_publikacje(ks3);

        cout<<"tutaj:\n";
    reg.wyswietl();


    cout<<"Wyswietl:\n";
    bib.wyswietl();
/*

    Czasopismo czas4;
    Czasopismo czas5;
    Czasopismo czas6;

    Regal reg("Przyrodnicze");
    Regal reg2("Przyrodnicze");//nie jest alokowana pamiec na nazwe, bo temetyka juz istnieje
    Regal reg3("Thriller");
    Regal reg4("Kulinarne");

    reg.push(ks1);//dodanie 2 ksiazek i 2 czasopism na regal 0
    reg.push(ks2);
    reg.push(czas1);
    reg.push(czas2);

    reg3.push(ks3);
    reg3.push(ks4);
    reg3.push(czas3);
    reg3.push(czas4);

    bib.dodaj_regal(reg);
    bib.dodaj_regal(reg); //funkcja nic nie robi, bo regal o danej tematyce istnieje
    bib.dodaj_regal(reg2);
    bib.dodaj_regal(reg3);
    bib.dodaj_regal(reg4);



    //w tym momencie w bibliotece nadal jest jeden regal

    bib.dodaj_regal(reg2);



    bib.wyswietl();*/

    /*reg.push(ks);
    reg.push(ks);
    reg.push(ks);

    reg.push(czas);
    reg.push(czas);
    reg.push(czas);*/



    return 0;
}
