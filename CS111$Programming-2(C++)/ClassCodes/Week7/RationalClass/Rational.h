#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>
using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;
    static int gcd(int n, int d);

public:
    Rational();
    Rational(int numerator, int denominator);
    int getNumerator() ;
    int getDenominator() ;
    Rational add( Rational &secondRAtional) ;
    Rational subtract( Rational &secondRAtional) ;
    Rational multiply( Rational &secondRAtional) ;
    Rational divide( Rational &secondRAtional) ;
    int compareTo( Rational &secondRAtional) ;
    bool equals( Rational &secondRational) ;
    int intValue() ;
    double doubleValue() ;
    string toString() ;

    /** function overload */
    bool operator<( Rational &secondRational) ;
    bool operator>( Rational &secondRational) ;
    Rational operator+( Rational &secondRational) ;
    Rational operator-( Rational &secondRational) ;
    Rational operator*( Rational &secondRational) ;
    Rational operator/( Rational &secondRational) ;
    bool operator==( Rational &secondRational) ;
    int operator[](int idx);
};

#endif