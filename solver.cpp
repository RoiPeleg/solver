#include "solver.hpp"
#include <complex>
#include <iostream>
using namespace std;

namespace solver
{

const RealVariable operator==(const RealVariable &other, const double &other2)
{
    if (other.geta() == 0 && other.getb() == 0)
    {
        if (other.getisZero() == false)
            return RealVariable(0, 0, other2 - other.getc());
        else
        {
            throw new runtime_error("no soultion");
        }
    }
    return RealVariable(other.geta(), other.getb(), other.getc() - other2);
}
const RealVariable operator==(const double &other, const RealVariable &other2)
{
    return other2 == other;
}
const RealVariable operator==(const RealVariable &other, const RealVariable &other2)
{
    return RealVariable(other.geta() - other2.geta(), other.getb() - other2.getb(), other.getc() - other2.getc());
}

const RealVariable operator-(const RealVariable &other, const double &other2)
{
    return RealVariable(other.geta(), other.getb(), other.getc() - other2, other.getisZero());
}
const RealVariable operator-(const double &other, const RealVariable &other2)
{
    return RealVariable(-other2.geta(), -other2.getb(), other - other2.getc());
}
const RealVariable operator-(const RealVariable &other, const RealVariable &other2)
{
    if (other.geta() == other2.geta() && other.getb() == other2.getb() && other.getc() == other2.getc())
        return RealVariable(0, 0, 0, true);
    if (other2.getb() == 0)
        return RealVariable(other.geta(), other.getb() - 1, other.getc());
    return RealVariable(other.geta() - other2.geta(), other.getb() - other2.getb(), other.getc() - other2.getc());
}



const RealVariable operator+(const double &other, const RealVariable &other2)
{
    return RealVariable(other2.geta(), other2.getb(), other + other2.getc());
}
const RealVariable operator+(const RealVariable &other, const double &other2)
{
    return RealVariable(other.geta(), other.getb(), other.getc() + other2, other.getisZero());
}
const RealVariable operator+(const RealVariable &X, const RealVariable &Y)
{
    if (X.geta() == -Y.geta() && X.getb() == -Y.getb() && X.getc() == -Y.getc())
        return RealVariable(0, 0, 0, true);

    return RealVariable(X.geta() + Y.geta(), X.getb() + Y.getb(), X.getc() + Y.getc());
}

const RealVariable operator*(const double &X, const RealVariable &Y)
{
    if (X == 0.0)
        return RealVariable(0, 0, 0, true);

    if (Y.geta() == 1)
        return RealVariable(X, Y.getb(), Y.getc());
    return RealVariable(Y.geta(), X, Y.getc());
}
const RealVariable operator*(const RealVariable &X, const double &Y) { return operator*(Y, X); }
const RealVariable operator/(const double &X, const RealVariable &Y) { return Y; }
const RealVariable operator/(const RealVariable &X, const double &Y)
{
    if (Y == 0)
        throw new runtime_error("can't divide by 0");
    return RealVariable(X.geta(), X.getb() / Y, X.getc());
}

const RealVariable operator^(const RealVariable &X, const int &Y)
{
    if (Y != 2)
        throw new runtime_error("unsupported exp");
    return RealVariable(1, X.getb(), X.getc());
}



//coplex ops

const ComplexVariable operator*(const double &X, const ComplexVariable &Y) {

    if(Y.a==0.0 && Y.b ==0.0 && Y.c == 0.0 && Y.isZero == false){
            //cout << Y.a << " " << X << " " << Y.c << endl;
        return ComplexVariable(0.0, X, 0.0, false);
    }
    if(Y.a != 0.0)
       return ComplexVariable(X*Y.a, X*Y.b,Y.c, false); 
    return ComplexVariable(Y.a, X*Y.b,Y.c,false);
}
const ComplexVariable operator*(const ComplexVariable &X, const double &Y) { return Y*X; }

const ComplexVariable operator/(const ComplexVariable &X, const double &Y) { 
    return X*(1/Y); }
const ComplexVariable operator^(const ComplexVariable &X, const int &Y)
{
    if(Y != 2)throw new runtime_error("unsupported exp");
    return ComplexVariable(1,complex<double>(0,0),complex<double>(0,0),false);
}



const ComplexVariable operator==(const ComplexVariable &other, const complex<double> &other2)
{
    return other - other2;
}
const ComplexVariable operator==(const complex<double> &other, const ComplexVariable &other2)
{
    return other - other2;
}
const ComplexVariable operator==(const ComplexVariable &other, const ComplexVariable &other2)
{
    return other - other2;
}

const ComplexVariable operator-(const ComplexVariable &other, const double &other2) {return ComplexVariable(other.a,other.b,other.c-other2,false); }
const ComplexVariable operator-(const double &other, const ComplexVariable &other2)
{
    return ComplexVariable(-other2.a,other2.b,other-other2.c,false);
}
const ComplexVariable operator-(const ComplexVariable &X, const ComplexVariable &Y) {
    if(X.b==0.0 && X.isZero == false)
        return ComplexVariable (X.a-Y.a, X.b-Y.b+1.0, X.c-Y.c, false);
    if(Y.b==0.0 && Y.isZero == false)
       return ComplexVariable (X.a-Y.a, X.b-1.0, X.c-Y.c, false); 
    return ComplexVariable (X.a-Y.a, X.b-Y.b, X.c-Y.c, false);
}

const ComplexVariable operator-(const ComplexVariable &X, const complex<double> &Y) {
    return ComplexVariable(X.a, X.b, X.c-Y, false);
}
const ComplexVariable operator-(const complex<double> &X, const ComplexVariable &Y){
    return ComplexVariable(-Y.a, -Y.b, X-Y.c, false);
}

const ComplexVariable operator+(const double &X, const ComplexVariable &Y) {
    return ComplexVariable(Y.a, Y.b, Y.c+X, false);
}
const ComplexVariable operator+(const ComplexVariable &X, const double &Y) {
   return ComplexVariable(X.a, X.b, X.c+Y, false); 
}
const ComplexVariable operator+(const ComplexVariable &X, const ComplexVariable &Y) {
    return ComplexVariable (X.a+Y.a, X.b+Y.b, X.c+Y.c, false);
}
const ComplexVariable operator+(const complex<double> &X, const ComplexVariable &Y) {
    return ComplexVariable(Y.a, Y.b, Y.c+X, false);
}
const ComplexVariable operator+(const ComplexVariable &X, const complex<double> &Y) {
    return ComplexVariable(X.a, X.b, X.c+Y, false);
}

double solve(RealVariable x)
{
    if (x.geta() == 0 && x.getb() == 0)
    {
        return x.getc();
    }
     if (x.geta() == 0)
    {
        return -x.getc() / x.getb();
    }
     double delta = pow(x.getb(), 2) - 4 * x.geta() * x.getc();
    if (delta < 0)
        throw new runtime_error("no soultion");
    return (-x.getb() + sqrt(delta)) / (2.0 * x.geta());
}
 complex<double> solve(ComplexVariable x)
{

    if (x.geta() == 0.0 && x.getb() == 0.0)
    {
        return -x.getc();
    }
     if (x.geta() == 0.0)
    {
        return -x.getc() / x.getb();
    }
    complex <double> delta = pow(x.getb(), 2.0) - 4.0 * x.geta() * x.getc();
    return (-x.getb() + sqrt(delta)) / (2.0 * x.geta());
}
} // namespace solver