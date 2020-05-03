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

public:
    RealVariable() : a(0), b(0), c(0) {}
    RealVariable(double a, double b, double c) : a(a), b(b), c(c) {}
    double& geta() { return a; }
    double& getb() { return b; }
    double& getc() { return c; }
    friend RealVariable &operator==(const RealVariable &other, const RealVariable &other2);
    friend RealVariable &operator==(const RealVariable &other, const int &other2);
    friend RealVariable &operator==(const int &other, const RealVariable &other2);
    friend RealVariable &operator==(const RealVariable &other, const double &other2);
    friend RealVariable &operator==(const double &other, const RealVariable &other2);

    friend RealVariable& operator-(const int &other,  RealVariable &other2);
    friend RealVariable& operator-( RealVariable &other,  int &other2);
    friend RealVariable& operator-( RealVariable &other, const double &other2);
    friend RealVariable &operator-(const double &other,  RealVariable &other2);
    friend RealVariable &operator-( RealVariable &other,  RealVariable &other2);

    friend RealVariable& operator+( RealVariable &other, const int other2);
    friend RealVariable& operator+(const double &X,  RealVariable &Y);
    friend RealVariable& operator+( RealVariable &X, const double &Y);
    friend RealVariable& operator+( RealVariable &X,  RealVariable &Y);

    friend RealVariable& operator*(const int &X,  RealVariable &Y);
    friend RealVariable& operator*( RealVariable &X, const int &Y);
    friend RealVariable& operator*(const double &X,  RealVariable &Y);
    friend RealVariable &operator*( RealVariable &X, const double &Y);

    friend RealVariable& operator/(const int &X,  RealVariable &Y);
    friend RealVariable &operator/( RealVariable &X, const int &Y);
    friend RealVariable &operator/(const double &X,  RealVariable &Y);
    friend RealVariable &operator/( RealVariable &X, const double &Y);

    friend RealVariable &operator^( RealVariable &X, const int &Y);
};

class ComplexVariable
{
public:
    ComplexVariable()
    {
    }
    friend ComplexVariable &operator==(const ComplexVariable &other, const ComplexVariable &other2);
    friend ComplexVariable &operator==(const ComplexVariable &other, const int &other2);
    friend ComplexVariable &operator==(const int &other, const ComplexVariable &other2);
    friend ComplexVariable &operator==(const ComplexVariable &other, const double &other2);
    friend ComplexVariable &operator==(const double &other, const ComplexVariable &other2);
    friend ComplexVariable &operator==(const ComplexVariable &other, const complex<double> &other2);
    friend ComplexVariable &operator==(const complex<double> &other, const ComplexVariable &other2);

    friend ComplexVariable operator-(const int &other, const ComplexVariable &other2);
    friend ComplexVariable operator-(const ComplexVariable &other, const int &other2);
    friend ComplexVariable operator-(const ComplexVariable &other, const double &other2);
    friend ComplexVariable operator-(const double &other, const ComplexVariable &other2);
    friend ComplexVariable operator-(const ComplexVariable &other, const ComplexVariable &other2);
    friend ComplexVariable operator-(const ComplexVariable &other, const complex<double> &other2);

    friend ComplexVariable operator+(const int &other, const ComplexVariable &other2);
    friend ComplexVariable operator+(const ComplexVariable &other, const int &other2);
    friend ComplexVariable operator+(const double &X, const ComplexVariable &Y);
    friend ComplexVariable operator+(const ComplexVariable &X, const double &Y);
    friend ComplexVariable operator+(const ComplexVariable &X, const ComplexVariable &Y);
    friend ComplexVariable operator+(const complex<double> &X, const ComplexVariable &Y);
    friend ComplexVariable operator+(const ComplexVariable &X, const complex<double> &Y);

    friend ComplexVariable operator*(const int &X, const ComplexVariable &Y);
    friend ComplexVariable operator*(const ComplexVariable &X, const int &Y);
    friend ComplexVariable operator*(const double &X, const ComplexVariable &Y);
    friend ComplexVariable operator*(const ComplexVariable &X, const double &Y);

    friend ComplexVariable operator/(const int &X, const ComplexVariable &Y);
    friend ComplexVariable operator/(const ComplexVariable &X, const int &Y);
    friend ComplexVariable operator/(const double &X, const ComplexVariable &Y);
    friend ComplexVariable operator/(const ComplexVariable &X, const double &Y);

    friend ComplexVariable &operator^(const ComplexVariable &X, const int &Y);
};

double solve(RealVariable x);
complex<double> solve(ComplexVariable &x);
} // namespace solver