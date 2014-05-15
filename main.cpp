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

    Ksiazka ks1("aaaaa","Thriller","Przyrodnicze");
    Ksiazka ks2("bbbbb","Bajka","BBBBBB");
    Ksiazka ks3;
    Ksiazka ks4;
    Ksiazka ks5;
    Ksiazka ks6;

    //Regal reg("Przyrodnicze");

    //bib.dodaj_regal(reg);
    bib.dodaj_publikacje(ks1);
    cout<<"Wyswietl:\n";
    bib.wyswietl();
/*
    Czasopismo czas1;
    Czasopismo czas2;
    Czasopismo czas3;
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
