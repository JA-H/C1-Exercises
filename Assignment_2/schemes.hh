#ifndef SCHEMES_HH
#define SCHEMES_HH

#include <cassert>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "models.hh"

const double delta = 0.5 + std::pow(3.0, 0.5)/6.0;

struct DIRK
{
  DIRK(int steps): steps_(steps), a_(steps*steps), b_(steps), c_(steps) // initialising dimensions of matrix A and vectors b, c
  {}
  
  // arbitrary DIRK method
  double evolve(const double &y, double t, double tau, const ModelInterface *model) const
  {
    double ret = y;                 // Value for y_n
    std::vector<double> k(steps_);  // Vector of k[i]
    for (int i = 0; i < steps_; ++i)
    {
      double sum = 0;
      if (i != 0)
      {
        for (int j = 0; j < i; ++j)
        {
	         sum += a_[i*steps_ + j]*k[j];
        }
      }
      if (a_[0] == 0) // Explicit case
      {
        k[i] = model->f(t + c_[i]*tau, y + tau*sum);
        ret += tau*b_[i]*k[i];
      }
      else // Implicit Case
      {
        // Newton-Raphson to calculate k[i]
        double tolerance = 1.0e-6;
        int maxIterations = 100000;
        int count = 0;
        double k_temp;
        do
        {
	         k_temp = k[i];
	         k[i] = k_temp - (model->f(t + c_[i]*tau,y + tau*a_[i*steps_ + i]*k_temp + tau*sum) - k_temp)/(model->df(t + c_[i]*tau, y + tau*a_[i*steps_ + i]*k_temp + tau*sum)*tau*a_[i*steps_ + i] - 1);
	         count += 1;
        }
        while( (std::fabs((k_temp - k[i])/k_temp) >= tolerance) && (count < maxIterations) );
      
        ret += tau*b_[i]*k[i];
      }
    }
    return ret;
  }
  
  protected:
  int steps_;
  std::vector<double> a_,b_,c_;
};

struct FE : public DIRK
{
  FE(int steps) : DIRK(steps)
  {
    b_[0] = 1.0;
  }
};

struct BE : public DIRK
{
  BE(int steps) : DIRK(steps)
  {
    a_[0] = 1.0;
    b_[0] = 1.0;
    c_[0] = 1.0;
  }
};

struct CN : public DIRK
{
  CN(int steps) : DIRK(steps)
  {
    a_[0] = 0.5;
    b_[0] = 1.0;
    c_[0] = 0.5;
  }
};

struct Heun3 : public DIRK
{
  Heun3(int steps) : DIRK(steps)
  {
    a_[3] = 1.0/3.0;
    a_[7] = 2.0/3.0;
    b_[0] = 1.0/4.0;
    b_[2] = 3.0/4.0;
    c_[1] = 1.0/3.0;
    c_[2] = 2.0/3.0;
  }
};

struct DIRK2 : public DIRK
{
  DIRK2(int steps) : DIRK(steps)
  {
    a_[0] = delta;
    a_[2] = 1.0 - 2.0*delta;
    a_[3] = delta;
    b_[0] = (0.5 - delta)/(1 - 2.0*delta);
    b_[1] = (0.5 - delta)/(1 - 2.0*delta);
    c_[0] = delta;
    c_[1] = 1.0 - delta;
  }
};

#endif
