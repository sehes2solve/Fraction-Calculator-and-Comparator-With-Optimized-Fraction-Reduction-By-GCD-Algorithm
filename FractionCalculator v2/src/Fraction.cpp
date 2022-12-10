#include "Fraction.h"

bool Is_Valid_Frac(string f)
{
    bool Is_Slash_Found = false;

    for(int i = 0;(unsigned)i < f.length();i++)
    {
        if(((f[i] > '9' || f[i] < '0') && f[i] != ' ' )|| (f[i] == '/' && Is_Slash_Found))
            return false;
        if(f[i] == '/')
            Is_Slash_Found = true;
    }

    stringstream buff(f); string s;
    vector < string > vec;
    while ( buff >> s ) vec.push_back( s );

    if ( vec.size() != 2 ) return false;
    return true;
}
int Fraction::GCD(int num,int den)
{
    if(num == 0)
        return den;
    else if(den == 0)
        return num;
    else
        if(num > den)
            return GCD(den,num%den);
        else
            return GCD(num,den%num);
}
void Fraction::reduce()
{
    int gcd = GCD(abs(nume),abs(denu));
    if((gcd != nume && gcd != denu )||( nume % denu == 0 )|| (denu % nume == 0))
    {
        nume /= gcd;
        denu /= gcd;
    }
}
Fraction::Fraction()
{
    nume = 1;
    denu = 1;
}
void Fraction::set_denu(int d)
{
    denu = (d != 0 && nume != 0)? d : 1;
}
Fraction::~Fraction()
{
    //dtor
}
Fraction Fraction::operator+(const Fraction& F)const
{
    Fraction res;
    res.nume = nume*F.denu + F.nume*denu;
    res.denu = denu * F.denu;
    res.reduce();
    return res;
}
Fraction Fraction::operator-(const Fraction& F)const
{
    Fraction temp = F;
    temp.nume = -temp.nume;
    return (*this + temp);
}
Fraction Fraction::operator*(const Fraction& F)const
{
    Fraction res;
    res.nume = nume*F.nume;
    res.denu = denu*F.denu;
    res.reduce();
    return res;
}
Fraction Fraction::operator/(const Fraction& F)const
{
    Fraction temp = F;
    swap(temp.nume,temp.denu);
    return *this * temp;
}
bool Fraction::operator<(const Fraction& F)const
{
    return (nume/denu < F.nume/F.denu)? true : (nume/denu == F.nume/F.denu && nume%denu < F.nume%F.denu);
}
bool Fraction::operator>(const Fraction& F)const
{
    return !(*this < F || *this == F);
}
bool Fraction::operator<=(const Fraction& F)const
{
    return !(*this > F);
}
bool Fraction::operator>=(const Fraction& F)const
{
    return !(*this < F);
}
bool Fraction::operator==(const Fraction& F)const
{
    return nume == F.nume && denu == F.denu;
}
bool Fraction::operator!=(const Fraction& F)const
{
    return !(*this == F);
}
istream& operator>> (istream& in,Fraction& F)
{
    string temp;
    in >> temp;
    for(char& tem:temp)
    {if(tem =='/'){tem = ' ' ;break;}}
    if(Is_Valid_Frac(temp))
    {
        int denu_temp;
        stringstream buff(temp);
        buff >> F.nume >> denu_temp;
        F.set_denu(denu_temp);
        F.reduce();
    }
    else
        {F.nume = 1; F.set_denu(1);} /// set 1 value for invalid inputs
    return in;
}
ostream& operator<< (ostream& out,const Fraction F)
{
    if(F.denu == 1)
        out << F.nume;
    else
        out << F.nume << '/' << F.denu;
    return out;
}
