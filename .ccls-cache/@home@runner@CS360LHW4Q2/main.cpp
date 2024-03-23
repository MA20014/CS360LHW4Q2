#include <iostream>
using namespace std;

class Rational {
public:
    Rational(int = 0, int = 1); // default constructor
    Rational addition(const Rational &); // function addition
    Rational subtraction(const Rational &); // function subtraction
    Rational multiplication(const Rational &); // function multi.
    Rational division(const Rational &); // function division
    void printRational(); // print rational format
    void printRationalAsDouble(); // print rational as double format

private:
    int numerator; // integer numerator
    int denominator; // integer denominator
    void reduction(); // utility function
}; // end class Rational

Rational::Rational(int n, int d) {
    numerator = n; // sets numerator
    denominator = d; // sets denominator
    reduction(); // store the fraction in reduced form
} // end Rational constructor

Rational Rational::addition(const Rational &a) {
    Rational t; // creates Rational object
    t.numerator = a.numerator * denominator;
    t.numerator += a.denominator * numerator;
    t.denominator = a.denominator * denominator;
    t.reduction(); // store the fraction in reduced form
    return t;
} // end function addition

Rational Rational::subtraction(const Rational &s) {
    Rational t; // creates Rational object
    t.numerator = s.denominator * numerator;
    t.numerator -= denominator * s.numerator;
    t.denominator = s.denominator * denominator;
    t.reduction(); // store the fraction in reduced form
    return t;
} // end function subtraction

Rational Rational::multiplication(const Rational &m) {
    Rational t; // creates Rational object
    t.numerator = m.numerator * numerator;
    t.denominator = m.denominator * denominator;
    t.reduction(); // store the fraction in reduced form
    return t;
} // end function multiplication

Rational Rational::division(const Rational &v) {
    Rational t; // creates Rational object
    t.numerator = v.denominator * numerator;
    t.denominator = denominator * v.numerator;
    t.reduction(); // store the fraction in reduced form
    return t;
} // end function division

void Rational::printRational() {
    if (denominator == 0) // validates denominator
        cout << "\nDIVIDE BY ZERO ERROR!!!" << '\n';
    else if (numerator == 0) // validates numerator
        cout << 0;
    else
        cout << numerator << '/' << denominator;
} // end function printRational

void Rational::printRationalAsDouble() {
    cout << static_cast<double>(numerator) / denominator;
} // end function printRationalAsDouble

void Rational::reduction() {
    int largest;
    largest = numerator > denominator ? numerator : denominator;
    int gcd = 0; // greatest common divisor
    for (int loop = 2; loop <= largest; loop++)
        if (numerator % loop == 0 && denominator % loop == 0)
            gcd = loop;
    if (gcd != 0) {
        numerator /= gcd;
        denominator /= gcd;
    } // end if
}

int main() {
    int num1, denom1, num2, denom2;

    cout << "Enter numerator and denominator for the first fraction: ";
    cin >> num1 >> denom1;
    cout << "Enter numerator and denominator for the second fraction: ";
    cin >> num2 >> denom2;

    Rational c(num1, denom1), d(num2, denom2), x; // creates three rational objects
    cout << endl;
    cout<<"Addition of the 2 rational numbers: ";
    c.printRational(); // prints rational object c
    cout << " + ";
    d.printRational(); // prints rational object d
    x = c.addition(d); // adds object c and d; sets the value to x
    cout << " = ";
    x.printRational(); // prints rational object x
    cout << '\n';
    x.printRational(); // prints rational object x
    cout << " = ";
    x.printRationalAsDouble(); // prints rational object x as double
    cout << "\n\n";
    cout<<"Subtraction of the 2 rational numbers: ";
    c.printRational(); // prints rational object c
    cout << " - ";
    d.printRational(); // prints rational object d
    x = c.subtraction(d); // subtracts object c and d

    cout << " = ";
    x.printRational(); // prints rational object x
    cout << '\n';
    x.printRational(); // prints rational object x
    cout << " = ";
    x.printRationalAsDouble(); // prints rational object x as double
    cout << "\n\n";
    cout<<"Multiplication of the 2 rational numbers: ";
    c.printRational(); // prints rational object c
    cout << " x ";
    d.printRational(); // prints rational object d
    x = c.multiplication(d); // multiplies object c and d

    cout << " = ";
    x.printRational(); // prints rational object x
    cout << '\n';
    x.printRational(); // prints rational object x
    cout << " = ";
    x.printRationalAsDouble(); // prints rational object x as double
    cout << "\n\n";
    cout<<"Quotient of the 2 rational numbers: ";
    c.printRational(); // prints rational object c
    cout << " / ";
    d.printRational(); // prints rational object d
    x = c.division(d); // divides object c and d

    cout << " = ";
    x.printRational(); // prints rational object x
    cout << '\n';
    x.printRational(); // prints rational object x
    cout << " = ";
    x.printRationalAsDouble(); // prints rational object x as double
    cout << endl;
    return 0;
} 
