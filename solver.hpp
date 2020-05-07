#pragma once
using namespace std;
#include <complex>
namespace solver
{
class RealVariable
{
private:
    double a;
    double b;
    double c;
    bool isZero;

public:
    RealVariable() : a(0), b(0), c(0) {}
    RealVariable(double a, double b, double c) : a(a), b(b), c(c), isZero(false) {}
    RealVariable(double a, double b, double c, bool x) : a(a), b(b), c(c), isZero(x) {}
    double geta() const { return a; }
    double getb() const { return b; }
    double getc() const { return c; }
    bool getisZero() const { return isZero; }
    friend const RealVariable operator==(const RealVariable &other, const RealVariable &other2);
    //friend const  RealVariable operator==(const  RealVariable &other, const int &other2);
    //friend const RealVariable operator==(const int &other, const RealVariable &other2);
    friend const RealVariable operator==(const RealVariable &other, const double &other2);
    friend const RealVariable operator==(const double &other, const RealVariable &other2);

    //friend const RealVariable operator-(const int &other,  const RealVariable &other2);
    //friend const RealVariable operator-( const RealVariable &other,  int &other2);
    friend const RealVariable operator-(const RealVariable &other, const double &other2);
    friend const RealVariable operator-(const double &other, const RealVariable &other2);
    friend const RealVariable operator-(const RealVariable &other, const RealVariable &other2);

    //friend const RealVariable operator+( const RealVariable &other, const int& other2);
    //friend const  RealVariable operator+( const int &other, const RealVariable other2);
    friend const RealVariable operator+(const double &X, const RealVariable &Y);
    friend const RealVariable operator+(const RealVariable &X, const double &Y);
    friend const RealVariable operator+(const RealVariable &X, const RealVariable &Y);

    // friend const RealVariable operator*(const int &X,  const RealVariable &Y);
    //friend const RealVariable operator*( const RealVariable &X, const int &Y);
    friend const RealVariable operator*(const double &X, const RealVariable &Y);
    friend const RealVariable operator*(const RealVariable &X, const double &Y);

    // friend const RealVariable operator/(const int &X,  const RealVariable &Y);
    // friend const RealVariable operator/( const RealVariable &X, const int &Y);
    friend const RealVariable operator/(const double &X, const RealVariable &Y);
    friend const RealVariable operator/(const RealVariable &X, const double &Y);

    friend const RealVariable operator^(const RealVariable &X, const int &Y);
};

class ComplexVariable
{

private:
    complex<double> a, b, c;
public:
    ComplexVariable():a(0),b(0),c(0){}
    ComplexVariable(complex<double> a,complex<double> b,complex<double> c):a(a),b(b),c(c)  {}
    friend const ComplexVariable operator==(const ComplexVariable &other, const ComplexVariable &other2);
    friend const ComplexVariable operator==(const ComplexVariable &other, const double &other2);
    friend const ComplexVariable operator==(const double &other, const ComplexVariable &other2);
    friend const ComplexVariable operator==(const ComplexVariable &other, const complex<double> &other2);
    friend const ComplexVariable operator==(const complex<double> &other, const ComplexVariable &other2);

    friend const ComplexVariable operator-(const ComplexVariable &other, const double &other2);
    friend const ComplexVariable operator-(const double &other, const ComplexVariable &other2);
    friend const ComplexVariable operator-(const ComplexVariable &other, const ComplexVariable &other2);
    friend const ComplexVariable operator-(const ComplexVariable &other, const complex<double> &other2);


    friend const ComplexVariable operator+(const double &X, const ComplexVariable &Y);
    friend const ComplexVariable operator+(const ComplexVariable &X, const double &Y);
    friend const ComplexVariable operator+(const ComplexVariable &X, const ComplexVariable &Y);
    friend const ComplexVariable operator+(const complex<double> &X, const ComplexVariable &Y);
    friend const ComplexVariable operator+(const ComplexVariable &X, const complex<double> &Y);


    friend const ComplexVariable operator*(const double &X, const ComplexVariable &Y);
    friend const ComplexVariable operator*(const ComplexVariable &X, const double &Y);
    friend const ComplexVariable operator*(const complex<double> &X, const ComplexVariable &Y);

    friend const ComplexVariable operator/(const ComplexVariable &X, const double &Y);

    friend const ComplexVariable operator^(const ComplexVariable &X, const int &Y);
};

double solve(RealVariable x);
complex<double> solve(ComplexVariable x);
} // namespace solver