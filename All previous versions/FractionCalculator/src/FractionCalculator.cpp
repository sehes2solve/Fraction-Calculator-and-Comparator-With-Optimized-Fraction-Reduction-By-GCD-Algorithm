#include "FractionCalculator.h"

#include "Fraction.cpp"

FractionCalculator::FractionCalculator()
{
    cout << "Welcome in fraction calculator\n";
    this->execute();
}

FractionCalculator::~FractionCalculator()
{
    //dtor
}

void FractionCalculator :: execute()
{
    string choice;
    while ( true )
    {
        this->menu(); cin >> choice;

        if      ( choice == "0" ) break;
        else if ( choice == "1" )
        {
            Fraction object;
            cout << "Enter the fraction : "; cin >> object;
            string key = this->EnterKey();

            mp[ key ] = object;
        }
        else if ( choice == "2" )
        {
            string key = this->getKey();
            mp.erase( key );
        }
        else if ( choice == "3" )
        {
            string key = this->getKey();
            cout << mp[ key ] << "\n";
        }
        else if ( choice == "4" )
        {
            cout << "the key of the first  fraction :- \n"; string key1 = this->getKey();
            cout << "the key of the second fraction :- \n"; string key2 = this->getKey();
            cout << "the key of the Result fraction :- \n"; string key3 = this->EnterKey();

            mp[ key3 ] = mp[ key1 ] + mp[ key2 ];
        }
        else if ( choice == "5" )
        {
            cout << "the key of the first  fraction :- \n"; string key1 = this->getKey();
            cout << "the key of the second fraction :- \n"; string key2 = this->getKey();
            cout << "the key of the Result fraction :- \n"; string key3 = this->EnterKey();

            mp[ key3 ] = mp[ key1 ] - mp[ key2 ];
        }
        else if ( choice == "6" )
        {
            cout << "the key of the first  fraction :- \n"; string key1 = this->getKey();
            cout << "the key of the second fraction :- \n"; string key2 = this->getKey();
            cout << "the key of the Result fraction :- \n"; string key3 = this->EnterKey();

            mp[ key3 ] = mp[ key1 ] * mp[ key2 ];
        }
        else if ( choice == "7" )
        {
            cout << "the key of the first  fraction :- \n"; string key1 = this->getKey();
            cout << "the key of the second fraction :- \n"; string key2 = this->getKey();
            cout << "the key of the Result fraction :- \n"; string key3 = this->EnterKey();

            mp[ key3 ] = mp[ key1 ] / mp[ key2 ];
        }
        else if ( choice == "8" )
        {

            system( "CLS" );
            this->compareMenu(); cin >> choice;

            cout << "the key of the first  fraction :- \n"; string key1 = this->getKey();
            cout << "the key of the second fraction :- \n"; string key2 = this->getKey();

            if      ( choice == "1" )
            {
                cout << ( mp[key1] <  mp[key2] ? "True" : "False" ) << "\n";
            }
            else if ( choice == "2" )
            {
                cout << ( mp[key1] >  mp[key2] ? "True" : "False" ) << "\n";
            }
            else if ( choice == "3" )
            {
                cout << ( mp[key1] <= mp[key2] ? "True" : "False" ) << "\n";
            }
            else if ( choice == "4" )
            {
                cout << ( mp[key1] >= mp[key2] ? "True" : "False" ) << "\n";
            }
            else if ( choice == "5" )
            {
                cout << ( mp[key1] == mp[key2] ? "True" : "False" ) << "\n";
            }
            else
                cout << "Invalid Input\n";

        }
        else
            cout << "Invalid input\n";
        system( "Pause" ); system( "CLS" );
    }
}


void FractionCalculator :: menu()
{
    cout << "0- End\n";
    cout << "1- Enter  Fraction\n";
    cout << "2- Delete Fraction\n";
    cout << "3- Print  Fraction\n";
    cout << "4- Add Two Fractions\n";
    cout << "5- Subtract Two Fractions\n";
    cout << "6- Multiply Two Fractions\n";
    cout << "7- Divide   Two Fractions\n";
    cout << "8- Compare  Two Fractions\n";
    cout << "Choice : ";
}

void FractionCalculator :: compareMenu()
{
    cout << "1- less than\n";
    cout << "2- grater than\n";
    cout << "3- less than or equal\n";
    cout << "4- greater than or equal\n";
    cout << "5- equal equal\n";
    cout << "Choice : ";
}

string FractionCalculator :: EnterKey(  )
{
    string key;
    while ( true )
    {
        cout << "Enter the key : "; cin >> key;
        if ( mp.find( key ) != mp.end() )
        {
            cout << "Key is founded, chose anther one\n";
            system( "Pause" ); system( "CLS" );
        }
        else
            break;
    }
    return key;
}

string FractionCalculator :: getKey( )
{
    string key;
    while ( true )
    {
        cout << "Enter the key : "; cin >> key;
        if ( mp.find( key ) == mp.end() )
        {
            cout << "Key is not founded\n";
            system( "Pause" ); system( "CLS" );
        }
        else
            break;
    }
    return key;
}
