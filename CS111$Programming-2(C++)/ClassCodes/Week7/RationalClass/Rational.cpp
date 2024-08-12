#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Rational.h"
using namespace std;

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int nume, int denomi)
{
    numerator = nume;
    denominator = denomi;
}

int Rational::getNumerator()
{
    return numerator;
}

int Rational::getDenominator()
{
    return denominator;
}

int Rational::gcd(int n, int d)
{
    int n1 = abs(n);
    int n2 = abs(d);
    int gcd = 1;

    for (int k = 1; k <= n1 && k <= n2; k++)
    {
        if (n1 % k == 0 && n2 % k == 0)
        {
            gcd = k;
        }
    }

    return gcd;
}

Rational Rational::add(Rational &secondRational)
{
    int n = numerator * secondRational.getDenominator() + denominator * secondRational.getNumerator();
    int d = denominator * secondRational.getDenominator();
    return Rational(n, d);
}

Rational Rational::subtract(Rational &secondRational)
{
    int n = numerator * secondRational.getDenominator() - denominator * secondRational.getNumerator();
    int d = denominator * secondRational.getDenominator();
    return Rational(n, d);
}

Rational Rational::multiply(Rational &secondRational)
{
    int n = numerator * secondRational.getNumerator();
    int d = denominator * secondRational.getDenominator();
    return Rational(n, d);
}

Rational Rational::divide(Rational &secondRational)
{
    int n = numerator * secondRational.getDenominator();
    int d = denominator * secondRational.getNumerator();
    return Rational(n, d);
}

int Rational::compareTo(Rational &secondRational)
{
    Rational temp = subtract(secondRational);
    if (temp.getNumerator() < 0)
    {
        return -1;
    }
    else if (temp.getNumerator() == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool Rational::equals(Rational &secondRational)
{
    if (compareTo(secondRational) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Rational::intValue()
{
    return getNumerator() / getDenominator();
}

double Rational::doubleValue()
{
    return 1.0 * getNumerator() / getDenominator();
}

string Rational::toString()
{
    // cout << "n: " << numerator << endl;
    // cout << "d: " << denominator << endl;

    stringstream ss;
    ss << numerator;
    if (denominator > 1)
    {
        ss << "/" << denominator;
    }

    return ss.str();
}

/** function overload  */
bool Rational::operator<(Rational &secondRational)
{
    if (compareTo(secondRational) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Rational::operator>(Rational &secondRational)
{
    if (compareTo(secondRational) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Rational Rational::operator+(Rational &secondRational)
{
    add(secondRational);
}

Rational Rational::operator-(Rational &secondRational)
{
    subtract(secondRational);
}

Rational Rational::operator*(Rational &secondRational)
{
    multiply(secondRational);
}

Rational Rational::operator/(Rational &secondRational)
{
    divide(secondRational);
}

bool Rational::operator==(Rational &secondRational)
{
    equals(secondRational);
}

int Rational::operator[](int idx)
{
    if (idx == 0)
    {
        return numerator;
    }
    else if (idx == 1)
    {
        return denominator;
    }
    else
    {
        cout << "Index Out of Range.";
        exit(0);
    }
}