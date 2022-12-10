#ifndef FRACTIONCALCULATOR_H
#define FRACTIONCALCULATOR_H

#include "Fraction.h"
#include <map>
#include <iostream>
#include <cstring>
using namespace std;

class FractionCalculator
{
    public:
        FractionCalculator();
        virtual ~FractionCalculator();

        void execute();
        void menu();
        void compareMenu();
        string EnterKey(  );
        string getKey( );

    protected:

    private:
        map < string , Fraction > mp;
};

#endif // FRACTIONCALCULATOR_H
