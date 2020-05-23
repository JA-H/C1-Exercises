#ifndef ODE_HH
#define ODE_HH

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/odeint.hpp>

using namespace boost::numeric::odeint;

typedef std::vector<double> state_type;

const double T = 50.0;
const double lambda = 1000.0; //We take lambda to be deterministic

double mu; //We take this to be random in the main function

double q(double t)
{
  return 1.0 - cos(t)*(cos(t) - 1.0);
}

double h(double t)
{
  return -(3.0*t*t -2.0*t)/mu;
}

state_type exact(double t)
{
  state_type result;
  double u = sin(t)*(lambda + t*t*t - t*t)/(mu);
  double v = mu/(lambda + t*t*t - t*t);

  result.push_back(u);
  result.push_back(v);

  return result;
}

void model( state_type &x, state_type &dxdt, double t)
{
  dxdt[0] = (q(t)/x[1]) - (x[0] + h(t))*x[0]*x[1];
  dxdt[1] = h(t)*x[1]*x[1];
}

state_type runge_kutta_4(double tau)
{
	runge_kutta4<state_type> rk4;
	//4th order runge kutta

	state_type x(2);
	double t = 0.0;

  //Initial values
	x[0] = 0.0;
	x[1] = 10.0;

  //Finds value of the solution at the end of the interval using RK4
	while(t < T)
	{
    rk4.do_step(model, x, t, tau);
		t += tau;
	}

  return x;
}


#endif
