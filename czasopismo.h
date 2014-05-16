#ifndef CZASOPISMO_H_INCLUDED
#define CZASOPISMO_H_INCLUDED

class Czasopismo: public Publikacja
{
protected:
    string data_wyd;
public:
    Czasopismo(string tytul="bez_tytulu", string gatunek="bez_gatunku", string data_wyd="bez_daty"): Publikacja(tytul,gatunek), data_wyd(data_wyd)
    {
        ustaw_typ(1);
    };
    ~Czasopismo()
    {
    };
    void ustaw_date(string data_wyd);
    void wyswietl();
    string jaka_data();
};

void Czasopismo:: ustaw_date(string data_wyd)
{
        cout<<"\nNowa data (poprz: "<<this->jaka_data()<<": ";
        this->data_wyd=data_wyd;
}

void Czasopismo:: wyswietl()
{
    cout<<"\""<<tytul<<"\", "<<data_wyd;
}

string Czasopismo:: jaka_data()
{
    return data_wyd;
}

#endif // CZASOPISMO_H_INCLUDED
