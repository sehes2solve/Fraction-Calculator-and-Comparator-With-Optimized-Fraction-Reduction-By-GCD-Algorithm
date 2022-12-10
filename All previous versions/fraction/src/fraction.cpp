#include "fraction.h"

fraction::fraction()
{
    this->sign          = '+';
    this->numerator     = 0;
    this->denominator   = 0;
    this->valid         = 0;
    this->state = "No value\n";
}

fraction :: fraction ( fraction& object )
{
    cout << "OK\n";
    this->isValid( object );
    if ( object.valid )
    {
        this->numerator     = object.getNumerator();
        this->denominator   = object.getDenominator();
        this->sign          = object.getSign();
    }
    else
    {
        this->valid = object.getValid();
        this->state = object.getState();
    }
}

fraction :: fraction ( int _numerator , int _denominator )
{
    if ( _denominator == 0 )
    {
        this->valid = false;
        this->state = "UNDEFINE";
    }
    else
    {
        this->valid     = 1;
        this->state     = "";
        this->sign      = this->tellSign( _numerator , _denominator );
        this->numerator     = abs( _numerator );
        this->denominator   = abs( _denominator );
    }
}

fraction::~fraction()
{
    this->numerator     = 0;
    this->denominator   = 0;
    this->valid         = 0;
    this->state = "No value";
}


void fraction :: isValid( fraction& object )
{
    if ( object.denominator == 0 )
    {
        this->valid = 0;
        this->state = "UNDEFIEND";
    }
    else
    {
        this->valid = 1;
        this->state = "";
    }
}

int  fraction :: getNumerator()
{
    return this->numerator;
}

int  fraction :: getDenominator()
{
    return this->denominator;
}

bool fraction :: getValid()
{
    return this->valid;
}

string fraction :: getState()
{
    return this->state;
}

char fraction :: getSign()
{
    return this->sign;
}

char fraction :: tellSign( int _numerator , int _denominator )
{
    if      ( _numerator <  0 && _denominator <  0 ) return '+';
    else if ( _numerator >  0 && _denominator >  0 ) return '+';
    else if ( _numerator == 0 && _denominator != 0 ) return '+';
    else return '-';
}


ostream& operator << ( ostream& out , fraction& object )
{
    if ( object.getValid() == true )
    {
        if ( object.numerator == 0 )
            out << object.sign << " " << 0;
        else
            out << object.getSign() << " " << object.getNumerator() << "/" << object.getDenominator();
    }
    else
    {
        out << object.getState();
    }

    return out;
}

bool decode( string frac , fraction& object )
{
    for ( char& index : frac )
        index = ( index == '/' ? ' ' : index );

    stringstream buf( frac );
    vector < string > nums;
    string s;

    while ( buf >> s ) nums.push_back( s );

    if ( nums.size() != 2 )
    {
        object.setValid( false );
        object.setState( "No Value" );
        return false;
    }
    else
    {
        int numerator   = atoi( nums.front().c_str() );
        int denomirator = atoi( nums.back().c_str()  );

        if ( denomirator == 0 )
        {
            object.setValid( false );
            object.setState( "UNDEFINED" );
            return false;
        }
        else
        {
            object.setValid( true );
            return true;
        }
    }
}


istream& operator >> ( istream& in  , fraction& object )
{
    cout << "Enter the fraction : "; string frac;
    while ( getline( in , frac ) )
    {
        if ( decode( frac , object ) == true ) break;
        else
            cout << "Invalid input\n";
        system( "Pause" ); system( "CLS" );
        cout << "Enter the fraction : ";
    }

    return in;
}


void fraction :: setSign( char _sign )
{
    this->sign = _sign;
}

void fraction :: setDenominator ( int _Denominator )
{
    this->denominator = _Denominator;
}

void fraction :: setNumerator( int _numberator )
{
    this->numerator = _numberator;
}

void fraction :: setValid( bool _valid )
{
    this->valid = _valid;
}

void fraction :: setState( string _state )
{
    this->state = _state;
}

