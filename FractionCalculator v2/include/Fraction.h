#ifndef FRACTION_H
#define FRACTION_H
#include <string.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Fraction
{
    public:
        Fraction();
        virtual ~Fraction();
        Fraction operator+(const Fraction&)const;
        Fraction operator-(const Fraction&)const;
        Fraction operator*(const Fraction&)const;
        Fraction operator/(const Fraction&)const;
        bool operator<(const Fraction&)const;
        bool operator>(const Fraction&)const;
        bool operator<=(const Fraction&)const;
        bool operator>=(const Fraction&)const;
        bool operator==(const Fraction&)const;
        bool operator!=(const Fraction&)const;
        friend istream& operator>> (istream&,Fraction&);
        friend ostream& operator<< (ostream&,const Fraction);

    protected:

    private:
        int nume,denu;
        bool Is_Valid_Frac(string);
        void set_denu(int);
        void reduce();
        int GCD(int,int);
};

#endif // FRACTION_H
