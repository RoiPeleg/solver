#include "solver.hpp"
#include <complex>
#include <iostream>
using namespace std;

namespace solver
{
// const RealVariable operator==(const RealVariable &other, const int &other2)
// {
//     return RealVariable();
// }
// const RealVariable operator==(const int &other, const RealVariable &other2)
// {
//     return RealVariable();
// }
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
    //cout << other.geta() << " " << other.getb() << " " << other.getc() << endl;
    return RealVariable(other.geta() - other2.geta(), other.getb() - other2.getb(), other.getc() - other2.getc());
}
// const RealVariable operator-(const int &other, const RealVariable &other2)
// {
//     return RealVariable(-other2.geta(), -other2.getb(), other - other2.getc());
// }
// const RealVariable operator-(const RealVariable &other, const int &other2)
// {
//     return RealVariable(other.geta(), other.getb(), other.getc() - other2);
// }
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
    //cout << other.getb()<< " "<< other2.getb() << endl;
    if (other.geta() == other2.geta() && other.getb() == other2.getb() && other.getc() == other2.getc())
        return RealVariable(0, 0, 0, true);
    if (other2.getb() == 0)
        return RealVariable(other.geta(), other.getb() - 1, other.getc());
    return RealVariable(other.geta() - other2.geta(), other.getb() - other2.getb(), other.getc() - other2.getc());
}

// const RealVariable operator+(const int &other, const RealVariable &other2)
// {
//     return RealVariable(other2.geta(), other2.getb(), other2.getc() + other);
// }
// const RealVariable operator+(const RealVariable &other, const int &other2)
// {
//     return RealVariable(other.geta(), other.geta(), other.getc() + other2);
// }

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

// const RealVariable operator*(const int &X, const RealVariable &Y)
// {
//     return RealVariable(Y.geta(), Y.getb() * X, Y.getc());
// }
// const RealVariable operator*(const RealVariable &X, const int &Y)
// {
//     return Y * X;
// }
const RealVariable operator*(const double &X, const RealVariable &Y)
{
    if (X == 0.0)
        return RealVariable(0, 0, 0, true);

    if (Y.geta() == 1)
        return RealVariable(X, Y.getb(), Y.getc());
    return RealVariable(Y.geta(), X, Y.getc());
}
const RealVariable operator*(const RealVariable &X, const double &Y) { return operator*(Y, X); }

//const RealVariable operator/(const int &X, const RealVariable &Y) { return Y; }
// const RealVariable operator/(const RealVariable &X, const int &Y)
// {
//     if (X.getb() != 0)
//         throw new runtime_error("can't divide by 0");
//     return RealVariable(X.geta(), X.getb() / Y, X.getc());
// }
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

const ComplexVariable operator*(const double &X, const ComplexVariable &Y) { return Y; }
const ComplexVariable operator*(const ComplexVariable &X, const double &Y) { return X; }

const ComplexVariable operator/(const double &X, const ComplexVariable &Y) { return Y; }
const ComplexVariable operator/(const ComplexVariable &X, const double &Y) { return X; }
const ComplexVariable operator^(const ComplexVariable &X, const int &Y)
{
    return ComplexVariable();
}
const ComplexVariable operator==(const ComplexVariable &other, const ComplexVariable &other2)
{
    ComplexVariable x;
    return ComplexVariable();
}

const ComplexVariable operator==(const ComplexVariable &other, const double &other2)
{
    ComplexVariable x;
    return ComplexVariable();
}
const ComplexVariable operator==(const double &other, const ComplexVariable &other2)
{
    ComplexVariable x;
    return ComplexVariable();
}
const ComplexVariable operator==(const ComplexVariable &other, const complex<double> &other2)
{
    ComplexVariable x;
    return ComplexVariable();
}
const ComplexVariable operator==(const complex<double> &other, const ComplexVariable &other2)
{
    ComplexVariable x;
    return ComplexVariable();
}
const ComplexVariable operator-(const ComplexVariable &other, const double &other2) { return other; }
const ComplexVariable operator-(const double &other, const ComplexVariable &other2)
{
    return ComplexVariable();
}
const ComplexVariable operator-(const ComplexVariable &other, const ComplexVariable &other2) { return other; }

const ComplexVariable operator-(const ComplexVariable &other, const complex<double> &other2) { return other; }

const ComplexVariable operator+(const double &X, const ComplexVariable &Y) { return Y; }
const ComplexVariable operator+(const ComplexVariable &X, const double &Y) { return X; }
const ComplexVariable operator+(const ComplexVariable &X, const ComplexVariable &Y) { return X; }
const ComplexVariable operator+(const complex<double> &X, const ComplexVariable &Y) { return Y; }
const ComplexVariable operator+(const ComplexVariable &X, const complex<double> &Y) { return X; }

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
const complex<double> solve(ComplexVariable x)
{
     complex<double> s;
     return s;
    
}
} // namespace solverrr