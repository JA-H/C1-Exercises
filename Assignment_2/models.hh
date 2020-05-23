#ifndef MODELS_HH
#define MODELS_HH

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

const double PI = 3.141592653589793238463;
const double lambda = -0.1;


struct ModelInterface
{
  virtual double f(double t,const double &y) const = 0;
  virtual double df(double t, const double &y) const = 0;
  virtual double T() const = 0;
  virtual double y0() const = 0;
  virtual double exact(double t) const = 0;
  virtual ~ModelInterface(){}
};

struct Equation_1 : public ModelInterface
{
  double f(double t, const double &y) const
  {
    return 1.0 - cos(t)*(cos(t) - 1.0) - y*y;
  }
  double df(double t, const double &y) const
  {
    return -2.0*y;
  }
  double T() const
  {
    return 2.0*PI; // 2*pi
  }
  double y0() const
  {
    return 0.0;
  }
  double exact(double t) const
  {
    return sin(t);
  }
  ~Equation_1(){}
};

struct Equation_2 : public ModelInterface
{
  double f(double t, const double &y) const
  {
    return 1.0 - cos(t)*(cos(t) - exp(lambda*t)) - exp(-2.0*lambda*t)*y*y + lambda*y;
  }
  double df(double t, const double &y) const
  {
    return 2.0*exp( -2.0*lambda*t )*y + lambda;
  }
  double T() const
  {
    return 10.0;
  }
  double y0() const
  {
    return 0.0;
  }
  double exact(double t) const
  {
    return exp(lambda*t)*sin(t);
  }
  ~Equation_2(){}
};

#endif // MODELS_HH
