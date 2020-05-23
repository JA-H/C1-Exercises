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

#include "bvp.hh"

typedef arma::vec Vec;
typedef arma::mat Mat;


int main( int argc, char *argv[] )
{
  double alpha = atof(argv[1]);
  double beta = atof(argv[2]);
  double L = atof(argv[3]);
  int numNodes = atoi(argv[4]);

  std::ofstream myfile, myfile2;
  std::string filename, filename2;
  std::stringstream convertAlpha, convertBeta, convertL, convertNumNodes;
  convertAlpha << alpha;
  convertBeta << beta;
  convertL << L;
  convertNumNodes << numNodes;
  filename = convertAlpha.str() + "_" + convertBeta.str() + "_" + convertL.str() + "_" + convertNumNodes.str() + ".dat";
  //filename = "test.dat";
  filename2 = "Error_Plot_" + convertAlpha.str() + "_" + convertBeta.str() + "_" + convertL.str() + ".dat";
  //filename2 = "test_error.dat";
  myfile.open(filename.c_str());
  myfile2.open(filename2.c_str());


  double h = L/((double) numNodes);

  Vec test = solveBVP(alpha, beta, L, numNodes);
  Vec test_exact = exactSol(alpha, beta, L, numNodes);
  double Err = maxError(alpha, beta, L, numNodes);

  for(int i = 0; i < numNodes; ++i)
  {
    myfile << (double) i*h << "\t" << test(i) << "\t" << test_exact(i) << "\n";
  }
  myfile.close();

  for(int i = 0; i < 10; ++i)
  {
    int M = std::pow(2, i);
    myfile2 << M << "\t" << maxError(alpha, beta, L, M) << "\n";
  }
  myfile2.close();


  return 0;
}
