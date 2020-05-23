#ifndef MODELS_HH
#define MODELS_HH

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

const double PI = 3.14159265358979323846;

struct ModelInterface
{
  virtual double f( std::vector<double> &x ) const = 0;
  virtual double exact_integral(int N) const = 0;
  virtual ~ModelInterface(){}
};

struct Gaussian : public ModelInterface
{
  double f( std::vector<double> &x ) const
  {
    double result;

    int N = x.size();
    double sum = 0.0;

    for(int i = 1; i < N + 1; ++i)
    {
      double nth_term = (7.03 * 7.03 *( x[i - 1] - 0.5 ) *( x[i - 1] - 0.5 ))/((double) i);
      sum += nth_term;
    }

    result = exp(-sum);
    return result;
  }
  double exact_integral(int N) const
  {
    double result = 1.0;

    double root_pi = pow( PI, 0.5 );

    for(int i = 1; i < N + 1; ++i )
    {
      double c_n = 7.03 / (double) i;
      double term = (root_pi/c_n)*erf(0.5*c_n);
      result *= term;
    }
    return result;
  }
  ~Gaussian(){}
};

struct Continuous : public ModelInterface
{
  double f( std::vector<double> &x ) const
  {
    double result;
    int N = x.size();

    double sum = 0.0;

    for(int i = 1; i < N+1; ++i)
    {
      double c_i = (2.04/( ((double) N) ) );
      sum += c_i*std::fabs(x[i-1] - 0.5);
    }
    result = exp(-sum);
    return result;
  }
  double exact_integral(int N) const
  {
    double result = 1.0;

    double c_n = 2.04/((double) N);

    for(int i = 1; i < N+1; ++i)
    {
        result *= (1.0/c_n)*(2.0 - 2.0*exp(-c_n*0.5));
    }
    return result;
  }
  ~Continuous(){}
};

struct Discontinuous : public ModelInterface
{
  double f( std::vector<double> &x ) const
  {
    double result;
    int N = x.size();

    if( (x[0] > PI/4.0) || (x[1] > PI/5.0) )
    {
      result = 0.0;
    }
    else
    {
      double c_n = 4.3/( (double) N );
      double sum = 0.0;

      for(int i = 0; i < N; ++i)
      {
        sum += c_n*x[i];
      }
      result = sum;
    }

    return result;
  }
  double exact_integral(int N) const
  {
    double c_n = 4.3/( (double) N);
    double k = std::pow(c_n, (double) N);

    return (1.0/k)*(std::exp( c_n*(PI/4.0) ) - 1.0)*(std::exp( c_n*(PI/5.0) ) - 1.0)*(std::pow( std::exp(c_n)  - 1.0, ((double) N) - 2.0));

  }
  ~Discontinuous(){}
};

struct Simplex : public ModelInterface
{
  double f( std::vector<double> &x ) const
  {
    double result;
    double sum = 0.0;

    std::vector<double>::iterator it;

    for(it = x.begin(); it !=x.end(); ++it)
    {
      sum += *it;
    }

    if(sum <= 1.0)
    {
      result = 1.0;
    }
    else
    {
      result = 0.0;
    }

    return result;
  }

  double exact_integral(int N) const
  {
    double result = 1.0;

    for(int i = 1; i < N + 1; ++i)
    {
      result *= 1.0/((double) i);
    }
    return result;
  }
  ~Simplex(){}
};

#endif
