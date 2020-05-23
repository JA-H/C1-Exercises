#ifndef LOGNORMAL_HH
#define LOGNORMAL_HH

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include <iomanip>
#include <string>
#include <random>

//Constants from assignment 3
const double mu_0 = 10000.0;
const double mu_STD = 1.0e4; //Throughout the assignment we take the variance of mu and lambda to be 1
const double eta = log( mu_0/( pow(1.0 + ( (mu_STD*mu_STD)/(mu_0*mu_0) ) , 0.5 ) ) );
const double var = log(1.0 + (mu_STD*mu_STD)/(mu_0*mu_0));


std::vector<double> Lognormal(int N)
{
  std::vector<double> samples;
  for(int i = 0; i < N; ++i)
  {
    std::random_device rd;
    std::mt19937 e2(rd());
    std::normal_distribution<> dist(eta, var);
    samples.push_back( exp(dist(e2)) );
  }
  return samples;
}

#endif
