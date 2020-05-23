#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include <iomanip>
#include <string>
#include <random>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/odeint.hpp>

#include "ode.hh"
#include "lognormal.hh"

int main( int argc, char *argv[] )
{
  int N = atoi(argv[1]); //Number of samples
  double tau = atof(argv[2]); //Step size

  std::string filename = "histogram.dat";
  std::string filename2 = "expectation.dat";
  std::string filename3 = "variance.dat";
  std::ofstream myfile, myfile2, myfile3;
  myfile.open(filename.c_str());
  myfile2.open(filename2.c_str(), std::ofstream::app);
  myfile3.open(filename3.c_str(), std::ofstream::app);

  std::vector<double> samples = Lognormal( 2*N );

  //Variables storing the Monte Carlo estimations of the expectations
  double Eu_T_Approx = 0.0;
  double Ev_T_Approx = 0.0;

  for(int i = 0; i < N; ++i)
  {
    mu = samples[i]; //Lognormally sampled value for mu

    double u_T = runge_kutta_4( tau )[0];
    double v_T = runge_kutta_4( tau )[1];

    myfile << mu << "\t" << v_T << std::endl;

    Eu_T_Approx += u_T/((double) N);
    Ev_T_Approx += v_T/((double) N);
  }

  //Variables storing the Monte Carlo estimations of the and variances
  double Var_u_T_Approx = 0.0;
  double Var_v_T_Approx = 0.0;

  for(int i = N; i < 2*N; ++i )
  {
    double u_T = runge_kutta_4( tau )[0];
    double v_T = runge_kutta_4( tau )[1];

    Var_u_T_Approx += (u_T - Eu_T_Approx)*(u_T - Eu_T_Approx)/((double) N);
    Var_v_T_Approx += (v_T - Ev_T_Approx)*(v_T - Ev_T_Approx)/((double) N);
  }

  myfile2 << N << "\t" << Eu_T_Approx << "\t" << Ev_T_Approx << std::endl;
  myfile3 << N << "\t" << Var_u_T_Approx << "\t" << Var_v_T_Approx << std::endl;


  myfile.close();
  myfile2.close();
  myfile3.close();

  return 0;
}
