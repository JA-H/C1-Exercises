#ifndef BVP_HH
#define BVP_HH


#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <armadillo>

typedef arma::vec Vec;
typedef arma::mat Mat;


Vec solveBVP(double alpha, double beta, double L, int numNodes)
{
  //This function solves the BVP - alpha u'' + beta u' = 0 on [0, L] with u(0) = 0 and u(L) = 1. The result is an Armadillo vector with numNodes entries.
  double h = L/((double) numNodes);

  Mat A(numNodes, numNodes); //Finite difference matrix
  Vec b(numNodes); // RHS vector (0, ... , 0, 1)
  Vec u(numNodes); // Approximation of solution of the BVP

  A.zeros(); //Initialise all entries to be zero

  const double P_e_loc = (beta*h)/(2.0*alpha); //Local Peclet Number

  //Input entires for the finite difference matrix
  for(int i = 0; i < numNodes; ++i)
  {
    if(i == 0)
    {
      A(i , i) = 1.0;
      b(i) = 0.0;
    }
    else if( (i > 0) && (i < numNodes - 1) )
    {
      A(i, i - 1) = -(P_e_loc + 1.0);
      A(i, i) = 2.0;
      A(i, i + 1) = P_e_loc - 1.0;
      b(i) = 0.0;
    }
    else
    {
      A(i, i) = 1.0;
      b(i) = 1.0;
    }
  }
  //Having reduced the BVP to a linear system Au = b, we find the inverse of A.
  Mat I = inv(A);

  u = I*b;

  return u;
}

Vec exactSol(double alpha, double beta, double L, int numNodes)
{
  //This function returns an Armadillo vector with the values of the exact solution at each node of the grid.
  Vec u(numNodes);
  double h = L/((double) numNodes);

  for(int i = 0; i < numNodes; ++i)
  {
    double x = (double) i*h;
    double exact = ( std::exp( (beta*x)/alpha) - 1.0)/( std::exp(beta*L/alpha) - 1.0);
    u(i) = exact;
  }
  return u;
}

double maxError(double alpha, double beta, double L, int numNodes)
{
  Vec u = solveBVP(alpha, beta, L, numNodes);
  Vec v = exactSol(alpha, beta, L, numNodes);
  double max = norm(u - v, "inf"); //Infinity norm of the difference of the two vectors
  return max;
}

#endif
