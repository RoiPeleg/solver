#pragma once
using namespace std;
#include <complex>
namespace solver{
    class RealVariable{     
        public:  
        RealVariable(){}
        friend RealVariable& operator==(const RealVariable& other,const RealVariable& other2);
        friend RealVariable& operator==(const RealVariable& other,const int& other2);
        friend RealVariable& operator==(const int& other,const RealVariable& other2);
        friend RealVariable& operator==(const RealVariable& other,const double& other2);
        friend RealVariable& operator==(const double& other,const RealVariable& other2);
        

        friend RealVariable operator-(const int& other, const RealVariable& other2);
        friend RealVariable operator-(const RealVariable& other, const int& other2);
        friend RealVariable operator-(const RealVariable& other, const double& other2);
        friend RealVariable operator-(const double& other, const RealVariable& other2);
        friend RealVariable operator-(const RealVariable& other, const RealVariable& other2);
        
        friend RealVariable operator+(const int& other, const RealVariable& other2);
        friend RealVariable operator+(const RealVariable& other, const int& other2);
        friend RealVariable operator+(const double& X,const RealVariable& Y);
        friend RealVariable operator+(const RealVariable& X,const double& Y);
        friend RealVariable operator+(const RealVariable& X,const RealVariable& Y);


        friend RealVariable operator*(const int& X,const RealVariable& Y);
        friend RealVariable operator*(const RealVariable& X,const int& Y);
        friend RealVariable operator*(const double& X,const RealVariable& Y);
        friend RealVariable operator*(const RealVariable& X,const double& Y);

        
        friend RealVariable operator/(const int& X,const RealVariable& Y);
        friend RealVariable operator/(const RealVariable& X,const int& Y);
        friend RealVariable operator/(const double& X,const RealVariable& Y);
        friend RealVariable operator/(const RealVariable& X,const double& Y);

        friend RealVariable& operator^(const RealVariable& X, const int& Y);
    };



    class ComplexVariable{
        public:
        ComplexVariable(){

        }
        friend ComplexVariable& operator==(const ComplexVariable& other,const ComplexVariable& other2);
        friend ComplexVariable& operator==(const ComplexVariable& other,const int& other2);
        friend ComplexVariable& operator==(const int& other,const ComplexVariable& other2);
        friend ComplexVariable& operator==(const ComplexVariable& other,const double& other2);
        friend ComplexVariable& operator==(const double& other,const ComplexVariable& other2);
        

        friend ComplexVariable operator-(const int& other, const ComplexVariable& other2);
        friend ComplexVariable operator-(const ComplexVariable& other, const int& other2);
        friend ComplexVariable operator-(const ComplexVariable& other, const double& other2);
        friend ComplexVariable operator-(const double& other, const ComplexVariable& other2);
        friend ComplexVariable operator-(const ComplexVariable& other, const ComplexVariable& other2);
        
        friend ComplexVariable operator+(const int& other, const ComplexVariable& other2);
        friend ComplexVariable operator+(const ComplexVariable& other, const int& other2);
        friend ComplexVariable operator+(const double& X,const ComplexVariable& Y);
        friend ComplexVariable operator+(const ComplexVariable& X,const double& Y);
        friend ComplexVariable operator+(const ComplexVariable& X,const ComplexVariable& Y);
        friend ComplexVariable operator+(const complex<double>& X,const ComplexVariable& Y);
        friend ComplexVariable operator+(const ComplexVariable& X,const complex<double>& Y);



        friend ComplexVariable operator*(const int& X,const ComplexVariable& Y);
        friend ComplexVariable operator*(const ComplexVariable& X,const int& Y);
        friend ComplexVariable operator*(const double& X,const ComplexVariable& Y);
        friend ComplexVariable operator*(const ComplexVariable& X,const double& Y);

        
        friend ComplexVariable operator/(const int& X,const ComplexVariable& Y);
        friend ComplexVariable operator/(const ComplexVariable& X,const int& Y);
        friend ComplexVariable operator/(const double& X,const ComplexVariable& Y);
        friend ComplexVariable operator/(const ComplexVariable& X,const double& Y);

        friend ComplexVariable& operator^(const ComplexVariable& X, const int& Y);
    };

    double solve(RealVariable x);
    complex<double> solve(ComplexVariable& x);
}