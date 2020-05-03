#include "solver.hpp"
#include <complex>

using namespace std;

namespace solver
{
RealVariable &operator==(const RealVariable &other, const int &other2)
{
    RealVariable X;
    return X;
}
RealVariable &operator==(const int &other, const RealVariable &other2)
{
    RealVariable X;
    return X;
}
RealVariable &operator==(const RealVariable &other, const double &other2)
{
    RealVariable X;
    return X;
}
RealVariable &operator==(const double &other, const RealVariable &other2)
{
    RealVariable X;
    return X;
}
RealVariable &operator==(const RealVariable &other, const RealVariable &other2)
{
    RealVariable X;
    return X;
}
RealVariable &operator-(const int &other,  RealVariable &other2) { 
    other2.getc() = -other;
    return other2; }
RealVariable &operator-( RealVariable &other, const int &other2) { 
    other2 - other;
    return other; }
RealVariable &operator-( RealVariable &other, const double &other2) { return other; }
RealVariable &operator-(const double &other,  RealVariable &other2) { return other2; }
RealVariable &operator-( RealVariable &other,  RealVariable &other2) { return other; }

RealVariable &operator+(const int &other,  RealVariable &other2) { 
    other2.getc() = other;
    return other2; }
RealVariable &operator+( RealVariable &other, const int &other2) {
    other2 + other;
     return other; }
RealVariable &operator+( const double &X,  RealVariable &Y) { 
    Y.getc() = X;
    return Y; }
RealVariable &operator+( RealVariable &X, const double &Y) { 
    Y + X;
    return X; }
RealVariable &operator+( RealVariable &X,  RealVariable &Y) { return Y; }

RealVariable &operator*( int &X,  RealVariable &Y) { 
   Y.getb() = X;
    return Y; }
RealVariable& operator*( RealVariable &X, const int &Y) { 
    operator*(Y,X);
    return X; }
RealVariable& operator*(const double &X,  RealVariable &Y) { return Y; }
RealVariable& operator*( RealVariable &X, const double &Y) { return X; }

RealVariable& operator/(const int &X,  RealVariable &Y) { return Y; }
RealVariable& operator/( RealVariable &X, const int &Y) { return X; }
RealVariable& operator/(const double &X,  RealVariable &Y) { return Y; }
RealVariable& operator/( RealVariable &X, const double &Y) { return X; }

RealVariable &operator^( RealVariable &X, const int &Y)
{
    if(Y>2)throw new runtime_error("unsupported exp");
    X.geta = Y;
    return X;
}

//coplex ops
ComplexVariable operator*(const int &X, const ComplexVariable &Y) { return Y; }
ComplexVariable operator*(const ComplexVariable &X, const int &Y) { return X; }
ComplexVariable operator*(const double &X, const ComplexVariable &Y) { return Y; }
ComplexVariable operator*(const ComplexVariable &X, const double &Y) { return X; }

ComplexVariable operator/(const int &X, const ComplexVariable &Y) { return Y; }
ComplexVariable operator/(const ComplexVariable &X, const int &Y) { return X; }
ComplexVariable operator/(const double &X, const ComplexVariable &Y) { return Y; }
ComplexVariable operator/(const ComplexVariable &X, const double &Y) { return X; }

ComplexVariable &operator^(const ComplexVariable &X, const int &Y)
{
    ComplexVariable x;
    return x;
}
ComplexVariable &operator==(const ComplexVariable &other, const ComplexVariable &other2)
{
    ComplexVariable x;
    return x;
}
ComplexVariable &operator==(const ComplexVariable &other, const int &other2)
{
    ComplexVariable x;
    return x;
}
ComplexVariable &operator==(const int &other, const ComplexVariable &other2)
{
    ComplexVariable x;
    return x;
}
ComplexVariable &operator==(const ComplexVariable &other, const double &other2)
{
    ComplexVariable x;
    return x;
}
ComplexVariable &operator==(const double &other, const ComplexVariable &other2)
{
    ComplexVariable x;
    return x;
}
ComplexVariable &operator==(const ComplexVariable &other, const complex<double> &other2)
{
    ComplexVariable x;
    return x;
}
ComplexVariable &operator==(const complex<double> &other, const ComplexVariable &other2)
{
    ComplexVariable x;
    return x;
}

ComplexVariable operator-(const int &other, const ComplexVariable &other2)
{
    ComplexVariable x;
    return x;
}
ComplexVariable operator-(const ComplexVariable &other, const int &other2) { return other; }
ComplexVariable operator-(const ComplexVariable &other, const double &other2) { return other; }
ComplexVariable operator-(const double &other, const ComplexVariable &other2)
{
    ComplexVariable x;
    return x;
}
ComplexVariable operator-(const ComplexVariable &other, const ComplexVariable &other2) { return other; }

ComplexVariable operator-(const ComplexVariable& other, const complex<double>& other2){ return other; }
ComplexVariable operator+(const int &other, const ComplexVariable &other2)
{
    ComplexVariable x;
    return x;
}
ComplexVariable operator+(const ComplexVariable &other, const int &other2) { return other; }
ComplexVariable operator+(const double &X, const ComplexVariable &Y) { return Y; }
ComplexVariable operator+(const ComplexVariable &X, const double &Y) { return X; }
ComplexVariable operator+(const ComplexVariable &X, const ComplexVariable &Y) { return X; }
ComplexVariable operator+(const std::complex<double> &X, const ComplexVariable &Y) { return Y; }
ComplexVariable operator+(const ComplexVariable &X, const std::complex<double> &Y) { return X; }
ComplexVariable operator+(const int &X, const std::complex<double> &Y) {
    ComplexVariable c;
    return c;
 }


    double solver::solve(RealVariable x){
        return 0.0;
    }
    complex<double> solver::solve(ComplexVariable& x){
        complex<double> s;
        return s;
    }
} // namespace solver