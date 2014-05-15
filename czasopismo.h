#ifndef CZASOPISMO_H_INCLUDED
#define CZASOPISMO_H_INCLUDED

class Czasopismo: public Publikacja
{
protected:
    string data_wyd;
public:
    Czasopismo(string tytul="bez_tytulu", string gatunek="bez_gatunku", string data_wyd="bez_daty"): Publikacja(tytul,gatunek), data_wyd(data_wyd)
    {

    };
    ~Czasopismo(){
    };

    void ustaw_date()
    {
        cout<<"Data wydania: ";
        cin>>data_wyd;
    }

    void wyswietl()
    {
        cout<<"Czasopismo: "<<tytul<<" "<<data_wyd;
    }
};

#endif // CZASOPISMO_H_INCLUDED
