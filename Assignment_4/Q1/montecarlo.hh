#ifndef MONTECARLO_HH
#define MONTECARLO_HH

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <sstream>

#include "models.hh"

double Uniform_0_1()
{
  return (double) rand() / (double) RAND_MAX;
}

double MonteCarloEstimator(const int M, const int N, const ModelInterface* model)
{
  double result = 0.0;
  std::vector< std::vector<double> > samples_vector; // Vector of vector of uniformly distributed samples

  for( int i = 0; i < M; ++i )
  {
    std::vector<double> samples_vector_element;
    for( int j = 0; j < N; ++j )
    {
      double sample = Uniform_0_1();
      samples_vector_element.push_back( sample );
    }
    samples_vector.push_back( samples_vector_element );
  }

  std::vector< std::vector<double> >::iterator it;

  for(it = samples_vector.begin(); it != samples_vector.end(); ++it)
  {
    result += model->f(*it);
  }

  result /= M;
  return result;
}

//Calculates the error between the Monte Carlo simulation and the exact integral.
double RelativeError(const int M, const int N, const ModelInterface* model)
{
  return std::fabs( MonteCarloEstimator(M, N, model) - model->exact_integral(N) )/(model->exact_integral(N));
}










#endif
