#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <sstream>

#include "models.hh"
#include "montecarlo.hh"

int main( int argc, char *argv[] )
{
  if(argc < 2)
  {
    std::cerr << "Error: Call " << argv[0] << " Dimension, Model" << std::endl;
    return 1;
  }

  const int N = atoi( argv[1] ); // Number of dimensions
  const int P = atoi( argv[2] ); // Which model to choose

  ModelInterface* model;
  std::string modelName;

  if(P == 1)
  {
    model = new Gaussian;
    modelName = "Gaussian";
  }
  else if(P == 2)
  {
    model = new Continuous;
    modelName = "Continuous";
  }
  else if(P == 3)
  {
    model = new Discontinuous;
    modelName = "Discontinuous";
  }
  else if(P == 4)
  {
    model = new Simplex;
    modelName = "Simplex";
  }
  else
  {
    std::cerr << "Error: choose either model 0, 1, 2, 3 or 4." << std::endl;
    return 1;
  }

  //Creates file comparing sample size to error
  std::ofstream myfile;
  std::string filename;
  std::stringstream convertN;
  convertN << N;
  filename = modelName + "_" + convertN.str() + ".dat";
  myfile.open(filename.c_str());

  for(int i = 0; i < 15; ++i)
  {
    int M = std::pow(2, i);
    myfile << M << "\t" << RelativeError(M, N, model) << std::endl;
  }

  myfile.close();

  delete model;

  return 0;
}
