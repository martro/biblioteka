#ifndef BIBLIOTEKA_H_INCLUDED
#define BIBLIOTEKA_H_INCLUDED

#include <string>
#include <sstream>
#include "regal.h"
#include "pugixml.hpp"

using namespace pugi;
class Biblioteka
{

private:

    vector<Regal> v_reg;
    vector<Publikacja> v_pub;

    string adres;

    int czy_istnieje_regal(string nazwa_regalu);
    int szukaj_regal(string nazwa_regalu);
    void push(Regal regal);
    void usun_z_regalu();

    int il_publikacji;

public:

    Biblioteka() {};
    ~Biblioteka() {};

    void dodaj_publikacje(Ksiazka ks);
    void dodaj_publikacje(Ksiazka ks,int numer_bib);
    void dodaj_publikacje(Czasopismo czas);
    void dodaj_publikacje(Czasopismo czas,int numer_bib);
    void dodaj_regal(Regal reg);
    void wyswietl_regaly();
    void wyswietl_index_pub();
    int ile_pub();
    void ustaw_il_pub(int il);
    void init();
    void zwieksz_il_pub();
    void usun_publikacje(int numer_bib);
    void szukaj_tytul(string tytul);
    int znajdz_publikacje(int numer_pub);
    void edytuj_publikacje(int numer_bib);
    void zapisz();
    int  wczytaj();
    int ile_regalow();
    string jaki_adres();
    void ustaw_adres(string adres);
};

void Biblioteka:: push(Regal regal)
{
    v_reg.push_back (regal);
}

void Biblioteka:: wyswietl_regaly()
{
    cout<<endl;
    int max=v_reg.size();
    for (int i=0; i<max; i++)
    {
        cout<<"\n__________________________";
        cout<<"\nRegal: "<<i<<". ";
        v_reg.at(i).wyswietl_tematyke();
        v_reg.at(i).wyswietl();
    }
}

void Biblioteka:: szukaj_tytul(string tytul)
{
    int max=v_pub.size();

    for (int i=0; i<max; i++)
    {
        //cout<<"temat: "<<v_pub.at(i).jaki_tytul();
        if (int(v_pub.at(i).jaki_tytul().find(tytul))!=-1)
        {
            cout<<"\n"<<i<<". ";
            cout<<"[";
            if (v_pub.at(i).jaki_typ()==0)
                cout<<"Ksiazka";
            if (v_pub.at(i).jaki_typ()==1)
                cout<<"Czasopismo";
            cout<<"] ";
            v_pub.at(i).wyswietl();
        }
    }
}

void Biblioteka:: wyswietl_index_pub()
{
    cout<<"\n\nWszystkie publikacje:\n";

    int max=v_pub.size();
    for (int i=0; i<max; i++)
    {
        cout<<"\n"<<i<<". ";
        cout<<"[";
        if (v_pub.at(i).jaki_typ()==0)
            cout<<"Ksiazka";
        if (v_pub.at(i).jaki_typ()==1)
            cout<<"Czasopismo";
        cout<<"] ";
        v_pub.at(i).wyswietl();
    }
}

void Biblioteka:: dodaj_regal(Regal reg)
{
    string nazwa_regalu;

    nazwa_regalu=reg.jaka_tematyka();

    if (czy_istnieje_regal(nazwa_regalu)==0)
    {
        push(reg);
    }
}

int Biblioteka:: czy_istnieje_regal(string nazwa_regalu)
{
    int i=0;
    int czy_istnieje=0;
    int max=v_reg.size();

    if (max)
        do
        {
            if (v_reg.at(i).jaka_tematyka()==nazwa_regalu)
            {
                cout<<"\nRegal o podanej tematyce istnieje. Nie zostal utworzony nowy.";
                czy_istnieje=1;
            }
            i++;
        }
        while (i<max && czy_istnieje==0);


    return czy_istnieje;
}

int Biblioteka:: szukaj_regal(string nazwa_regalu)
{
    int i=0;
    int max=v_reg.size();
    int czy_istnieje=0;

    Regal reg;

    if (max)
        do
        {
            if (v_reg.at(i).jaka_tematyka()==nazwa_regalu)
            {
                czy_istnieje=1;
            }
            i++;
        }
        while (i<max && czy_istnieje==0);

    i--;

    if (czy_istnieje==0)
        i=-1;
    return i;
}

void Biblioteka:: edytuj_publikacje(int numer_bib)
{
    int max=this->ile_pub();
    string tematyka;
    string tytul;
    string autor;
    string data_wyd;

    int miejsce_na_polce,numer_regalu;

    int poz=znajdz_publikacje(numer_bib);

    cout<<"\nNowy tytul (poprz: "<<this->v_pub.at(poz).jaki_tytul()<<": ";
    getline (cin,tytul);

    tematyka=v_pub.at(poz).jaka_tematyka();


    numer_regalu=szukaj_regal(tematyka);
    miejsce_na_polce=v_reg.at(numer_regalu).znajdz_ks(numer_bib);

    if (miejsce_na_polce>=0)
    {
        cout<<"\nNowy autor (poprz: "<<this->v_reg.at(numer_regalu).jaki_autor(miejsce_na_polce)<<": ";
        getline (cin,autor);
        v_reg.at(numer_regalu).edytuj_ks(miejsce_na_polce,tytul,autor);
    }

    miejsce_na_polce=v_reg.at(numer_regalu).znajdz_czas(numer_bib);

    if (miejsce_na_polce>=0)
    {
        cout<<"\nNowy autor (poprz: "<<this->v_reg.at(numer_regalu).jaka_data(miejsce_na_polce)<<": ";
        getline (cin,autor);
        v_reg.at(numer_regalu).edytuj_czas(miejsce_na_polce,tytul,data_wyd);
    }

    v_pub.at(poz).ustaw_tytul(tytul);

    if (poz>=0)
    {
        if ((numer_bib>0)&&(numer_bib<=max))
        {

        }
        else cout<<"\nNiepoprawny numer biblioteczny.\n";
    }
}

void Biblioteka:: dodaj_publikacje(Ksiazka ks)
{
    Regal reg(ks.jaka_tematyka());
    Publikacja pub(ks.jaki_tytul(),ks.jaka_tematyka(),ks.jaki_typ());
    int poz;

    poz=szukaj_regal(ks.jaka_tematyka());



    int numer_bib=v_pub.size()+1;
    this->zwieksz_il_pub();
    pub.ustaw_nr_bib(numer_bib);
    ks.ustaw_nr_bib(numer_bib);

    if (poz==-1)
    {
        reg.push(ks);
        push(reg);
    }

    if (poz>=0)
        v_reg.at(poz).push(ks);
    v_pub.push_back(pub);
}

void Biblioteka:: dodaj_publikacje(Ksiazka ks,int numer_bib)
{
    Regal reg(ks.jaka_tematyka());
    Publikacja pub(ks.jaki_tytul(),ks.jaka_tematyka(),ks.jaki_typ());
    int poz;

    poz=szukaj_regal(ks.jaka_tematyka());


    pub.ustaw_nr_bib(numer_bib);
    ks.ustaw_nr_bib(numer_bib);

    if (numer_bib>ile_pub())
    ustaw_il_pub(numer_bib);

    if (poz==-1)
    {
        reg.push(ks);
        push(reg);
    }

    if (poz>=0)
        v_reg.at(poz).push(ks);
    v_pub.push_back(pub);
}

void Biblioteka:: dodaj_publikacje(Czasopismo czas)
{
    Regal reg(czas.jaka_tematyka());
    int poz;
    Publikacja pub(czas.jaki_tytul(),czas.jaka_tematyka(),czas.jaki_typ());

    poz=szukaj_regal(czas.jaka_tematyka());


    int numer_bib=ile_pub()+1;
    this->zwieksz_il_pub();
    pub.ustaw_nr_bib(numer_bib);
    pub.ustaw_typ(1);

    czas.ustaw_nr_bib(numer_bib);

    if (poz==-1)
    {
        reg.push(czas);
        push(reg);
    }

    if (poz>=0)
        v_reg.at(poz).push(czas);
    v_pub.push_back(pub);
}

void Biblioteka:: dodaj_publikacje(Czasopismo czas, int numer_bib)
{
    Regal reg(czas.jaka_tematyka());
    int poz;
    Publikacja pub(czas.jaki_tytul(),czas.jaka_tematyka(),czas.jaki_typ());

    poz=szukaj_regal(czas.jaka_tematyka());


    pub.ustaw_nr_bib(numer_bib);
    pub.ustaw_typ(1);

    if (numer_bib>ile_pub())
    ustaw_il_pub(numer_bib);


    czas.ustaw_nr_bib(numer_bib);

    if (poz==-1)
    {
        reg.push(czas);
        push(reg);
    }

    if (poz>=0)
        v_reg.at(poz).push(czas);
    v_pub.push_back(pub);
}


void Biblioteka:: usun_publikacje(int numer_bib)
{
    int max=this->ile_pub();
    string tematyka;

    int miejsce_na_polce,numer_regalu;

    int poz=znajdz_publikacje(numer_bib);

    if (poz>=0)
    {
    tematyka=v_pub.at(poz).jaka_tematyka();


    numer_regalu=szukaj_regal(tematyka);
    miejsce_na_polce=v_reg.at(numer_regalu).znajdz_ks(numer_bib);

    if (miejsce_na_polce>=0)
        v_reg.at(numer_regalu).pop_ks(miejsce_na_polce);

    miejsce_na_polce=v_reg.at(numer_regalu).znajdz_czas(numer_bib);

    if (miejsce_na_polce>=0)
    {
        v_reg.at(numer_regalu).pop_czas(miejsce_na_polce);
    }
    }

    if (poz>=0)
    {
        if ((numer_bib>0)&&(numer_bib<=max))
        {
            v_pub.erase(v_pub.begin()+poz);
        }
        else cout<<"\nNiepoprawny numer biblioteczny.\n";
    }
}

int Biblioteka:: znajdz_publikacje(int numer_bib)
{
    int max=this->v_pub.size();
    int i=0;
    int czy_istnieje=0;

    do
    {
        if (v_pub.at(i).jaki_numer_bib()==numer_bib)
        {
            czy_istnieje=1;
        }
        i++;
    }
    while (i<max && czy_istnieje==0);
    i--;
    if (czy_istnieje==0)
        i=-1;
    return i;
}

int Biblioteka:: ile_pub()
{
    return il_publikacji;
}

void Biblioteka:: ustaw_il_pub(int il)
{
    this->il_publikacji=il;
}

int Biblioteka:: ile_regalow()
{
    return v_reg.size();
}

void Biblioteka:: zwieksz_il_pub()
{
    il_publikacji++;
}

void Biblioteka:: init()
{
    il_publikacji=0;
}

string Biblioteka:: jaki_adres()
{
    return adres;
}
void Biblioteka:: ustaw_adres(string adres)
{
    this->adres=adres;
}

void Biblioteka::zapisz()
{
    xml_document doc;
    xml_node bib=doc.append_child("Biblioteka");
    bib.append_attribute("Adres")=this->jaki_adres().c_str();

    for (int i=0; i<this->ile_regalow(); i++)
    {
        xml_node regal=bib.append_child("Regal");
        regal.append_attribute("Tematyka")=v_reg.at(i).jaka_tematyka().c_str();

        for(int j=0; j<v_reg.at(i).ile_ks(); j++)
        {
            /*
            string tekst;

            std::stringstream ss;
            ss << 5;
            tekst=ss.str();*/

            xml_node ksiazka=regal.append_child("Ksiazka");
            ksiazka.append_attribute("Tytul")=v_reg.at(i).ksiazka(j).jaki_tytul().c_str();
            ksiazka.append_attribute("Autor")=v_reg.at(i).ksiazka(j).jaki_autor().c_str();
            ksiazka.append_attribute("Numer_biblioteczny")=v_reg.at(i).ksiazka(j).jaki_numer_bib();
        }

        for(int j=0; j<v_reg.at(i).ile_czas(); j++)
        {
            xml_node ksiazka=regal.append_child("Czasopismo");
            ksiazka.append_attribute("Tytul")=v_reg.at(i).czasopismo(j).jaki_tytul().c_str();
            ksiazka.append_attribute("Data_wydania")=v_reg.at(i).czasopismo(j).jaka_data().c_str();
            ksiazka.append_attribute("Numer_biblioteczny")=v_reg.at(i).czasopismo(j).jaki_numer_bib();
        }
    }

    doc.save_file("biblioteka.txt");
}


int Biblioteka::wczytaj()
{
    cout<<"\n\nWCZYTYWANIE ";
    xml_document doc;

    this->v_pub.clear();
    this->v_reg.clear();
    this->ustaw_il_pub(0);

    if (!doc.load_file("biblioteka.txt"))
        return -1;
    xml_node b=doc.child("Biblioteka");
    //cout<<"Biblioteka: ";
    ustaw_adres(b.attribute("Adres").value());

    for(xml_node r=b.child("Regal");r;r=r.next_sibling("Regal"))
    {
        //cout<<"\n\tRegal: " <<r.attribute("Tematyka").value()<<endl;
        for(xml_node k=r.child("Ksiazka");k;k=k.next_sibling("Ksiazka"))
        {
            Ksiazka ks(k.attribute("Tytul").value(),r.attribute("Tematyka").value(),k.attribute("Autor").value());
            //cout<<"\n\t\tKsiazka: "<<k.attribute("Tytul").value()<<" | "<<k.attribute("Autor").value()<<" | ";
            //cout<<"Numer bib.: "<<k.attribute("Numer_biblioteczny").value();

            int numer_bib;

            std::istringstream ss(k.attribute("Numer_biblioteczny").value());
            ss >> numer_bib;

            //cout<<" int: "<<numer_bib;


            dodaj_publikacje(ks,numer_bib);
       }
        for(xml_node c=r.child("Czasopismo");c;c=c.next_sibling("Czasopismo"))
        {
            Czasopismo czas(c.attribute("Tytul").value(),r.attribute("Tematyka").value(),c.attribute("Data_wydania").value());
            //cout<<"\n\t\tCzasopismo: "<<c.attribute("Tytul").value()<<" \""<<c.attribute("Data_wydania").value()<<"\"";
            //cout<<"Numer bib.: "<<c.attribute("Numer_biblioteczny").value();


            int numer_bib;

            std::istringstream ss(c.attribute("Numer_biblioteczny").value());
            ss >> numer_bib;

            dodaj_publikacje(czas,numer_bib);
        }
    }
            cout<<("(zakonczone)\n");
    return 0;
}

#endif // BIBLIOTEKA_H_INCLUDED
