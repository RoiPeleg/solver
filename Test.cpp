/**
 * unit test to solver
 * AUTHOR: RoiPeleg TalAbed
 * */
#include "doctest.h"
#include "solver.hpp"
using namespace solver;

#include <string>
using namespace std;

TEST_CASE("RealVariable"){
    RealVariable x;
    CHECK (solve(1*x==7) == 7);
    CHECK (solve(2*x==8) == 4);
    CHECK (solve(7==7*x) == 1);
    CHECK (solve(12==2*x) == 6);
    CHECK (solve(x-35==7) == 42);
    CHECK (solve(-9+x==-1) == 8);
    CHECK (solve(0==7+x) == -7);
    CHECK (solve(2*x==80) == 40);
    CHECK (solve(-0.5==-0.25+x) == -0.25);
    CHECK (solve(0.9+x==0.3) == -0.6);
    CHECK (solve(1.5+x==1) == -0.5);
    CHECK (solve(-3==0.5+x) == -3.5);

    CHECK (solve(x-7.2==-13.2) == -6);
    CHECK (solve(0.4==x+3.2) == -2.8);
    CHECK (solve(-2.4+x==1.6) == 4);
    CHECK (solve(4+x==2.4) == -1.6);
    CHECK (solve(x+9.5==2.5) == -7);
    CHECK (solve(7==14*x) == 0.5);
    CHECK (solve(-3*x==-3) == 1);
    CHECK (solve(4==-8*x) == -0.5);
    CHECK (solve(-3.2==-0.4*x) == 8);
    CHECK (solve(15*x==0.5) == 0.033);
    CHECK (solve(-9*x==24) == -2.66);
    CHECK (solve(5*x==2) == 0.4);
    CHECK (solve(-400==5*x) == -80);
    CHECK (solve(9*x==-1) == -0.11);
    CHECK (solve(0.2*x==-1) == -5);
    CHECK (solve(x/18==-3) == -54);
    CHECK (solve(10==-10*x/11) == -11);
    CHECK (solve(3.5*x==-10.5) == -3);
    CHECK (solve(-5==x/-5) == 25);
    CHECK (solve(x/8==0) == 0);
    CHECK (solve(15*x==-7.5) == -0.5);

    CHECK (solve(3+4*x==15) == 3);
    CHECK (solve(-6==3*x+3) == -3);
    CHECK (solve(-21==-3-2*x) == 9);
    CHECK (solve(89==10*x-1) == 9);
    CHECK (solve(x+7.5==0) == -7.5);
    CHECK (solve(-3.6*x-4.8==-33.6) == 8);

    CHECK (solve(3*x+6+9*x==-33) == -3.25);
    CHECK (solve(-40-60==12*x-10*x-5*x) == 33.33);
    CHECK (solve(-5*x-4-2.5*x+3==14) == -2);
    CHECK (solve(-1.4*x+6-3.6*x-8==18) == -4);

    CHECK (solve((x^2)-36==0) == 6);
    CHECK (solve(4*(x^2)==9) == 1.5);
    CHECK (solve(81-(x^2)==0) == 9);
    CHECK (solve((x^2)==4) == 2);
    CHECK (solve(6*x==18) == 3);
    CHECK (solve(-9*x+0.6*(x^2)==0) == 0);
    CHECK (solve((x^2)-9==0) == 3);
}

TEST_CASE("ComplexVariable"){
    ComplexVariable y;

    CHECK (solve(y==1) == 1. +0i);
    CHECK (solve(1==y) == 1. +0i);
    CHECK (solve(y==4i) == 0. +4i);
    CHECK (solve(4i==y) == 0. +4i);
    CHECK (solve(y==4i+3i) == 0. +7i);
    CHECK (solve(y==5.+7i) == 5. +7i);
    CHECK (solve(5.+7i==y) == 5. +7i); 
    CHECK (solve(5.+7i==y-7) == 12. +7i);
    CHECK (solve(5.+7i==y) == 5. +7i);
    CHECK (solve(y==2i^2) == -4. +0i);
    CHECK (solve(y+4i-8==3i-12.) == -4. + -1i);
    CHECK (solve(2+y-3i==40.+4i) == 38. +7i);
    CHECK (solve(y+3i==5) == 5. -3i);
    CHECK (solve(y+7i==5.-9i) == 5. -16i);
    CHECK (solve(y+1i+6==5) == -1. -1i);
    CHECK (solve(2*y==2i) == 0. + 1i);
    CHECK (solve((y^2)==-1) == 0. + 1i);
    CHECK (solve(y-60==2i-9.) == 51. + 2i);
    CHECK (solve(y+1i==2i-9.) == 51. + 1i);
    CHECK (solve(y==2.+1i-6.) == -4. + 1i);
    CHECK (solve(y==2.*(1i-6.)) == -12. + 2i);
    CHECK (solve(y+7==2.+1i-4.+3i) == -9. + 4i);
    CHECK (solve(2*y==2.+1i-6.) == -2. + 0.5i);
    CHECK (solve(4*y-6i==3. +5i-2.) == 0.25 + 2.75i);
    CHECK (solve((y^2)+1==0) == 0. + 1i);
    CHECK (solve(y==-4.+1i) == -4. + 1i);
    CHECK (solve((y^2)==4) == 2. + 0i);
    CHECK (solve(y==1i^2 + 4.) == 3. + 0i);

    int j;
    for (j=0;j<30;j++){
        CHECK (solve(y==1) == 1. + 0i);
    }  
}
