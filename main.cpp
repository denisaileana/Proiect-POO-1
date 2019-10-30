#include <iostream>
#include <math.h>

using namespace std;


class Numar_Complex
{
public:
    Numar_Complex()
    {
        parte_imaginara = 0;
        parte_reala = 0;
    }
    Numar_Complex(double real)
    {
        parte_reala = real;
        parte_imaginara = 0;
    }
    Numar_Complex(double real, double imaginar)
    {
        parte_reala = real;
        parte_imaginara = imaginar;
    }
    Numar_Complex(const Numar_Complex &celalalt)
    {
        parte_reala = celalalt.parte_reala;
        parte_imaginara = celalalt.parte_imaginara;
    }
    ~Numar_Complex()
    {
        // nu fac nimic
    }
    void citire_parte_reala()
    {
        double a;
        cout<<"Introduceti partea reala a numarului complex: ";
        cin>>a;
        parte_reala=a;
    }

    void citire_parte_imaginara()
    {
        double b;
        cout<<"Introduceti partea imaginara a numarului complex: ";
        cin>>b;
        parte_imaginara=b;
    }

    void setare_parte_reala(double real)
    {
        parte_reala = real;
    }
    void setare_parte_imaginara(double imaginar)
    {
        parte_imaginara = imaginar;
    }
    double afisare_parte_reala()
    {
        return parte_reala;
    }
    double afisare_parte_imaginara()
    {
        return parte_imaginara;
    }

    double modul()
    {
        double modulul;
        modulul=sqrt(parte_reala*parte_reala+(parte_imaginara*parte_imaginara));
        return modulul;
    }

    Numar_Complex operator -()
    {
        Numar_Complex rezultat;
        rezultat.parte_reala=-parte_reala;
        rezultat.parte_imaginara=-parte_imaginara;
        return rezultat;
    }
    Numar_Complex operator -(Numar_Complex const &obiect)
    {
        Numar_Complex rezultat;
        rezultat.parte_reala=parte_reala - obiect.parte_reala;
        rezultat.parte_imaginara=parte_imaginara - obiect.parte_imaginara;
        return rezultat;
    }
    Numar_Complex operator + (Numar_Complex const &obiect)
    {
        Numar_Complex rezultat;
        rezultat.parte_reala=parte_reala + obiect.parte_reala;
        rezultat.parte_imaginara=parte_imaginara + obiect.parte_imaginara;
        return rezultat;
    }
    Numar_Complex operator*(double const &numar) {
        Numar_Complex rezultat;
        rezultat.parte_reala=parte_reala * numar;
        rezultat.parte_imaginara=parte_imaginara * numar;
        return rezultat;
    }


    Numar_Complex operator * (Numar_Complex const &obiect)
    {
        Numar_Complex rezultat;
        rezultat.parte_reala=parte_reala * obiect.parte_reala;
        rezultat.parte_imaginara=parte_imaginara * obiect.parte_imaginara;
        return rezultat;
    }

    Numar_Complex operator / (Numar_Complex const &obiect)
    {
        Numar_Complex rezultat;
        rezultat.parte_reala=(parte_reala * obiect.parte_reala + parte_imaginara * obiect.parte_imaginara) / (obiect.parte_reala * obiect.parte_reala + obiect.parte_imaginara * obiect.parte_imaginara);
        rezultat.parte_imaginara=(obiect.parte_reala * parte_imaginara - parte_reala * obiect.parte_imaginara) / (obiect.parte_reala * obiect.parte_reala + obiect.parte_imaginara * obiect.parte_imaginara);
        return rezultat;
    }

    Numar_Complex radical() {
        Numar_Complex rezultat;
        rezultat.parte_reala = 0.5*sqrt(2)*sqrt(sqrt(parte_reala * parte_reala + parte_imaginara * parte_imaginara) + parte_reala);
        rezultat.parte_imaginara = 0.5*sqrt(2)*sqrt(sqrt(parte_reala * parte_reala + parte_imaginara * parte_imaginara) - parte_reala);
        if (parte_imaginara < 0)
        {
            rezultat.parte_imaginara = -rezultat.parte_imaginara;
        }
        return rezultat;
    }

    void afisare()
    {
        if (parte_imaginara == 0)
        {
            cout << parte_reala;
            return;
        }
        if (parte_reala == 0)
        {
            if (parte_imaginara < 0)
            {
                cout << "-i*" << -parte_imaginara;
            }
            else
            {
                cout << "i*" << parte_imaginara;
            }
            return;
        }
        if (parte_imaginara < 0)
        {
            cout << parte_reala << "-i*" << -parte_imaginara;
        }
        else
        {
            cout << parte_reala << "+i*" << parte_imaginara;
        }
    }

    friend ostream & operator<< (ostream &out, const Numar_Complex &numar);
    friend istream & operator>> (istream &in, Numar_Complex &numar);

private:
    double parte_reala;
    double parte_imaginara;


};

ostream & operator << (ostream &out, const Numar_Complex &c)
{
    if (c.parte_imaginara == 0)
        {
            out << c.parte_reala;
            return out;
        }
        if (c.parte_reala == 0)
        {
            if (c.parte_imaginara < 0)
            {
                out << "-i*" << -c.parte_imaginara;
            }
            else
            {
                out << "i*" << c.parte_imaginara;
            }
            return out;
        }
        if (c.parte_imaginara < 0)
        {
            out << c.parte_reala << "-i*" << -c.parte_imaginara;
        }
        else
        {
            out << c.parte_reala << "+i*" << c.parte_imaginara;
        }
    return out;
}

istream & operator >> (istream &in, Numar_Complex &c)
{
    cout<<"Introduceti partea reala a numarului complex: ";
    cin>>c.parte_reala;
    cout<<"Introduceti partea imaginara a numarului complex: ";
    cin>>c.parte_imaginara;
    return in;
}

int main()
{
    cout<<"Se da ecuatia a*z^2 + b*z + c = 0\n";
    Numar_Complex a;
    a.citire_parte_reala();
    a.citire_parte_imaginara();
    cout<<"Numarul complex a este: ";
    a.afisare();
    cout<<"\n";

    Numar_Complex b;
    b.citire_parte_reala();
    b.citire_parte_imaginara();
    cout<<"Numarul complex b este: ";
    b.afisare();
    cout<<"\n";

    Numar_Complex c;
    cin>>c;
    cout<<"Numarul complex c este: "<<c<<"\n";

    Numar_Complex c3= a+b;
    Numar_Complex c4= a*b;
    Numar_Complex c5= a/b;
    cout<<"Suma a+b este: "<<c3<<"\n";
    cout<<"Produsul a*b: "<<c4<<"\n";
    cout<<"Impartirea a/b este: "<<c5<<"\n";
    cout<<"Modulul lui a este: "<<a.modul()<<"\n";
    cout<<"Radicalul lui a este "<<a.radical()<<"\n";
    cout<<"\n\n";
    cout<<"Calculam radicalul pentru: ("<<a<<")*z^2 + ("<<b<<")*z + ("<<c<<") = 0\n";
    Numar_Complex r = (b*b - a*c*4).radical();
    Numar_Complex z1 = (-b - r) / (a*2);
    Numar_Complex z2 = (-b + r) / (a*2);
    cout<<"r="<<r<<"\n\n";
    cout<<"z1="<<z1<<"\n";
    cout<<"z2="<<z2<<"\n";
    return 0;
}
