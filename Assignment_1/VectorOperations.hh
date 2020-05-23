//Vector Operations Header

#ifndef VECOPHEADERDEF
#define VECOPHEADERDEF

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cstdlib>

//L^infinity norm of vectors 
double norm_infinity( std::vector<double> x );

//Supremum difference
double sup_difference(std::vector<double> x, std::vector<double> y);

#endif