#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

class fraction
{
    public:
        fraction();
        fraction( fraction& object );
        fraction( int _numerator , int _denominator );

        fraction operator + ( fraction object );
        fraction operator - ( fraction object );
        fraction operator * ( fraction object );
        fraction operator / ( fraction object );

        bool operator >  ( fraction object );
        bool operator <  ( fraction object );
        bool operator >= ( fraction object );
        bool operator <= ( fraction object );
        bool operator == ( fraction object );

        friend ostream& operator << ( ostream& out , fraction& object );
        friend istream& operator >> ( istream& in  , fraction& object );

        int  getNumerator();
        int  getDenominator();
        bool getValid();
        string getState();
        char getSign();

        bool decode( string frac , fraction& object );
        void reduction();
        void isValid( fraction& object );
        char tellSign( int _numerator , int _denominator );

        void setSign( char _sign );
        void setDenominator ( int _Denominator );
        void setNumerator( int _numberator );
        void setValid( bool _valid );
        void setState( string _state );

        virtual ~fraction();

    protected:

    private:
        int numerator , denominator;
        bool valid; string state;
        char sign;
};

ostream& operator << ( ostream& out , fraction& object );
istream& operator >> ( istream& in  , fraction& object );

#endif // FRACTION_H
